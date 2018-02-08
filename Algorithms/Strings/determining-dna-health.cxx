#include <cmath>
#include <cstdio>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

template < class T, size_t N = 1024, size_t Tsize = sizeof(T) > struct pool {
    vector< void* > memory; void *currentPage; T *current, *currentEnd;
    pool () : memory(0), currentPage(0), current(0), currentEnd(0) { next_page(); }
    ~pool () { for ( auto t : memory ) ::operator delete (t); }
    void next_page () {
        memory.push_back( currentPage = ::operator new ( Tsize * N ) );
        currentEnd = ( current = static_cast<T*>( currentPage ) ) + N;
    }
    T *next_element () { if ( current == currentEnd ) next_page(); return current++; }
    void *allocate () { return static_cast<void*>( next_element() ); }
};

struct trie_t {
    struct node_t {
        array< node_t *, 26 > g;    // goto function
        node_t *f;                  // fail function
        vector<int> out;            // output function (indices of pattern that ends here)
                                    // then follow fail chain to find other patterns that are suffixes of this one
        node_t () : f{nullptr}, out{} { g.fill(nullptr); }
    };
    pool<node_t,1024> nodes;
    inline node_t *new_child () { return new ( nodes.allocate() ) node_t { }; }
    node_t *root;
    trie_t () : root( new_child() ) { }
    inline node_t *find_or_create_child (node_t *node, char a) {
        node_t * &child = node->g[a];
        if ( !child ) child = new_child ();
        return child;
    }
    inline void insert (string::iterator from, string::iterator to, int P) {
        auto q = root;
        while (from != to)
            q = find_or_create_child(q, *from++ - 'a');
        q->out.push_back(P);
    }
    inline void insert (string &gene, int P) { insert( begin(gene), end(gene), P ); }
    inline void build (vector<string> &genes);
    inline void out (vector<int> &weights, int start, int end_, int64_t &weight, vector<int> &indices) {
        for ( auto i : indices )
            if ( i >= start && i <= end_ )
                weight += weights[i];
    }
    inline void out (vector<int> &weights, int start, int end_, int64_t &weight, node_t *u) {
        do
            out (weights, start, end_, weight, u->out);
        while ( ( u = u->f ) && u != root );
    }
    static inline node_t *next (node_t *q, char a) {
        node_t *g;
        while ( !( g = q->g[a] ) )
            q = q->f;
        return g;
    }
    inline int64_t match (string::iterator from, string::iterator to, vector<int> &weights, int start, int end_);
    inline int64_t match (string &d, vector<int> &weights, int start, int end_);
};

inline void trie_t::build (vector<string> &genes) {
    for ( int P = 0, N = genes.size(); P < N; ++P )
        insert ( genes[P], P );
    queue<node_t*> Q;
    auto dequeue = [] (queue<node_t*> &Q) -> node_t* { node_t *q = Q.front(); Q.pop(); return q; };
    auto enqueue = [] (node_t *u, queue<node_t*> &Q) -> void { Q.push(u); };
    root->f = root;
    for ( auto &q : root->g ) {
        if (q) {
            q->f = root;
            enqueue(q, Q);
        }
        else
            q = root;
    }
    while (Q.size()) {
        node_t *r = dequeue(Q);
        for ( char a = 'a'-'a'; a <= 'z'-'a'; ++a ) {
            auto u = r->g[a];
            if (!u)
                continue;
            enqueue(u, Q);
            auto v = r; node_t *g;
            do v = v->f; while ( !( g = v->g[a] ) );
            u->f = g;
            // possibly generate union of out function
        }
    }
}

inline int64_t trie_t::match (string::iterator from, string::iterator to, vector<int> &weights, int start, int end_) {
    int64_t weight = 0;
    for ( node_t *q = root, *g; from != to; ++from ) {
        q = next( q, *from - 'a' );
        out( weights, start, end_, weight, q );
    }
    return weight;
}

int64_t trie_t::match (string &d, vector<int> &weights, int start, int end_) {
    return match( begin(d), end(d), weights, start, end_ );
}

int64_t healthiness (trie_t &trie, vector<int> &weights, int start, int end_, string &d) {
    return trie.match (d, weights, start, end_);
}

int main() {
    int n; cin >> n;
    vector<string> genes (n); for ( string &gi : genes ) cin >> gi;
    vector<int> health (n); for ( int &hi : health ) cin >> hi;
    trie_t trie; trie.build (genes);
    uint64_t maxHealth = 0, minHealth = ~uint64_t(0);
    int s; cin >> s; if (s) while ( --s >= 0 ) {
        int ghStart, ghEnd; string d; cin >> ghStart >> ghEnd >> d;
        uint64_t totalHealth = trie.match (d, health, ghStart, ghEnd);
        if ( totalHealth > maxHealth ) maxHealth = totalHealth;
        if ( totalHealth < minHealth ) minHealth = totalHealth;
    } else
        minHealth = 0;
    cout << minHealth << ' ' << maxHealth << endl;
    return 0;
}

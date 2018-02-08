import java.io.*;
import java.util.*;
class Node{
    Node left,right;
    int data;
    Node(int data){
        this.data=data;
        left=right=null;
    }
}
class Solution{
    
	static void levelOrder(Node root){
        if ( root == null )
            return;
        Deque<Node> q = new ArrayDeque<Node>();
        q.add(root);
        while( ! q.isEmpty() ) {
            root = q.remove();
            if ( root.left != null ) q.add( root.left );
            if ( root.right != null ) q.add ( root.right );
            System.out.print( root.data + " " );
        }
    }
	public static Node insert(Node root,int data){
        if(root==null){
            return new Node(data);
        }
        else{
            Node cur;
            if(data<=root.data){
                cur=insert(root.left,data);
                root.left=cur;
            }
            else{
                cur=insert(root.right,data);
                root.right=cur;
            }
            return root;
        }
    }
    public static void main(String args[]){
            Scanner sc=new Scanner(System.in);
            int T=sc.nextInt();
            Node root=null;
            while(T-->0){
                int data=sc.nextInt();
                root=insert(root,data);
            }
            levelOrder(root);
        }	
}

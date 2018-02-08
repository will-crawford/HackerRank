using namespace std;
#include <iostream>


class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        // Add some more code to run some checks on initialAge
        if ( initialAge < 0 ) {
            cout << "Age is not valid, setting age to 0." << endl;
            initialAge = 0;
        }
        age = initialAge;
    }

    void Person::amIOld(){
        // Do some computations in here and print out the correct statement to the console 
        cout << "You are " << ( age < 13 ? "young" : age < 18 ? "a teenager" : "old" ) << ".\n";
    }

    void Person::yearPasses(){
        // Increment the age of the person in here
        ++age;
    }
};

int main(){
    int t;
	int age;
    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses(); 
        }
        p.amIOld();
      
		cout << '\n';
    }

    return 0;
}

import java.util.*;

class Person {
	protected String firstName;
	protected String lastName;
	protected int idNumber;
	
	// Constructor
	Person(String firstName, String lastName, int identification){
		this.firstName = firstName;
		this.lastName = lastName;
		this.idNumber = identification;
	}
	
	// Print person data
	public void printPerson(){
		 System.out.println(
				"Name: " + lastName + ", " + firstName 
			+ 	"\nID: " + idNumber); 
	}
	 
}
class Student extends Person{
	private int[] testScores;
    Student ( String firstName, String lastName, int id, int[] scores ) {
        super ( firstName, lastName, id );
        this.testScores = scores;
    }
    char calculate () {
        int total = 0;
        for ( int i : testScores ) total += i;
        int average = total / testScores.length;
        return
            average >= 90 ? 'O' :
            average >= 80 ? 'E' :
            average >= 70 ? 'A' :
            average >= 55 ? 'P' :
            average >= 40 ? 'D' :
                            'T'
        ;
    }
}
class Solution {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String firstName = scan.next();
		String lastName = scan.next();
		int id = scan.nextInt();
		int numScores = scan.nextInt();
		int[] testScores = new int[numScores];
		for(int i = 0; i < numScores; i++){
			testScores[i] = scan.nextInt();
		}
		scan.close();
		
		Student s = new Student(firstName, lastName, id, testScores);
		s.printPerson();
		System.out.println("Grade: " + s.calculate());
	}
}

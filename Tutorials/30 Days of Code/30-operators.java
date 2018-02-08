public class Arithmetic {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double mealCost = scan.nextDouble(); // original meal price
        int tipPercent = scan.nextInt(); // tip percentage
        int taxPercent = scan.nextInt(); // tax percentage
        scan.close();
      
        // Write your calculation code here.
        double numberToRoundHere = mealCost * ( 100.0 + tipPercent + taxPercent ) / 100.0;
      
        // cast the result of the rounding operation to an int and save it as totalCost 
        int totalCost = (int) Math.round(numberToRoundHere);
      
        // Print your result
        System.out.printf ("The total meal cost is %d dollars.%n", totalCost);
    }
}

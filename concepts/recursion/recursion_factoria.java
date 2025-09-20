public class recursion_factoria {
    public static void main(String[] args) {
        /*
        Another example of recursion - A factorial is the product of all positive 
        integers less than or equal to a given non-negative integer.
        For more info, see README.
         */
        
        System.out.println(factorial(7));
    }

    private static int factorial(int num) {
        // Factorial function with recursion

        if (num < 1) return 1; // Base Case
        return num * factorial(num-1); // Recusrive Case
    }
}

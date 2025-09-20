public class recursion {
    public static void main(String[] args) {
        /*
        Recursion - when something calls itself. It divides a problem of the same 
        type as the original and is commonly used with sorting algorithms and navigating tress.
         */

        walk(5);
        walk2(5);
    }

    private static void walk2(int steps) {
        // Example of a recursion function
        
        if (steps < 1) return; // Base Case
        System.out.println("You took a step!");
        walk(steps - 1); // Recursive
    }

    private static void walk(int steps) {
        // Example of a non-recursion function

        for (int i = 0; i < steps; i++) {
            System.out.println("You took a step!");
        }
    }
}

public class recursion {
    public static void main(String[] args) {
        /*
        Recursion - when something calls itself. It divides a problem of the same 
        type as the original and is commonly used with sorting algorithms and navigating tress.
        Can be a subsitute for iteration - however, it should not be used for simple 
        programs like this becuase it can be slower and take more memory; this is just an example/
         */

        walkIteration(5);
        walkRecursion(5);
    }

    private static void walkRecursion(int steps) {
        // Example of a recursion function
        
        if (steps < 1) return; // Base Case
        System.out.println("You took a step!");
        walkRecursion(steps - 1); // Recursive
    }

    private static void walkIteration(int steps) {
        // Example of a non-recursion function

        for (int i = 0; i < steps; i++) {
            System.out.println("You took a step!");
        }
    }
}
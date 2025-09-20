import java.util.Arrays;

public class binary_search {
    public static void main(String[] args) {
        /*
        Binary Search - Half of the array is eliminated during every search; If we find 
        the value is smaller we find the middle of the smaller section and vise versa.

        Runtime: O(log n)
         */


        // Input specification, can be any array
         int[] array = new int[100]; 
         int target = 42;

         for (int i = 0; i < 100; i++) {
            array[i] = i;
         }

         // This is the built in binary function that Java uses. I will also be showing a function that we can create ourselves.
         int index = Arrays.binarySearch(array, target); 

         if (index != -1) System.out.println("Index found at " + index);
         else System.out.println("Index not found");

         int index2 = binarySearch(array, target); // Creating a function for the binary search

         if (index2 != -1) System.out.println("Index found at " + index2);
         else System.out.println("Index not found");

    }

    private static int binarySearch(int[] array, int target) {
        // Creates a function that has the same functions as the built in function Arrays.binarySearch.
        
        Arrays.sort(array); // Sorting the array
        int low = array[0];
        int high = array.length-1;

        while (low <= high) {
            int middle = low + (high-low) / 2;
            int value = array[middle];
            
            if (value < target) low = middle + 1;
            else if (value > target) high = middle - 1;
            else return middle; // Found target
        }
        return -1; // Target not found
    }
}
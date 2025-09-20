public class bubble_sort {
    public static void main(String[] args) {
        /*
        Bubble Sort - Pairs of adjacent elements are compared and they are swapped if they aren't in order.
        
        Runtime Complexity: O(n^2)
        Space: O(1)
         */

         // Input specification, this can be any array
        int[] array = {9, 1, 8, 2, 7, 3, 6, 4, 5};

        bubbleSort(array);

        // Print out the results
        for (int i : array) {
            System.out.print(i + " ");
        }
    }

    private static void bubbleSort(int[] array) {
        // Bubble sort function
        
        for (int i = 0; i < array.length-1; i++) {
            for (int j = 0; j < array.length-1; j++) {
                if (array[j] > array[j+1]) {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }
}
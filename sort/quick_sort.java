public class quick_sort {
    public static void main(String[] args) {
        /*
        Quick Sort: A recursive algorithm that has a pivot and sorts the 
        left and right of that pivot - the left is smaller than that pivot and the right is smaller. 
        For more info, see README.
        
        Runtime Complexity: O(n log n); worst case O(n^2) if already sorted
        Space Complexity: O(log n)
         */

        // Input specification, can be any array
        int[] array = {8, 2, 5, 3, 9, 4, 7, 6, 1};

        quickSort(array, 0, array.length-1);

        for (int i : array) {
            System.out.print(i + " ");
        }
    }

    private static void quickSort(int[] array, int start, int end) {
        // Quicksort recursive function

        if (end<=start) return; // Base Case

        int pivot = partition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }

    private static int partition(int[] array, int start, int end) {
        // Helper function

        int pivot = array[end];
        int i = start -1;
        
        for (int j = start; j <= end - 1; j++) {
            if (array[j] < pivot) {
                i++;

                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        i++;

        int temp = array[i];
        array[i] = array[end];
        array[end] = temp;

        return i;
    }
}

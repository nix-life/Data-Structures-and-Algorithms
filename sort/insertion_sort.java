public class insertion_sort {
    public static void main(String[] args) {
        /*
        Insertion sort - Compare elements to the left and shift elements to the right if the temporary value is smaller
        For more info, see README.

        Runtime complexity: O(n^2) with a best case of O(n)
        Space: O(1)
         */

        // Input specification, can be any array
        int[] array = {9, 1, 8, 2, 7, 3, 6, 5, 4};

        insertionSort(array);

        // Print out the results
        for (int i : array) {
            System.out.print(i + " ");
        }



    }

    private static void insertionSort(int[] array) {
        // Insertion Sort Function

        for (int i = 1; i < array.length; i++) {
            int temp = array[i];
            int j = i - 1;

            while (j >= 0 && array[j] > temp) {
                array[j + 1] = array[j];
                j--;
            }
            array[j+1] = temp;
        }
    }
}

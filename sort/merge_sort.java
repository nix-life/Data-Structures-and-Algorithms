public class merge_sort {
    public static void main(String[] args) {
        /*
        Merge sort - Merge sort uses recursion to divide an array into subarrays and sorts them based on the smallest subarrays possible

        Runtime Complexity - O(n log n)
        Space - O(n)
         */

        // Input specification, this can be any array
        int[] array = {8, 2, 5, 3, 4, 7, 6, 1};

        mergeSort(array);

        for (int i : array) {
            System.out.print(i + " ");
        }
        
    }

    private static void mergeSort(int[] array) {
        // Recursive Merge Sort function
        
        int length = array.length;
        if (length <= 1) return; // Base case
        
        int middle = length / 2;
        int[] leftArray = new int[middle];
        int[] rightArray = new int[length - middle];

        int i = 0; // Left Array
        int j = 0; // RIght Array

        for (; i < length; i++) {
            if (i < middle) {
                leftArray[i] = array[i];
            } else {
                rightArray[i] = array[i];
            }
         }

         mergeSort(leftArray);
         mergeSort(rightArray);
         merge(leftArray, rightArray, array);
    }

    private static void merge(int[] leftArray, int[] rightArray, int[] array) {
        int leftSize = array.length / 2;
        int rightSize = array.length - leftSize;
        int i = 0, l = 0, r = 0; // Indices we are using

        // Check the conditions for merging
        while (l < leftSize && r < rightSize) {
            if (leftArray[l] < rightArray[r]) {
                array[i] = leftArray[l];
                i++;
                l++;
            } else {
                array[i] = rightArray[r];
                i++;
                r++;
            }
        }
        
        // Take in final value if there is a non-paired index
        while (l < leftSize) {
            array[i] = leftArray[l];
            i++;
            l++; 
        }

        while (r < rightSize) {
            array[i] = rightArray[r];
            i++;
            r++;
        }
    }
}

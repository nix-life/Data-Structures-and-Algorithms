public class selection_sort {
    public static void main(String[] args) {
        /*
        Selection sort - seach through an array and keep track of the minimum 
        value during each iteration and move the smallest number to the beginning.
        For more info, see README.

        Runtime complexity = O(n^2)
        Space: O(1)
         */

        //Input specification, can be any array
         int[] array = {8, 7, 9, 2, 3, 1, 5, 4, 6};

         selectionSort(array);

        // Print out the results
         for (int i : array) {
            System.out.print(i + " ");
         }
    }

    private static void selectionSort(int[] array) {
        // Selection Sort Function
		
		for (int i = 0; i < array.length - 1; i++) {
			int min = i;
			for (int j = i + 1; j < array.length; j++) {
				if(array[min] > array[j]) {
					min = j;
				}
			}
			
			int temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}

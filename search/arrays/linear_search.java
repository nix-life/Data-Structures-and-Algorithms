public class linear_search {
    public static void main(String[] args) {

        /*
        Linear search = Iterate through a collection one at a time
        For more info, see README.
        
        Runtine Complexity: O(n)
        */ 

        // Input specification, can be any array
        int[] array = {9, 3, 5, 7, 8, 0, 6, 1, 10204, 42, 532425, 674, 753};

        int index = linearSearch(array, 1);

        if (index != -1) System.out.println("Element found at index " + index);
        else System.out.println("Element not found");
    }  

    private static int linearSearch(int[] array, int value) {
        // Loop through all values and find the value that is wanted
        
        for (int i = 0; i < array.length; i++) {
            if (array[i]==value) return i;
        }
        return -1;
    }
}
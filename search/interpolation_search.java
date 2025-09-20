public class interpolation_search {
    public static void main(String[] args) {
        /*
        Interpolation Search - similar to binary, but instead of always using
        the middle value it "guesses" a value in a range based on calculations. 
        If the probe is incorrect the search area is narrowed. 
        The interpolation search is the best with sorted arrays but it does not have to be.

        Runtime:
        - Worst Case: O(n)
        - Best Case: O(log(log n))
         */

        // Input Specification, this can be any array (this is an example of a slightly complicated but still easy array value)
        int[] array = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

        int index = interpolationSearch(array, 256);

        if (index != -1) System.out.println("Index at: " + index);
        else System.out.println("Value not found");
    }

    private static int interpolationSearch(int[] array, int value) {

        int low = 0; // This can be different for negative arrays but this is not considered right now
        int high = array.length - 1;

        while (value >= array[low] && value <= array[high] && low <= high) {
            int probe = low + (high - low) * (value - array[low]) / (array[high] - array[low]); // Formula

            if (array[probe]==value) return probe;
            else if (array[probe] < value) low = probe + 1;
            else high = probe - 1;
        }

        return -1;
    }
}
import java.util.*;

public class hash_table {
    public static void main(String[] args) {
        /*
        Hashtable - a table that connects two values to a certain index. 
        If there are overlappping indexes there is a linkedlist created. 
        Below is a simple example usage of a hash table.

        Runtime Complexity: Best Case O(1); Worst case O(n)

        Fore more info, see README
         */
        
        Hashtable<Integer, String> table = new Hashtable<>(10);
        
        // Add values to hash table
        table.put(100, "Spongebob");
        table.put(123, "Patrick");
        table.put(321, "Sandy");
        table.put(555, "Squidward");
        table.put(777, "Gary");

        // Remove value of hash table; commented for example
        // table.remove(777);

        /* --------------------------------------------------------------------------------------------------------------------------------------------- */

        // Same hash table but instead of an integer value it is a string
        for (Integer key : table.keySet()) {
            System.out.println(key.hashCode() % 10 + "\t" + key + "\t" + table.get(key));
        }

        Hashtable<String, String> table2 = new Hashtable<>(10);
        
        // Add values to hash table
        table2.put("100", "Spongebob");
        table2.put("123", "Patrick");
        table2.put("321", "Sandy");
        table2.put("555", "Squidward");
        table2.put("777", "Gary");

        // To access a value in a hash
        for (String key : table2.keySet()) {
            System.out.println(key.hashCode() % 10 + "\t" + key + "\t" + table2.get(key)); 
        }
    }
}
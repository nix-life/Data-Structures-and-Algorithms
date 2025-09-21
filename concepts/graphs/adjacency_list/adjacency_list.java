public class adjacency_list {
    public static void main(String[] args) {
        /*
        Adjacency list - An array or arraylist of linkedlists. 
        Each linkedlist has a unique node at the head and all adjacent nodes are added to the linkedlist.

        Runtime complexity to check an edge: O(V)
        Space Complexity: O(V + E)
         */

        Graph graph = new Graph(5);

        graph.addNode(new Node('A'));
        graph.addNode(new Node('B'));
        graph.addNode(new Node('C'));
        graph.addNode(new Node('D'));
        graph.addNode(new Node('E'));

        graph.addEdge(0, 1);
		graph.addEdge(1, 2);
        graph.addEdge(1, 4); 
		graph.addEdge(2, 3);
		graph.addEdge(2, 4);
		graph.addEdge(4, 0);
		graph.addEdge(4, 2);

        graph.print();
    }
}
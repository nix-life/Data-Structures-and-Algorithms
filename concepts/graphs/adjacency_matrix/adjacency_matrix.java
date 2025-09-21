public class adjacency_matrix {
    public static void main(String[] args) {
        /*
        Adjacency matrix - a 2D array of 1s and 0s representing the edges of a graph. The rows and columns are all nodes and if the value in the matrix is one the nodes are connected. It should be noted that it does not have to be 0s and 1s, it can be true and false or any other number.

        Runtime complexity to check an edge: O(1)
        Space Complexity: O(V^2)
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
		
		System.out.println(graph.checkEdge(0, 1));
    }
}

import javafx.scene.Node;

public class bFS_adjacency_matrix {
    public static void main(String[] args) {
        /*
        Breadth First Search (BFS) - a search algorithm for traversing a tree or graph data structure.

        This is done one "level at a time", not one "branch" at a time.
         */

        bFS_graph graph = new bFS_graph(5);
		
		graph.addNode(new bFS_node('A'));
		graph.addNode(new bFS_node('B'));
		graph.addNode(new bFS_node('C'));
		graph.addNode(new bFS_node('D'));
		graph.addNode(new bFS_node('E'));
		
		graph.addEdge(0, 1);
		graph.addEdge(1, 2);
        graph.addEdge(1, 4); 
		graph.addEdge(2, 3);
		graph.addEdge(2, 4);
		graph.addEdge(4, 0);
		graph.addEdge(4, 2);
		
		graph.print();
		
		graph.breadthFirstSearch(0);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// - Q: Did you stole this code from somewhere?
// - A: OFC I did

/*
 * Заданы две системы двусторонних дорог с одним и тем же множеством городов (железные и шоссейные дороги).
 * Найти минимальный по длине путь из города А в город В (который может проходить как по железным, так и по шоссейным дорогам),
 * и места пересадок с одного вида транспорта на другой на этом пути.
 * А и В вводятся с клавиатуры.
 */

// Number of vertices in the graph
#define V 8

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[]) {
// Initialize min value
	int min = INT_MAX, min_index = -10;

	for (int v = 0; v < V; v++)
		if (!sptSet[v] && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[], int n) {
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("0 to %d in %d\n", i, dist[i]);
}


// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src) {
	int dist[V];     // The output array. dist[i] will hold the shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
			    && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist, V);
}

// driver program to test above function
int main() {
/* Let us create the example graph discussed above */
	int graph[V][V] = {{0, 2, 3, 4, 0, 0, 0, 0},
	                   {2, 0, 0, 0, 2, 0, 0, 0},
	                   {3, 0, 0, 2, 0, 1, 0, 0},
	                   {4, 0, 2, 0, 3, 0, 0, 0},
	                   {0, 2, 0, 3, 0, 3, 0, 6},
	                   {0, 0, 1, 0, 3, 0, 3, 2},
	                   {0, 0, 0, 0, 0, 3, 0, 6},
	                   {0, 0, 0, 0, 6, 2, 6, 0}
	};

	dijkstra(graph, 0);

	return 0;
}

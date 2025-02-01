#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 1000

// Structure to represent a graph
typedef struct {
    int V; // Number of vertices
    int **adjMatrix; // Adjacency matrix to store the graph
} Graph;

// Function to create the graph (adjacency matrix representation)
Graph* createGraph(int V) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
    }
    return graph;
}

// Function to take the adjacency matrix as input from the user
void inputGraph(Graph *graph) {
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            scanf("%d", &graph->adjMatrix[i][j]);
        }
    }
}

// Function to color the graph using the greedy method (no parallelization)
void greedyColoring(Graph *graph) {
    int *color = (int*)malloc(graph->V * sizeof(int));

    // Initialize colors for all vertices
    for (int i = 0; i < graph->V; i++) {
        color[i] = -1; // No color assigned initially
    }

    // Assign the first color to the first vertex
    color[0] = 0;

    // Perform coloring sequentially (no OpenMP)
    for (int u = 1; u < graph->V; u++) {
        int *usedColors = (int*)malloc(MAX_COLORS * sizeof(int));
        for (int i = 0; i < MAX_COLORS; i++) {
            usedColors[i] = 0; // Initialize used colors for neighbors
        }

        // Mark the colors of all adjacent vertices
        for (int v = 0; v < graph->V; v++) {
            if (graph->adjMatrix[u][v] == 1 && color[v] != -1) {
                usedColors[color[v]] = 1;
            }
        }

        // Find the first available color that is not used by any adjacent vertex
        int c;
        for (c = 0; c < MAX_COLORS; c++) {
            if (usedColors[c] == 0) {
                break;
            }
        }

        // Assign the color to the current vertex
        color[u] = c;
        free(usedColors); // Free the temporary memory for used colors
    }

    // Print the result
    printf("Vertex colors:\n");
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }

    free(color);
}

// Main function
int main() {
    // Number of vertices
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Create the graph
    Graph *graph = createGraph(V);

    // Take adjacency matrix input from the user
    inputGraph(graph);

    // Color the graph using greedy algorithm
    greedyColoring(graph);

    // Free allocated memory
    for (int i = 0; i < V; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}

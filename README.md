# Graph-coloring
# Overview
This assignment implements a Greedy Graph Coloring algorithm in C. The program takes an adjacency matrix as input and assigns a color to each vertex such that no two adjacent vertices share the same color. The coloring is done sequentially, without parallelization (no OpenMP support in Replit). The program is useful for understanding basic graph coloring concepts and solving graph coloring problems.

# Features
Takes the number of vertices and the adjacency matrix as input from the user.
Colors the graph using the greedy algorithm.
Outputs the assigned colors for each vertex.
No parallelization (sequential implementation for compatibility with Replit).
# Requirements
C Compiler (works with GCC or any standard C compiler).
No external libraries are required for this implementation.
The program does not require OpenMP support or multi-threading.
# Usage Instructions
1. Input
Number of vertices: The user is asked to input the number of vertices in the graph.
Adjacency matrix: After inputting the number of vertices, the user is prompted to enter the adjacency matrix. The matrix represents the edges in the graph where a value of 1 indicates an edge and 0 indicates no edge between vertices.
2. Output
The program will output the color assigned to each vertex after applying the greedy coloring algorithm. The first vertex starts with color 0, and subsequent vertices are assigned the smallest available color not used by their adjacent vertices.

3. Example
Sample Input:
yaml
Copy
Edit
Enter the number of vertices: 5
Enter the adjacency matrix:
0 1 1 0 0
1 0 1 1 0
1 1 0 1 1
0 1 1 0 1
0 0 1 1 0
Sample Output:
rust
Copy
Edit
Vertex colors:
Vertex 0 -> Color 0
Vertex 1 -> Color 1
Vertex 2 -> Color 2
Vertex 3 -> Color 0
Vertex 4 -> Color 1
4. How to Run
Create a C Project in your desired C environment (e.g., Replit).
Paste the provided code into the main file (e.g., main.c).
Run the program, and when prompted, enter the number of vertices and the adjacency matrix.
The program will then print the assigned color for each vertex.
5. Example Execution on Replit:
Open your C project in Replit.
Copy the provided code and paste it into the main file.
Run the program.
Enter input when prompted.
# Code Explanation
Graph Representation: The graph is represented using an adjacency matrix, where graph[i][j] = 1 means there is an edge between vertex i and vertex j, and graph[i][j] = 0 means there is no edge.

Greedy Coloring:

Initially, all vertices are uncolored.
The first vertex is assigned color 0.
For each subsequent vertex, the algorithm checks the colors of its neighbors and assigns the smallest color that is not already used by any adjacent vertex.
Sequential Coloring: The coloring process is done sequentially without OpenMP parallelization to ensure compatibility with environments like Replit.

Memory Management:

Dynamic memory allocation is used for the adjacency matrix and the color array.
Proper memory deallocation is performed to avoid memory leaks.
# Limitations
No OpenMP support: This version of the program does not use parallelization and runs sequentially, which may be slower for large graphs.
Greedy Algorithm: This is a greedy coloring algorithm that does not guarantee the minimum number of colors. It only ensures that adjacent vertices receive different colors.
# Future Improvements
Implement parallelization using OpenMP (for environments that support it).
Use heuristic-based algorithms for better graph coloring results in large graphs.
Add a feature to determine the chromatic number (the minimum number of colors required)

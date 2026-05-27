# Maze Solver

## Overview
A maze-solving and pathfinding project in C implementing classic Data Structures and Algorithms concepts.

## Algorithms Implemented
- Depth-First Search (DFS)
- Recursive DFS
- Breadth-First Search (BFS)
- Dijkstra’s Algorithm
- A* Search Algorithm
- Maze Generation

## Features
- Maze traversal and shortest path finding
- Custom stack, queue, and priority queue implementations
- Web-based visualization
- Modular project structure

## Project Structure
```text
MazeSolver/
├── A*.c / A*.h
├── Bfs.c / Bfs.h
├── Dfs.c / Dfs.h
├── Dfs_recursive.c / Dfs_recursive.h
├── Dijkstra.c / Dijkstra.h
├── CalcCost.c / CalcCost.h
├── ComplexMaze.c / ComplexMaze.h
├── mazeGenerator.c / mazeGenerator.h
├── priority_q.c / priority_q.h
├── queue.c / queue.h
├── stack.c / stack.h
├── main.c
├── index.html
├── script.js
├── style.css
└── README.md
```

## Compile & Run
```bash
gcc main.c Dfs.c Bfs.c Dijkstra.c A*.c queue.c stack.c priority_q.c -o maze_solver
./maze_solver
```

## Concepts Used
- Graph Traversal
- Pathfinding Algorithms
- Heuristics
- Data Structures

## Author
Maze-solving project focused on implementing core DSA concepts in C.

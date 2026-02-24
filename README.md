🧩 Maze Generator & Pathfinding Visualizer (C++ / SFML)

A visual maze generation and pathfinding project built using C++ and SFML.

This project demonstrates:

Recursive Backtracking (DFS-based) Maze Generation

Step-by-step Visualization of the Algorithm

Interactive Start & Finish Selection

(Upcoming) Dijkstra’s Shortest Path Algorithm

A demonstration video of the maze generation process is included in this repository.

🎥 Demo

📌 A video showcasing the maze generation process step-by-step is attached in this repository.



https://github.com/user-attachments/assets/6972e2f5-717e-453e-ae44-c7553d5d181e



📌 Project Overview

This project is divided into two main parts:

🟢 Part 1 — Maze Generation (Completed ✅)

The maze is generated using the Recursive Backtracking algorithm (Depth-First Search with a stack).

🔎 How It Works

Start from the first cell.

Mark the current cell as visited.

Randomly select one unvisited neighbour.

Remove the wall between current and neighbour.

Push the neighbour onto the stack.

Repeat until all cells are visited.

If a cell has no unvisited neighbours, the algorithm backtracks using the stack.

✨ Features

Real-time visualization of the generation process

Visited cells are colored (grey)

Walls are dynamically removed

Start and finish points can be selected with mouse clicks

Clean grid-based architecture

🧠 Core Concepts Used

Depth-First Search (DFS)

Stack-based backtracking

Grid indexing (2D → 1D mapping)

Object-oriented design

SFML rendering

🔵 Part 2 — Dijkstra’s Algorithm (In Progress 🚧)

The next phase of this project is implementing Dijkstra’s Shortest Path Algorithm to find the shortest path between the selected start and finish cells.

🎯 Planned Features:

Step-by-step visualization

Distance tracking for each cell

Priority-based exploration

Path reconstruction and highlighting

Final shortest path animation

This section is currently under development and will be added soon.

🏗 Project Structure
.
├── main.cpp
├── maze.hpp
├── stack.hpp
├── structs.hpp
├── macros.hpp
└── README.md
Main Components

Maze class → Handles grid logic, generation, drawing

Stack class → Used for DFS backtracking

Cell struct → Stores cell state (walls, visited, row, col)

SFML → Rendering and visualization

🛠 Technologies Used

C++

SFML (Simple and Fast Multimedia Library)

Object-Oriented Programming

🚀 How to Run

Install SFML

Clone the repository:

git clone github.com/noryzenn/procedural_map_generation

Build and run using your preferred C++ compiler with SFML linked.

📈 Future Improvements

Complete Dijkstra implementation

Animated shortest-path drawing


💡 Author Notes

This project was built to strengthen understanding of:

Graph traversal algorithms

Algorithm visualization

Clean class architecture

Real-time rendering loops

The maze generation phase is fully functional.
Dijkstra implementation is coming next.

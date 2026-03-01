# 🧩 Maze Generator & Pathfinding Visualizer (C++ / SFML)

A visual maze generation and pathfinding project built using C++ and SFML.

This project demonstrates algorithmic maze generation and shortest-path finding with real-time, step-by-step visualization. It allows users to watch the computer carve out a perfect maze, interactively select their start and finish points, and watch Dijkstra's algorithm hunt for the most efficient route.

## 🎥 Demos

**Part 1: Maze Generation** 📌 A video showcasing the Recursive Backtracking generation process step-by-step.

https://github.com/user-attachments/assets/61156c85-00ab-4ce3-bcb0-a7358b895ac1

**Part 2: Dijkstra's Pathfinding** 📌 A video showcasing the shortest path search and path reconstruction.

https://github.com/user-attachments/assets/96ea997c-0b7e-4e48-80bd-ef9a58bd4e76

---

## 🎮 Interactive Controls

Once the maze is fully generated, you can interact with the grid:

* **Left Click (1st time):** Sets the **Start** point (Red).
* **Left Click (2nd time):** Sets the **Finish** point (Green).
* **Press `S`:** Starts the Dijkstra Pathfinding visualization.
* **Press `ESC`:** Closes the window.

---

## 📌 Project Overview

### 🟢 Part 1 — Maze Generation (Completed ✅)

The maze is generated using the **Recursive Backtracking** algorithm (Depth-First Search with a stack). It creates a "perfect maze" (a maze with no loops and exactly one path between any two cells).

### 🔵 Part 2 — Dijkstra’s Algorithm (Completed ✅)

Finds the absolute shortest path between the user-selected start and finish cells using a **Priority Queue**. It accounts for generated walls and reconstructs the path once the finish is reached.

---

## 🏗 Project Structure

```text
.
├── main.cpp        # Entry point, event handling, and main loop
├── maze.hpp        # Maze class: grid logic, generation, pathfinding, drawing
├── stack.hpp       # Custom Stack implementation for DFS backtracking
├── structs.hpp     # Cell structure (walls, visited states, row/col mapping)
├── macros.hpp      # Constants (CELL_SIZE, ROWS, COLS, directions)
└── CMakeLists.txt

```

---

## 🛠 Technologies & Concepts Used

* **C++20** & **SFML** (Simple and Fast Multimedia Library)
* **Graph Traversal:** Depth-First Search (DFS) & Dijkstra's Algorithm
* **Data Structures:** Stacks, Vectors, and Priority Queues
* **Grid Mathematics:** 2D (row/col) to 1D array index mapping

---

## 🚀 How to Build & Run

### Prerequisites

* **CMake** (v3.15+)
* **C++20 Compiler** (MSVC, GCC, or Clang)
* **SFML 2.6.x**

### 🪟 Windows (Using vcpkg)

1. **Install SFML:**
```powershell
vcpkg install sfml:x64-windows

```


2. **Build the project:**
```powershell
# Replace C:/vcpkg with your actual path
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake -G "Visual Studio 18 2026"
cmake --build build --config Release

```



### 🐧 Linux (Ubuntu/Debian)

1. **Install SFML:**
```bash
sudo apt-get install libsfml-dev

```


2. **Build the project:**
```bash
cmake -S . -B build
cmake --build build

```



### 🍎 macOS

1. **Install SFML:**
```bash
brew install sfml

```


2. **Build the project:**
```bash
cmake -S . -B build
cmake --build build

```



---

## 💡 Author Notes

This project was built to strengthen my understanding of:

* Graph traversal algorithms and real-time visualization.
* Memory management and clean class architecture in C++.
* Handling real-time rendering loops and window events.

---

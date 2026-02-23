#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>
#include "structs.hpp"
#include "macros.hpp"
#include "stack.hpp"

class Maze {
private:
	std::vector<Cell> grid;
public:
	Maze() {
		grid.resize(MAX_SIZE);
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				int index = getIndex(i, j);
				grid[index].row = i;
				grid[index].col = j;
			}
		}
	}

	inline int getIndex(int row, int col) const { return row * COLS + col; }

	const Cell& getCell(int index) const { return grid[index]; }

	Cell& getCell(int index) { return grid[index]; }

	inline bool isValid(int row, int col) const { return row >= 0 && row < ROWS && col >= 0 && col < COLS; }

	inline std::vector<int> getUnvisitedNeighbours(int currentIndex) const {
		std::vector<int> neighbours;
		const Cell& current = getCell(currentIndex);
		int r = current.row;
		int c = current.col;

		// Bottom
		if (isValid(r + 1, c) && !getCell(getIndex(r + 1, c)).visited) {
			neighbours.push_back(getIndex(r + 1, c));
		}

		// Top
		if (isValid(r - 1, c) && !getCell(getIndex(r - 1, c)).visited) {
			neighbours.push_back(getIndex(r - 1, c));
		}

		// Left
		if (isValid(r, c - 1) && !getCell(getIndex(r, c - 1)).visited){
			neighbours.push_back(getIndex(r, c - 1));
		}

		// Right
		if (isValid(r, c + 1) && !getCell(getIndex(r, c + 1)).visited) {
			neighbours.push_back(getIndex(r, c + 1));
		}
		
		return neighbours;
	}

	inline void removeWalls(Cell& current, Cell& neighbour) {
		int dx = current.col - neighbour.col;
		int dy = current.row - neighbour.row;
		
		Wall direction;
		if (dx == 1) direction = LEFT;
		else if (dx == -1) direction = RIGHT;
		else if (dy == 1) direction = TOP;
		else if (dy == -1) direction = BOTTOM;

		current.walls[direction] = false;
		neighbour.walls[(direction + 2) % 4] = false;

		return;
	}

	inline void maze_generation() {
		srand(time(NULL));
		Stack<int> stack;
		int currentIndex = 0;
		stack.push(currentIndex);
		getCell(currentIndex).visited = true;
		while (!stack.isEmpty()) {
			currentIndex = stack.peek();
			std::vector<int> neighbours = getUnvisitedNeighbours(currentIndex);
			if (neighbours.size()) {
				int neighbourIndex = neighbours[rand() % neighbours.size()];
				removeWalls(getCell(currentIndex), getCell(neighbourIndex));
				getCell(neighbourIndex).visited = true;
				stack.push(neighbourIndex);
			}
			else {
				stack.pop();
			}
		}
	}
};


#endif
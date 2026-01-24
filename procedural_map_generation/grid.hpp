#ifndef GRID_HPP
#define GRID_HPP

#include "structs.hpp"
#include "macros.hpp"

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

	int getIndex(int row, int col);
};

int Maze::getIndex(int row, int col) {
	return row * COLS + col;
}

#endif
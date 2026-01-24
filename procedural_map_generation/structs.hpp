#ifndef STRUCTS_HPP
#define STRUCTS_HPP

// We need enum for numerating walls.

enum Wall {
	TOP,
	RIGHT,
	BOTTOM,
	LEFT
};

// This Cell struct will keep the information of the current state of each rectangle.

struct Cell {
	int row;
	int col;

	bool visited = false;
	bool walls[4] = { true, true, true, true };

	Cell() : row(0), col(0) {}
};


#endif
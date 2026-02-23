#ifndef MAZE_HPP
#define MAZE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "structs.hpp"
#include "macros.hpp"
#include "stack.hpp"


class Maze {
private:
	std::vector<Cell> grid;
	Stack<int> stack;
	int startIndex = -1;
	int finishIndex = -1;
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

	void setStart(int row, int col) { startIndex = getIndex(row, col); }
	void setFinish(int row, int col) { finishIndex = getIndex(row, col); }
	
	void drawStartFinish(sf::RenderWindow& window) {
		if (startIndex != -1) {
			sf::RectangleShape rect(sf::Vector2f(CELL_SIZE, CELL_SIZE));
			Cell& start = getCell(startIndex);
			rect.setPosition(start.col * CELL_SIZE, start.row * CELL_SIZE);
			rect.setFillColor(sf::Color::Red);
			window.draw(rect);
		}
		if (finishIndex != -1) {
			sf::RectangleShape rect(sf::Vector2f(CELL_SIZE, CELL_SIZE));
			Cell& finish = getCell(finishIndex);
			rect.setPosition(finish.col * CELL_SIZE, finish.row * CELL_SIZE);
			rect.setFillColor(sf::Color::Green);
			window.draw(rect);
		}
	}

	inline bool isValid(int row, int col) const { return row >= 0 && row < ROWS && col >= 0 && col < COLS; }

	inline void drawCell(const Cell& c, sf::RenderWindow& window) {
		int x = c.col * CELL_SIZE;
		int y = c.row * CELL_SIZE;

		if (c.visited) {
			sf::RectangleShape rect(sf::Vector2f(CELL_SIZE, CELL_SIZE));
			rect.setPosition(float(x), float(y));
			rect.setFillColor(sf::Color(100, 100, 100));
			window.draw(rect);
		}

		if (c.walls[TOP]) {
			sf::Vertex line[] = {
				sf::Vertex(sf::Vector2f(x,y), sf::Color::White),
				sf::Vertex(sf::Vector2f(x + CELL_SIZE, y), sf::Color::White)
			};

			window.draw(line, 2, sf::Lines);
		}

		if (c.walls[BOTTOM]) {
			sf::Vertex line[] = {
				sf::Vertex(sf::Vector2f(x, y + CELL_SIZE), sf::Color::White),
				sf::Vertex(sf::Vector2f(x + CELL_SIZE, y + CELL_SIZE), sf::Color::White)
			};

			window.draw(line, 2, sf::Lines);
		}

		if (c.walls[LEFT]) {
			sf::Vertex line[] = {
				sf::Vertex(sf::Vector2f(x,y), sf::Color::White),
				sf::Vertex(sf::Vector2f(x,y + CELL_SIZE), sf::Color::White)
			};

			window.draw(line, 2, sf::Lines);
		}

		if (c.walls[RIGHT]) {
			sf::Vertex line[] = {
				sf::Vertex(sf::Vector2f(x + CELL_SIZE,y), sf::Color::White),
				sf::Vertex(sf::Vector2f(x + CELL_SIZE, y + CELL_SIZE), sf::Color::White)
			};

			window.draw(line, 2, sf::Lines);
		}
	}

	inline void drawGrid(sf::RenderWindow& window) {
		for (int x = 0; x < COLS; x++) {
			for (int y = 0; y < ROWS; y++) {
				drawCell(getCell(getIndex(y,x)), window);
			}
		}
	}

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

	inline void maze_generation(sf::RenderWindow& window) {

		srand(time(NULL));
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

			window.clear(sf::Color::Black);
			drawGrid(window);
			window.display();
		}

		return;
	}
};


#endif
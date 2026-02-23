#include "funcs.hpp"

void Draw::draw_cell(const Cell& c, sf::RenderWindow& window) {
	int x = c.col * CELL_SIZE;
	int y = c.row * CELL_SIZE;

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

void Draw::draw_grid(const Maze& maze, sf::RenderWindow& window) {
	int index;
	for (int x = 0; x < COLS; x++) {
		for (int y = 0; y < ROWS; y++) {
			index = maze.getIndex(y,x);
			Draw::draw_cell(maze.getCell(index), window);
		}
	}
}
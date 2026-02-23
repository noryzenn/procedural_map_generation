#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <SFML/Graphics.hpp>
#include "macros.hpp"
#include "maze.hpp"
#include "structs.hpp"

class Draw {
public:
	void draw_cell(const Cell& c, sf::RenderWindow& window);
	void draw_grid(const Maze& maze, sf::RenderWindow& window);
};

#endif
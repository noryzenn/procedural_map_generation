#include <iostream>
#include <SFML/Graphics.hpp>
#include "funcs.hpp"
#include "stack.hpp"

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "Maze");
	Maze maze;
	Draw draw;
	bool isStartSelected = false;
	bool isFinishSelected = false;
	sf::Vector2i mousePos;
	sf::RectangleShape finish_rect(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	sf::RectangleShape start_rect(sf::Vector2f(CELL_SIZE, CELL_SIZE));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}

			if (isFinishSelected && !isStartSelected && event.type == sf::Event::MouseButtonPressed) {
				mousePos = sf::Vector2i(sf::Mouse::getPosition(window));
				int start_x = mousePos.x / CELL_SIZE;
				int start_y = mousePos.y / CELL_SIZE;
				if (start_x >= 0 && start_x < COLS && start_y >= 0 && start_y < ROWS) {
					start_rect.setPosition(start_x * CELL_SIZE, start_y * CELL_SIZE);
					isStartSelected = true;
				}
			}

			if (!isFinishSelected && !isStartSelected && event.type == sf::Event::MouseButtonPressed) {
				mousePos = sf::Vector2i(sf::Mouse::getPosition(window));
				int finish_x = mousePos.x / CELL_SIZE;
				int finish_y = mousePos.y / CELL_SIZE;
				if (finish_x >= 0 && finish_x < COLS && finish_y >= 0 && finish_y < ROWS) {
					finish_rect.setPosition(finish_x * CELL_SIZE, finish_y * CELL_SIZE);
					isFinishSelected = true;
				}
			}
		}

		window.clear(sf::Color::Black);
		
		if (isFinishSelected) {
			finish_rect.setFillColor(sf::Color::Green);
			window.draw(finish_rect);
		}

		if (isStartSelected) {
			start_rect.setFillColor(sf::Color::Red);
			window.draw(start_rect);
		}

		maze.maze_generation();
		draw.draw_grid(maze, window);
		
		window.display();
		sf::sleep(sf::milliseconds(20));
	}

	return 0;
}
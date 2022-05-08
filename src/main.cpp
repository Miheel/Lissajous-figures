#include <SFML/Graphics.hpp>
#include "borad.hpp"

const int WIN_X = 1000;
const int WIN_Y = 1020;

int main() {

	sf::RenderWindow win(sf::VideoMode(WIN_X, WIN_Y), "circles");
	win.setFramerateLimit(60);
	sf::Event event;

	Board board(WIN_X, WIN_Y);

	while (win.isOpen())
	{
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				win.close();
			}
		}
		board.update(win);
		win.clear();
		win.draw(board);
		win.display();
	}

	return 0;
}

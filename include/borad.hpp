#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include "tile.hpp"

class Board : public sf::Drawable
{
public:
	Board(const int win_x, const int win_y);
	~Board() = default;

	void init(const int win_x, const int win_y);

	void update(sf::RenderTarget & target);

private:
	std::vector<Tile> tileVec;
	std::vector<sf::Vertex> shape;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};

#endif // !BOARD_HPP

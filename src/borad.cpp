#include "borad.hpp"
#include <SFML/Graphics.hpp>

Board::Board(const int win_x, const int win_y)
{
	init(win_x, win_y);
}

void Board::init(const int win_x, const int win_y)
{

	std::vector<sf::Color> colorVec = {
		sf::Color(sf::Color::White),
		sf::Color(sf::Color::Red),
		sf::Color(255, 128, 0) ,
		sf::Color(sf::Color::Yellow),
		sf::Color(sf::Color::Green) ,
		sf::Color(sf::Color::Cyan) ,
		sf::Color(0, 128, 255) ,
		sf::Color(sf::Color::Blue) ,
		sf::Color(sf::Color::Magenta) ,
		sf::Color(128, 0, 255) ,
		sf::Color(128,0,128)
	};
	float topOffset = 20.f;
	float leftOffset = 5;
	size_t numberOfTiles = 11;
	double velocity = 0.01;
	auto tileSize = win_x / numberOfTiles;
	for (size_t i = 0; i < numberOfTiles; i++)
	{


		auto tile = Tile((float)tileSize);
		tile.setPosition(i*tile.getSize().x + leftOffset, topOffset);
		tile.setColor(colorVec[i]);
		tile.setDotVelocity(velocity += 0.01);
		this->tileVec.push_back(tile);
	}
	velocity = 0.02;
	for (size_t i = 1; i < numberOfTiles; i++)
	{
		auto sideTile = Tile((float)tileSize);
		sideTile.setPosition(leftOffset, i*sideTile.getSize().y + topOffset);
		sideTile.setColor(colorVec[i]);
		sideTile.setDotVelocity(velocity +=  0.01);
		this->tileVec.push_back(sideTile);

		for (size_t j = 1; j < numberOfTiles; j++)
		{
			int dotSize = 2;
			auto tile = Tile((float)tileSize);
			tile.setPosition(j*tile.getSize().x + leftOffset, i*sideTile.getSize().y + topOffset);
			tile.setSize(tileSize, tileSize, dotSize);
			this->tileVec.push_back(tile);
		}
	}
}

void Board::update(sf::RenderTarget & target)
{
	size_t rowSize = 11;
	for (size_t i = 0; i < tileVec.size(); i++)
	{
		if (i >= rowSize && (i % rowSize != 0))
		{
			auto x = i % rowSize;
			auto y = i / rowSize;

			tileVec[i].setDotPosition(tileVec[x].getDotPosiotion().x - (tileVec[x].getSize().x / 2) + 5, tileVec[y*rowSize].getDotPosiotion().y);

			const int vertexArrCap = 100000;
			if (shape.size() < vertexArrCap)
			{
				shape.push_back(sf::Vertex(sf::Vector2f(tileVec[x].getDotPosiotion().x, tileVec[y*rowSize].getDotPosiotion().y), tileVec[x].getColor() + tileVec[y*rowSize].getColor()));
			}
		}
		tileVec[i].update(target);
	}
}

void Board::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (size_t i = 0; i < tileVec.size(); i++)
	{
		target.draw(tileVec[i], states);
	}
	target.draw(&shape[0], shape.size(), sf::Points);

}

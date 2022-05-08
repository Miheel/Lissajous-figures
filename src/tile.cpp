#include "tile.hpp"

Tile::Tile(float size)
{
	setSize(size, size, 5);

	rect.setFillColor(sf::Color(sf::Color::Transparent));
	rect.setOutlineThickness(1);
	rect.setOutlineColor(sf::Color(sf::Color::White));

	circle.setFillColor(sf::Color(sf::Color::Transparent));

	dot.setFillColor(sf::Color(sf::Color::White));
}

void Tile::setPosition(float x, float y)
{
	rect.setPosition(x, y);

	circle.setOrigin(circle.getGlobalBounds().width / 2, circle.getGlobalBounds().height / 2);
	circle.setPosition(x + rect.getGlobalBounds().width / 2, y + rect.getGlobalBounds().height / 2);

	dot.setOrigin(dot.getGlobalBounds().width / 2, dot.getGlobalBounds().height / 2);
	dot.setPosition(circle.getPosition().x, circle.getPosition().y);
}

void Tile::setColor(const sf::Color & color)
{
	circle.setOutlineThickness(1);
	circle.setOutlineColor(color);
}

const sf::Color & Tile::getColor()
{
	return circle.getOutlineColor();
}

void Tile::setSize(float x, float y, float dotradius)
{
	rect.setSize(sf::Vector2f(x, y));
	circle.setRadius((float)(x - 10) / 2);
	dot.setRadius(dotradius);
	dot.setOscillationSize((float)(x - 10)/2);
}

sf::Vector2f Tile::getSize()
{
	return rect.getSize();
}

void Tile::setDotVelocity(double velocity)
{
	dot.setVelocity(velocity);
}

const sf::Vector2f& Tile::getDotPosiotion()
{
	return dot.getPosition();
}

void Tile::setDotPosition(float x, float y)
{
	dot.setPosition(x, y);
}

void Tile::update(sf::RenderTarget & target)
{
	dot.update(target);
}

void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(rect, states);
	target.draw(circle, states);
	target.draw(dot, states);
}

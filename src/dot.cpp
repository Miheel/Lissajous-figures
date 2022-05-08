#include "dot.hpp"
#include <iostream>
#include <cmath>

Dot::Dot() :circle()
{
}

void Dot::setPosition(float x, float y)
{
	pos.x = x;
	pos.y = y;
	circle.setPosition(x, y);
}

const sf::Vector2f& Dot::getPosition()
{
	return circle.getPosition();
}

const sf::Vector2f & Dot::getOrigPosition()
{
	return pos;
}

void Dot::setOrigin(float x, float y)
{
	circle.setOrigin(x, y);
}

sf::FloatRect Dot::getGlobalBounds()
{
	return circle.getGlobalBounds();
}

void Dot::setFillColor(const sf::Color & color)
{
	circle.setFillColor(color);
}

void Dot::setRadius(float radius)
{
	circle.setRadius(radius);
}

void Dot::setOscillationSize(double size)
{
	oscillationSize = size;
}

void Dot::setVelocity(double velocity)
{
	this->velocity = velocity;
}

void Dot::update(sf::RenderTarget & target)
{
	radians += velocity;
	circle.setPosition(pos.x + std::cos(radians)*oscillationSize, pos.y + std::sin(radians)*oscillationSize);
	//std::cout << std::cos(radians)*oscillationSize << "\n";
}

void Dot::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(circle, states);
}
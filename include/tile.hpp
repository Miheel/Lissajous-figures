#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include "dot.hpp"

class Tile : public sf::Drawable
{
public:
	Tile(float size);

	void setPosition(float x, float y);
	void setColor(const sf::Color& color);
	const sf::Color& getColor();
	void setSize(float x, float y, float dotradius);
	sf::Vector2f getSize();

	void setDotVelocity(double velocity);
	const sf::Vector2f& getDotPosiotion();
	void setDotPosition(float x, float y);

	void update(sf::RenderTarget & target);

private:

	sf::RectangleShape rect;
	sf::CircleShape circle;
	Dot dot;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

};
#endif // !TILE_HPP

#ifndef DOT_HPP
#define DOT_HPP

#include <SFML/Graphics.hpp>

class Dot : public sf::Drawable
{
public:
	Dot();
	~Dot() = default;

	void setPosition(float x, float y);
	const sf::Vector2f& getPosition();
	const sf::Vector2f& getOrigPosition();
	void setOrigin(float x, float y);
	sf::FloatRect getGlobalBounds();
	void setFillColor(const sf::Color &color);
	void setRadius(float radius);

	void setOscillationSize(double size);
	void setVelocity(double velocity);


	void update(sf::RenderTarget & target);

private:
	sf::CircleShape circle;
	sf::Vector2f pos;

	double oscillationSize;
	double radians = 0;
	double velocity = 0;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};

#endif // !DOT_HPP

#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

class Cell
{
public:
  explicit Cell(float size, sf::Color color = sf::Color::Black, float x = 0, float y = 0);
  explicit Cell(float size, sf::Color color, const sf::Vector2f& pos);

  const sf::RectangleShape& getRect() const;
  void draw(sf::RenderWindow& window) const;
  void setPos(float x, float y);
  void setPos(const sf::Vector2f& pos);
  void setColor(sf::Color color);
  void enableBorders(bool set);
  sf::Vector2f getPos() const;
  float getSize() const;
  sf::Color getColor() const;

private:
  float m_size{};
  sf::RectangleShape m_rect{};
};

#endif
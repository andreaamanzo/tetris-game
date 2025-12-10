#ifndef SHAPE_H
#define SHAPE_H

#include "Cell.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Shape
{
public:
  Shape(float cellSize, sf::Color color, const std::vector<sf::Vector2u>& absPos, float startX = 0, float startY = 0);

  void draw(sf::RenderWindow& window) const;
  void setPos(float x, float y);
  void setPos(const sf::Vector2f& pos);
  void setColor(sf::Color color);
  void enableBorders(bool set);
  sf::Vector2f getStartPos() const;
  sf::Vector2f getEndPos() const;
  const std::vector<Cell>& getCells() const;
  sf::Color getColor() const;

protected:
  sf::Vector2f m_start{};
  sf::Vector2f m_end{};
  float m_cellSize{};
  std::vector<Cell> m_cells{};
};

#endif



// luasnip
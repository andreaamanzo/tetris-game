#include "Cell.h"
#include <SFML/Graphics.hpp>

Cell::Cell(float size, sf::Color color, float x, float y)
  : m_size{ size }
  , m_rect{ sf::Vector2f{ size, size } }
{ 
  m_rect.setFillColor(color);
  m_rect.setOutlineColor(sf::Color::Black);
  enableBorders(true);
  m_rect.setPosition(x, y);
}

Cell::Cell(float size, sf::Color color, const sf::Vector2f& pos)
  : Cell{ size, color, pos.x, pos.y }
{ }

const sf::RectangleShape& Cell::getRect() const
{
  return m_rect;
}

void Cell::draw(sf::RenderWindow& window) const
{
  window.draw(m_rect);
}

void Cell::setPos(float x, float y)
{
  m_rect.setPosition(x, y);
}

void Cell::setPos(const sf::Vector2f& pos)
{
  m_rect.setPosition(pos);
}

void Cell::setColor(sf::Color color)
{
  m_rect.setFillColor(color);
}

void Cell::enableBorders(bool set)
{
  if (set)
    m_rect.setOutlineThickness(-1.f);
  else
    m_rect.setOutlineThickness(0);
}

sf::Vector2f Cell::getPos() const
{
  return m_rect.getPosition();
}

float Cell::getSize() const
{
  return m_size;
}

sf::Color Cell::getColor() const
{
  return m_rect.getFillColor();
}


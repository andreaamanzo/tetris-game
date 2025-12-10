#include "Shape.h"
#include "Cell.h"
#include <vector>
#include <cassert>
#include <SFML/Graphics.hpp>

Shape::Shape(float cellSize, sf::Color color, const std::vector<sf::Vector2u>& absPos, float startX, float startY)
  : m_start{ startX, startY }
  , m_cellSize{ cellSize }
{  
  assert(!absPos.empty() && "Shape::Shape() : can't create an empty shape");

  float maxX{ startX + cellSize };
  float maxY{ startY + cellSize };
  for (const auto& pos : absPos)
  {
    float nx{ (static_cast<float>(pos.x) * cellSize) + startX };
    float ny{ (static_cast<float>(pos.y) * cellSize) + startY };
    m_cells.push_back(Cell{ cellSize, color, sf::Vector2f{ nx, ny } });
    maxX = std::max(maxX, nx + cellSize);
    maxY = std::max(maxY, ny + cellSize);
  }

  m_end = sf::Vector2f{ maxX, maxY };
}

void Shape::setPos(float x, float y)
{
  float diffX{ x - m_start.x };
  float diffY{ y - m_start.y };
  m_start = { x, y };
  m_end.x += diffX;
  m_end.y += diffY;

  for (auto& cell : m_cells)
  {
    auto [prevX, prevY]{ cell.getPos() };
    cell.setPos(prevX + diffX, prevY + diffY);
  }
}

void Shape::setPos(const sf::Vector2f& pos)
{
  setPos(pos.x, pos.y);
}

void Shape::setColor(sf::Color color)
{
  for (auto& cell : m_cells)
    cell.setColor(color);
}

void Shape::enableBorders(bool set)
{
  for (auto& cell : m_cells) 
    cell.enableBorders(set);
}

void Shape::draw(sf::RenderWindow& window) const
{
  for (const auto& cell : m_cells)
    cell.draw(window);
}

sf::Vector2f Shape::getStartPos() const
{
  return m_start;
}

sf::Vector2f Shape::getEndPos() const
{
  return m_end;
}

const std::vector<Cell>& Shape::getCells() const
{
  return m_cells;
}

sf::Color Shape::getColor() const
{
  return m_cells[0].getColor();
}
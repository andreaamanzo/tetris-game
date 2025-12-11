#include "Board.h"
#include "Cell.h"
#include "utils.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cassert>
#include <memory>
#include <iostream>

Board::Board(int width, int heigth)
  : m_width{ width }
  , m_heigth{ heigth }
  , m_grid(toUZ(heigth), Rows(toUZ(width), nullptr))
{
  assert(width > 0 && heigth > 0);
}

int Board::getHeigth() const { return m_heigth; }
int Board::getWidth() const { return m_width; }

void Board::setCell(const Cell& cell, int x, int y)
{
  assert((x < m_width && x >= 0 && y < m_heigth && y >= 0) && "Invalid idxs in Board::setCell()");

  m_grid[toUZ(y)][toUZ(x)] = std::make_shared<Cell>(cell);
}

bool Board::isTaken(int x, int y) const
{
  assert((x < m_width && x >= 0 && y < m_heigth && y >= 0) && "Invalid idxs in Board::isTaken()");

  return m_grid[toUZ(y)][toUZ(x)].get() != nullptr;
}

void Board::draw(sf::RenderWindow& window) const
{
  for (const auto& row : m_grid)
    for (const auto& cell : row)
      if (cell) cell.get()->draw(window);
}

void Board::setRowColor(int y, sf::Color color)
{
  assert((y >= 0 && y < m_heigth) && "Invalid row idx in Board::setRowColor()");

  for (auto& cell : m_grid[toUZ(y)])
    cell.get()->setColor(color);
}

void Board::deleteRow(int y)
{
  assert((y >= 0 && y < m_heigth) && "Invalid row idx in Board::deleteRow()");

  for (auto& cell : m_grid[toUZ(y)])
    cell = nullptr;

  for (std::size_t i{ toUZ(y) }; i > 0 ; --i)
  {
    std::swap(m_grid[i], m_grid[i-1]);
    for (auto& cell : m_grid[i])
    {
      if (cell)
      {
        float nx{ cell.get()->getPos().x };
        float ny{ cell.get()->getPos().y + cell.get()->getSize() };
        cell.get()->setPos({ nx, ny });
      }
    }
  }
}

bool Board::checkValidPosition(const Shape& shape)
{
  for (const auto& cell : shape.getCells())
  {
    int posX{ static_cast<int>(cell.getPos().x / cell.getSize()) };
    int posY{ static_cast<int>(cell.getPos().y / cell.getSize()) };

    if (posX < 0 || posX >= m_width || posY >= m_heigth) 
      return false;
    if (posY < 0) 
      continue;
    if (this->isTaken(posX, posY))
      return false;
  }
  return true;
}

bool Board::isCompletedRow(int y) const
{
  assert((y >= 0 && y < m_heigth) && "Invalid row idx in Board::isCompletedRow()");

  for (auto& cell : m_grid[toUZ(y)])
    if (!cell) return false;

  return true;
}

void Board::clear()
{
  for (auto& row : m_grid)
    for (auto& cell : row)
      cell.reset();

}


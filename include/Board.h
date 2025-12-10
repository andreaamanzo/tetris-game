#ifndef BOARD_H
#define BOARD_H

#include "Settings.h"
#include "Cell.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Board
{
public:
  Board(int width, int heigth);
  void setCell(const Cell& cell, int x, int y);
  void deleteRow(int y);
  bool isTaken(int x, int y) const;
  bool checkValidPosition(const Shape& shape);
  bool isCompletedRow(int y) const;
  void setRowColor(int y, sf::Color color);
  void draw(sf::RenderWindow& window) const;
  int getHeigth() const;
  int getWidth() const;

private:
  using Rows = std::vector<std::shared_ptr<Cell>>;
  using BoardGrid = std::vector<Rows>;

  int m_width{};
  int m_heigth{};
  BoardGrid m_grid{};
};

#endif
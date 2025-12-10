#include "tetrominoes.h"
#include "Shape.h"
#include "Random.h"
#include "Settings.h"
#include "utils.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

Tetromino::Tetromino(float cellSize, sf::Color color, const TetrAbsPos& absPos, float x, float y, int rotationIdx)
  : Shape{ cellSize, color, absPos[toUZ(rotationIdx % 4)], x, y }
  , m_rotationIdx{ rotationIdx % 4 }
  , m_absPos{ absPos }
{ }

void Tetromino::stepDown()
{
  this->setPos(m_start.x, m_start.y + m_cellSize);
}

void Tetromino::stepUp()
{
  this->setPos(m_start.x, m_start.y - m_cellSize);
}

void Tetromino::stepRight()
{
  this->setPos(m_start.x + m_cellSize, m_start.y);
}

void Tetromino::stepLeft()
{
  this->setPos(m_start.x - m_cellSize, m_start.y);
}

void Tetromino::rotate()
{
  m_rotationIdx = (m_rotationIdx + 1) % 4;
  *this = Tetromino{ m_cellSize, this->getColor(), m_absPos, m_start.x, m_start.y, m_rotationIdx };
}

Tetromino getRandomTetromino(float cellSize)
{
  int n{ Random::get(1, Settings::n_tetrominoes) };
  
  switch (n)
  {
    case 1: 
      return Tetromino{ cellSize, I_Tetromino::s_color, I_Tetromino::s_absPos };
    case 2: 
      return Tetromino{ cellSize, J_Tetromino::s_color, J_Tetromino::s_absPos };
    case 3: 
      return Tetromino{ cellSize, L_Tetromino::s_color, L_Tetromino::s_absPos };
    case 4: 
      return Tetromino{ cellSize, O_Tetromino::s_color, O_Tetromino::s_absPos };
    case 5: 
      return Tetromino{ cellSize, S_Tetromino::s_color, S_Tetromino::s_absPos };
    case 6: 
      return Tetromino{ cellSize, T_Tetromino::s_color, T_Tetromino::s_absPos };
    case 7: 
      return Tetromino{ cellSize, Z_Tetromino::s_color, Z_Tetromino::s_absPos };
  
    default:
      throw std::runtime_error("Invalid tetromino in getRandomTetromino()");
  }
}

Tetromino getShadow(const Tetromino& src)
{
  Tetromino shadow{ src };
  shadow.enableBorders(false);
  shadow.setColor(sf::Color(60, 60, 60));

  return shadow;
}

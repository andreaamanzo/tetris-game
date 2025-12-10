#ifndef TETROMINOES_H
#define TETROMINOES_H

#include "Shape.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <array>

using TetrAbsPos = std::array<std::vector<sf::Vector2u>, 4>;

class Tetromino : public Shape
{
public:
  Tetromino(float cellSize, sf::Color color, const TetrAbsPos& absPos, float x = 0, float y = 0, int rotationIdx = 0);

  void stepDown();
  void stepUp();
  void stepRight();
  void stepLeft();
  void rotate();

  void setShadowPos(const Board& board);

protected:
  int m_rotationIdx{ 0 };
  TetrAbsPos m_absPos{};
};

namespace J_Tetromino
{
  inline static const TetrAbsPos s_absPos{{
    { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 } },  // 0° (initial)
    { { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 0 } },  // 90°
    { { 2, 2 }, { 0, 1 }, { 1, 1 }, { 2, 1 } },  // 180°
    { { 2, 0 }, { 2, 1 }, { 2, 2 }, { 1, 2 } }   // 270°
  }};
  
  inline static const sf::Color s_color{ sf::Color(0, 20, 255) };
  inline static const sf::Color s_shadowColor{ sf::Color(60, 60, 60) };
};

namespace I_Tetromino
{
  inline static const TetrAbsPos s_absPos{{
    { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } },  // 0° (initial)
    { { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 } },  // 90°
    { { 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 1 } },  // 180°
    { { 1, 0 }, { 1, 1 }, { 1, 2 }, { 1, 3 } }   // 270°
  }};

  inline static const sf::Color s_color{ sf::Color(30, 144, 255) };
  inline static const sf::Color s_shadowColor{ sf::Color(60, 60, 60) };
};

namespace O_Tetromino
{
  inline static const TetrAbsPos s_absPos{{
    { { 0, 0 }, { 1, 0 }, { 0, 1 }, { 1, 1 } }, // All rotations are the same for O_Tetromino
    { { 0, 0 }, { 1, 0 }, { 0, 1 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 0, 1 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 0, 1 }, { 1, 1 } }
  }};
  inline static const sf::Color s_color{ sf::Color(255, 215, 0) };
  inline static const sf::Color s_shadowColor{ sf::Color(60, 60, 60) };
};

namespace Z_Tetromino
{
  inline static const TetrAbsPos s_absPos{{
    { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 1 } },  // 0° (initial)
    { { 1, 0 }, { 0, 1 }, { 1, 1 }, { 0, 2 } },   // 90°
    { { 0, 1 }, { 1, 1 }, { 1, 2 }, { 2, 2 } },
    { { 1, 0 }, { 0, 1 }, { 1, 1 }, { 0, 2 } }
  }};
  inline static const sf::Color s_color{ sf::Color::Red };
  inline static const sf::Color s_shadowColor{ sf::Color(60, 60, 60) };
};

namespace S_Tetromino
{
  inline static const TetrAbsPos s_absPos{{
    { { 1, 0 }, { 2, 0 }, { 0, 1 }, { 1, 1 } },  // 0° (initial)
    { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 } },   // 90°
    { { 1, 1 }, { 2, 1 }, { 0, 2 }, { 1, 2 } },
    { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 } }
  }};
  inline static const sf::Color s_color{ sf::Color(50, 200, 0) };
  inline static const sf::Color s_shadowColor{ sf::Color(60, 60, 60) };
};

namespace T_Tetromino
{
  inline static const TetrAbsPos s_absPos{{
    { { 1, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 } },  // 0° (initial)
    { { 1, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 } },  // 90°
    { { 1, 2 }, { 0, 1 }, { 1, 1 }, { 2, 1 } },  // 180°
    { { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 1 } }   // 270°
  }};
  inline static const sf::Color s_color{ sf::Color(153, 17, 153) };
  inline static const sf::Color s_shadowColor{ sf::Color(60, 60, 60) };
};

namespace L_Tetromino
{
  inline static const TetrAbsPos s_absPos{{
    { { 2, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 } },  // 0° (initial)
    { { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 2 } },  // 90°
    { { 0, 2 }, { 0, 1 }, { 1, 1 }, { 2, 1 } },  // 180°
    { { 1, 0 }, { 1, 1 }, { 1, 2 }, { 0, 0 } }   // 270°
  }};
  inline static const sf::Color s_color{ sf::Color(255, 153, 0) };
  inline static const sf::Color s_shadowColor{ sf::Color(60, 60, 60) };
};

Tetromino getRandomTetromino(float cellSize);
Tetromino getShadow(const Tetromino& src);

#endif

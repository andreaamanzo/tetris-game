#ifndef PANEL_H
#define PANEL_H

#include "tetrominoes.h"
#include <SFML/Graphics.hpp>
#include <string>

class Panel
{
public:
  Panel(float width, float height, sf::Color color = sf::Color{ 60, 60, 60 }, float x = 0, float y = 0);
  void setPosition(float x, float y);
  void setTitle(const std::string& title);
  float getHeight() const;
  float getWidth() const;
  void draw(sf::RenderWindow& window) const;
  void drawInside(Tetromino& tetr, sf::RenderWindow& window) const;
  void drawInside(const std::string& str, sf::RenderWindow& window) const;

  static void loadFont();

private:
  inline static sf::Font s_font;
  sf::RectangleShape m_rect{};
  sf::Text m_title;
};



#endif
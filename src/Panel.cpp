#include "Panel.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <Settings.h>

Panel::Panel(float width, float height, sf::Color color, float x, float y)
  : m_rect{ sf::Vector2f{ width, height} }
  , m_title{ "", s_font, Settings::size }
{
  m_rect.setFillColor(color);
  m_rect.setPosition(x, y);
  m_title.setFillColor(sf::Color::White);
}

float Panel::getHeight() const { return m_rect.getSize().y; } 
float Panel::getWidth()  const { return m_rect.getSize().x; } 

void Panel::setPosition(float x, float y)
{
  m_rect.setPosition(x, y);
}

void Panel::setTitle(const std::string& title)
{
  m_title.setString(title);

  sf::FloatRect textBounds{ m_title.getLocalBounds() };
  m_title.setOrigin(
    textBounds.left + textBounds.width / 2.f,
    textBounds.top + textBounds.height
  );

  sf::FloatRect rectBounds{ m_rect.getGlobalBounds() };

  m_title.setPosition(
    rectBounds.left + rectBounds.width / 2.f,
    rectBounds.top - Settings::size
  );
}

void Panel::draw(sf::RenderWindow& window) const
{
  window.draw(m_rect);
  window.draw(m_title);
}

void Panel::drawInside(Tetromino& tetr, sf::RenderWindow& window) const
{
  sf::FloatRect rectBounds{ m_rect.getGlobalBounds() };

  float tetrWidth  = tetr.getEndPos().x - tetr.getStartPos().x;
  float tetrHeight = tetr.getEndPos().y - tetr.getStartPos().y;

  float panelCenterX{ rectBounds.left + rectBounds.width  / 2.f };
  float panelCenterY{ rectBounds.top  + rectBounds.height / 2.f };

  float newStartX = panelCenterX - tetrWidth  / 2.f;
  float newStartY = panelCenterY - tetrHeight / 2.f;

  tetr.setPos(newStartX, newStartY);

  tetr.draw(window);
}


void Panel::drawInside(const std::string& str, sf::RenderWindow& window) const
{
  sf::Text text{ str, s_font, Settings::size };

  sf::FloatRect textBounds{ text.getLocalBounds() };
  text.setOrigin(
    textBounds.left + textBounds.width / 2.f,
    textBounds.top + textBounds.height / 2.f
  );

  sf::FloatRect rectBounds{ m_rect.getGlobalBounds() };

  text.setPosition(
    rectBounds.left + rectBounds.width / 2.f,
    rectBounds.top + rectBounds.height / 2.f
  );

  window.draw(text);
}

void Panel::loadFont()
{
  if (!s_font.loadFromFile("../fonts/arial_narrow_7/arial_narrow_7.ttf"))
    throw std::runtime_error("Error while loading font (arial_narrow_7.ttf)");
}
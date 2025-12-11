#include "Settings.h"
#include "tetrominoes.h"
#include "Board.h"
#include "Panel.h"
#include <SFML/Graphics.hpp>

int main()
{
  Panel::loadFont();

  sf::RenderWindow window(sf::VideoMode(Settings::window_w, Settings::window_h), "Tetris");
  window.setFramerateLimit(60);
  
  Board board{ Settings::columns, Settings::rows };
  
  sf::RectangleShape panel{ sf::Vector2f{ Settings::panel_w, Settings::window_h } };
  panel.setPosition(Settings::board_w, 0.f);
  panel.setFillColor(sf::Color{ 20, 20, 20 });

  Panel nextPanel{ Settings::panel_w - Settings::size, 4 * Settings::size };
  nextPanel.setPosition(panel.getPosition().x + Settings::size / 2, Settings::window_h / 4 - nextPanel.getHeight() / 2);
  nextPanel.setTitle("Next");

  Panel scorePanel{ Settings::panel_w - Settings::size, 4 * Settings::size };
  scorePanel.setPosition(panel.getPosition().x + Settings::size / 2, nextPanel.getHeight() + nextPanel.getHeight() * 1.5f);
  scorePanel.setTitle("Score");

  Tetromino currTet{ getRandomTetromino(Settings::size) };
  currTet.setPos(Settings::spawn_tetromino_x, -static_cast<float>(Settings::size * 2));
  Tetromino nextTet{ getRandomTetromino(Settings::size) };

  Tetromino shadow{ getShadow(currTet) };

  int downDeley{ 30 };
  int downCount{ downDeley };
  int moveDeley{ 10 };
  int moveCount{ moveDeley };
  int deleteDeley{ 20 };
  int deleteCount{ deleteDeley };

  bool prevEnterPressed{ false };
  bool gameOver{ false };
  bool pause{ false };
  int score{ 0 };

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::KeyPressed)
      {
        if (event.key.code == sf::Keyboard::Q) window.close();
        if (event.key.code == sf::Keyboard::P) pause = !pause;
        if (event.key.code == sf::Keyboard::R)
        {
          board.clear();
          currTet = getRandomTetromino(Settings::size);
          currTet.setPos(Settings::spawn_tetromino_x, -static_cast<float>(Settings::size * 2));
          nextTet = getRandomTetromino(Settings::size);
          shadow = getShadow(currTet);
          score = 0;
          gameOver = false;
          pause = false;
        }
      }
    }

    if (pause)
      continue;

    if (gameOver)
      continue;

    //* --------------- CHECK COMPLETED ROWS --------------------

    int completedRows{ 0 };
    for (int i{ 0 }; i < board.getHeigth(); ++i)
    {
      if (board.isCompletedRow(i))
      {
        ++completedRows;
        if (deleteCount <= 0)
          board.deleteRow(i);
        else  
          board.setRowColor(i, sf::Color::White);
      }
    }

    if (completedRows > 0)
    {
      if (deleteCount <= 0) deleteCount = deleteDeley;
      else --deleteCount;
    }

    switch (completedRows)
    {
    case 1:
      score += 100; break;

    case 2:
      score += 300; break;
    
    case 3:
      score += 500; break;

    case 4:
      score += 800; break;

    default:
      break;
    }
      
    //* ------------------ MOVE ----------------------

    bool keyMovePressed{ true };
    if (moveCount <= 0)
    {
      keyMovePressed = false;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
        currTet.stepRight();
        if (!board.checkValidPosition(currTet))
          currTet.stepLeft();
        moveCount = moveDeley;
        keyMovePressed = true;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
        currTet.stepLeft();
        if (!board.checkValidPosition(currTet))
          currTet.stepRight();
        moveCount = moveDeley;
        keyMovePressed = true;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
        currTet.rotate();
        if (!board.checkValidPosition(currTet))
        {
          for (int i{ 0 }; i < 3; ++i)
            currTet.rotate();
        }
        shadow = getShadow(currTet);
        moveCount = moveDeley;
        keyMovePressed = true;
      }
    }

    --moveCount;

    bool currEnterPressed{ sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) };
    bool allDownPressed{ false };
    if (currEnterPressed && !prevEnterPressed)
    {
      allDownPressed = true;
      downCount = -1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      downCount -= 4;
    }
    else
      --downCount;

    if (downCount <= 0)
    {
      if (allDownPressed)
      {
        while (board.checkValidPosition(currTet))
        {
          currTet.stepDown();
          ++score;
        } 
      }
      else
      {
        currTet.stepDown();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) ++score;
      }

      downCount = downDeley;
    }

    prevEnterPressed = currEnterPressed;

    shadow.setPos(currTet.getStartPos());
    while (board.checkValidPosition(shadow))
    {
      shadow.stepDown();
    }
    shadow.stepUp();

    //* ------------------- COLLISION HANDLING ------------------------------
    
    bool collision{ false };
    if (!board.checkValidPosition(currTet))
    {
      currTet.stepUp();
      collision = true;
    }

    if (collision && !keyMovePressed)
    {
      for (const auto& cell : currTet.getCells())
      {
        int posX{ static_cast<int>(cell.getPos().x / Settings::size) };
        int posY{ static_cast<int>(cell.getPos().y / Settings::size) };

        if (posY < 0)
        {
          gameOver = true;
          continue;
        }
        board.setCell(cell, posX, posY);
      }

      currTet = nextTet;
      currTet.setPos(Settings::spawn_tetromino_x, -static_cast<float>(Settings::size * 2));
      shadow = getShadow(currTet);
      nextTet = getRandomTetromino(Settings::size);
      collision = false;
    }

    //* ---------------------- RENDERING -----------------------

    window.clear();

    window.draw(panel);
    nextPanel.drawInside(nextTet, window);
    nextPanel.draw(window);
    scorePanel.draw(window);
    scorePanel.drawInside(std::to_string(score), window);
    board.draw(window);
    shadow.draw(window);
    currTet.draw(window);
    nextTet.draw(window);

    window.display();
  }

  return 0;
}
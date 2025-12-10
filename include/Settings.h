#ifndef SETTINGS_H
#define SETTINGS_H

namespace Settings
{
  inline constexpr unsigned int size{ 40 };
  inline constexpr unsigned int rows{ 20 };
  inline constexpr unsigned int columns{ 10 };

  inline constexpr unsigned int board_w{ size * columns };
  inline constexpr unsigned int panel_w{ size * 6 };
  inline constexpr unsigned int window_w{ board_w + panel_w };
  inline constexpr unsigned int window_h{ size * rows };
  inline constexpr unsigned int n_tetrominoes{ 7 };
  inline constexpr float spawn_tetromino_x{ board_w / 2 - size };
}

#endif
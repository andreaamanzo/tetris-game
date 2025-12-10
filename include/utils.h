#ifndef UTILS_H
#define UTILS_H

#include <type_traits>

template <typename T>
constexpr std::size_t toUZ(T value)
{
  // make sure T is an integral type
  static_assert(std::is_integral<T>() || std::is_enum<T>());

  return static_cast<std::size_t>(value);
}

#endif
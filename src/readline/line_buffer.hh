#pragma once

#include <string>
#include <vector>

namespace readline
{
class LineBuffer
{
public:
  void push_character(char symbol, std::size_t index) noexcept;
  void discard_character(std::size_t index) noexcept;
  void clear_buffer() noexcept;

  operator char*() noexcept;
  operator std::string() noexcept;

  std::size_t size() const noexcept;

  std::size_t cursor_pos;
private:
  std::vector<char> buffer_{};
};
} // readline

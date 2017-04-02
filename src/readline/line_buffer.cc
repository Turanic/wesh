#include "line_buffer.hh"
#include <cassert>

namespace readline
{
void LineBuffer::push_character(char symbol, std::size_t index) noexcept
{
  assert(index <= buffer_.size());

  buffer_.insert(buffer_.begin() + index, symbol);
}

void LineBuffer::discard_character(std::size_t index) noexcept
{
  assert(index < buffer_.size());

  buffer_.erase(buffer_.begin() + index);
}

void LineBuffer::clear_buffer() noexcept
{
  buffer_.clear();
  cursor_pos = 0;
}

LineBuffer::operator char*() noexcept
{
  return buffer_.data();
}

LineBuffer::operator std::string() const noexcept
{
  return { buffer_.data(), buffer_.size() };
}

std::size_t LineBuffer::size() const noexcept
{
  return buffer_.size();
}

std::ostream& operator<<(std::ostream& os, const LineBuffer& buffer)
{
  os << buffer.operator std::string();

  return os;
}

} // readline

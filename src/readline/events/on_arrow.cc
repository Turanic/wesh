#include "on_arrow.hh"
#include <cstdio>
#include <readline/termcaps.hh>

namespace readline
{
namespace events
{
OnArrow::OnArrow(std::weak_ptr<LineBuffer> line_buffer) noexcept
    : buffer_ref_{ std::move(line_buffer) }
{
}

void OnArrow::operator()() noexcept
{
  auto buffer = buffer_ref_.lock();
  if (not buffer)
    return;

  std::getchar(); // skip [ char
  switch (std::getchar())
  {
  case 'C':
    if (buffer->cursor_pos < buffer->size())
    {
      ::readline::termcaps::move_cursor_right();
      buffer->cursor_pos++;
    }
    break;
  case 'D':
    if (buffer->cursor_pos > 0)
    {
      ::readline::termcaps::move_cursor_left();
      buffer->cursor_pos--;
    }
    break;
  default:
    break;
  };
}

std::string OnArrow::events_get() const noexcept
{
  static constexpr auto events = "\033";

  return events;
}
} // events
} // readline

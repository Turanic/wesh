#include "on_start_of_line.hh"
#include <readline/termcaps.hh>

namespace readline
{
namespace events
{
OnStartOfLine::OnStartOfLine(std::weak_ptr<LineBuffer> line_buffer)
  : buffer_ref_{std::move(line_buffer)}
{
}

void OnStartOfLine::operator()()
{
  auto buffer = buffer_ref_.lock();
  if (not buffer)
    return;

  while (buffer->cursor_pos > 0)
  {
    ::readline::termcaps::move_cursor_left();
    buffer->cursor_pos--;
  }
}

std::string OnStartOfLine::events_get() const
{
  static constexpr auto events = "\001";

  return events;
}

} // events
} // readline

#include "on_end_of_line.hh"
#include <readline/termcaps.hh>

namespace readline
{
namespace events
{
OnEndOfLine::OnEndOfLine(std::weak_ptr<LineBuffer> line_buffer)
  : buffer_ref_{std::move(line_buffer)}
{
}

void OnEndOfLine::operator()()
{
  auto buffer = buffer_ref_.lock();
  if (not buffer)
    return;

  while (buffer->cursor_pos < buffer->size())
  {
    ::readline::termcaps::move_cursor_right();
    buffer->cursor_pos++;
  }
}

std::string OnEndOfLine::events_get() const
{
  static constexpr auto events = "\005";

  return events;
}

} // events
} // readline

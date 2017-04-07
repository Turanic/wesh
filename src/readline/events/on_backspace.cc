#include "on_backspace.hh"
#include <readline/termcaps.hh>

namespace readline
{
namespace events
{
OnBackSpace::OnBackSpace(std::weak_ptr<LineBuffer> line_buffer)
    : buffer_ref_{ std::move(line_buffer) }
{
}

void OnBackSpace::operator()()
{
  auto buffer = buffer_ref_.lock();
  if (not buffer || not buffer->cursor_pos)
    return;

  ::readline::termcaps::move_cursor_left();
  buffer->cursor_pos--;

  ::readline::termcaps::delete_selected_char();
  buffer->discard_character(buffer->cursor_pos);

}

std::string OnBackSpace::events_get() const
{
  static constexpr auto events = "\b\177";

  return events;
}

} // events
} // readline

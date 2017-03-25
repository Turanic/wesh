#include "on_backspace.hh"
#include <readline/termcaps.hh>

namespace readline
{
namespace events
{
OnBackSpace::OnBackSpace(std::weak_ptr<std::vector<char>> line_buffer) noexcept
    : buffer_ref_{ std::move(line_buffer) }
{
}

void OnBackSpace::operator()() noexcept
{
  auto buffer = buffer_ref_.lock();
  if (buffer->empty())
    return;

  ::readline::termcaps::move_cursor_left();
  ::readline::termcaps::delete_selected_char();
  buffer->pop_back();
}

std::string OnBackSpace::events_get() const noexcept
{
  static constexpr auto events = "\b\177";

  return events;
}

} // events
} // readline

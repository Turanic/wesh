#include "on_backspace.hh"
#include <cassert>

namespace readline
{
namespace events
{
OnBackSpace::OnBackSpace(std::weak_ptr<std::vector<char>> line_buffer) noexcept
  : buffer_ref_{ std::move(line_buffer) }
{
}

void OnBackSpace::operator()() const noexcept
{
}

std::string OnBackSpace::events_get() const noexcept
{
  static constexpr auto events = "\b\127";

  return events;
}

} // events
} // readline

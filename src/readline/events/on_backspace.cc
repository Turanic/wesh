#include "on_backspace.hh"
#include <cassert>

#include <iostream>

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
  std::cerr << "hello world\n";
}

std::string OnBackSpace::events_get() const noexcept
{
  static constexpr auto events = "\b\177";

  return events;
}

} // events
} // readline

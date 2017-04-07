#include "on_exit.hh"
#include <exec/builtins/exit.hh>

namespace readline
{
namespace events
{
void OnExit::operator()()
{
  exec::builtins::exit();
}

std::string OnExit::events_get() const
{
  static constexpr auto events = "\004";

  return events;
}

} // events
} // readline

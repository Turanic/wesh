#include "command.hh"
#include <cassert>
#include "process.hh"

#include <iostream>

namespace exec
{
Command::Command()
    : previous_{nullptr}
{
}

Command::Command(std::unique_ptr<Command>&& previous)
    : previous_{std::move(previous)}
{
}

bool Command::operator()()
{
  assert(name);

  if (previous_)
  {
    if (not start_pipeline(*name, args))
      exec_pipeline();
    else
    {
      previous_.reset();
      return 0;
    }
  }


  bool rcode = start_process(*name, args);
  args = {};
  name = boost::optional<std::string>{};

  return rcode;
}

void Command::operator+=(const std::string& arg)
{
  if (name)
    args.push_back(arg);
  else
    name = arg;
}

bool Command::executable() const
{
  return static_cast<bool>(name);
}

void Command::exec_pipeline()
{
  if (previous_)
  {
    exec_pipe(*name, args);
    previous_->exec_pipeline();
  }
  else
    exec_process(*name, args);
}

} // exec

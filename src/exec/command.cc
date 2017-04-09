#include "command.hh"
#include <cassert>
#include "process.hh"

#include <iostream>

namespace exec
{
bool Command::operator()()
{
  assert(name);

  bool rcode = start_process(*name, args);
  args = {};
  name = boost::optional<std::string>{};

  if (next_)
  {
    std::cerr << "pipeline execution\n";
    (*next_)();
  }
  next_.reset();

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

Command* Command::push_to_pipeline()
{
  assert(not next_);

  next_ = std::make_unique<Command>();

  return next_.get();
}

} // exec

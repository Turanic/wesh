#include "command.hh"

namespace exec
{
void Command::operator()()
{
  assert(name);

  std::cerr << "executing command " << *name << '\n';
  rcode = start_process(*name, args);
  args = {};
  name = {};
}

void Command::operator+=(const std::string& arg)
{
  std::cerr << " ... adding " << arg << "...\n";
  if (name)
    args.push_back(arg);
  else
    name = arg;
}

} // exec

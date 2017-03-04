#include "process.hh"
#include <algorithm>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

namespace exec
{
namespace
{
std::vector<char*> convert_arg(std::string&& name,
                               std::vector<std::string>&& args)
{
  std::vector<char*> c_args{};
  c_args.push_back(&name[0]);
  std::transform(args.begin(),
                 args.end(),
                 std::back_inserter(c_args),
                 [](auto& str) { return &str[0]; });
  c_args.push_back(nullptr);

  return c_args;
}
} // anonymous

int start_process(std::string&& name, std::vector<std::string>&& args)
{
  const auto pid = fork();
  const auto c_args = convert_arg(std::move(name), std::move(args));

  switch (pid)
  {
  case -1: // error
    std::cerr << "Error while forking\n";
    return -1;
  case 0: // child
    execvp(name.c_str(), c_args.data());
    return -1;
  default: // parent
    int status = 0;
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
  }
}
} // exec

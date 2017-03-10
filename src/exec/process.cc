#include "process.hh"
#include <algorithm>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include "builtins/builtin.hh"

namespace exec
{
namespace
{
int exec_program(std::string name, std::vector<std::string> args)
{
  std::vector<char*> c_args{};
  c_args.push_back(&name[0]);
  std::transform(args.begin(),
                 args.end(),
                 std::back_inserter(c_args),
                 [](auto& str) { return &str[0]; });
  c_args.push_back(nullptr);
  execvp(name.c_str(), c_args.data());

  return -1;
}
} // anonymous

int start_process(const std::string& name, const std::vector<std::string>& args)
{
  const auto pid = fork();

  switch (pid)
  {
  case -1: // error
    std::cerr << "Error while forking\n";
    return -1;
  case 0: // child
    if (builtins::builtin(name, args) == 1)
      return 1;

    return exec_program(name, args);
  default: // parent
    int status = 0;
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
  }
}
} // exec

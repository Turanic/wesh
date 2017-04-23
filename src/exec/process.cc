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
  if (auto rcode = builtins::builtin(name, args))
    return *rcode;

  const auto pid = fork();

  switch (pid)
  {
  case -1: // error
    std::cerr << "Error while forking\n";
    return -1;
  case 0: // child
    std::exit(exec_program(name, args));
  default: // parent
    int status = 0;
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
  }
}

int exec_pipe(const std::string& name, const std::vector<std::string>& args)
{
  const auto pid = fork();

  int fds[2];
  pipe(fds);
  switch (pid)
  {
  case -1: // error
    std::cerr << "Error while forking\n";
    return -1;
  case 0: // child
    close(fds[0]);
    dup2(fds[1], STDOUT_FILENO);
    std::cerr << "fork context:" << name << '\n';
    return 0;
  default: // parent
    close(fds[1]);
    dup2(fds[0], STDIN_FILENO);
    int status = 0;
    waitpid(pid, &status, 0);
    exec_process(name, args);
  }
}

void exec_process(const std::string& name, const std::vector<std::string>& args)
{
    std::cerr << "exec: " << name << '\n';
    if (auto rcode = builtins::builtin(name, args))
      std::exit(*rcode);
    std::exit(exec_program(name, args));
}

int start_pipeline(const std::string& name,
                   const std::vector<std::string>& args)
{
  const auto pid = fork();

  switch (pid)
  {
  case -1: // error
    std::cerr << "Error while forking\n";
    return -1;
  case 0: // child
    std::cerr << "main fork\n";
    return 0; // pipeline started
  default:    // parent
    int status = 0;
    waitpid(pid, &status, 0);
    return 1;
  }
}

} // exec

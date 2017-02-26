#include "process.hh"

#include <iostream>

#include <unistd.h>
#include <sys/wait.h>

#include "command.hh"

namespace exec
{
int start_process(const Command&)
{
  const auto pid = fork();
  char *const test[] = { nullptr };
  switch (pid)
  {
  case -1: // error
    std::cerr << "Error while forking\n";
    return -1;
  case 0: // child
    execvp("tree", test);
    return -1;
  default: // parent
    int status = 0;
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
  }
}
} // exec

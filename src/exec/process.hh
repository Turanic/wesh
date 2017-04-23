#pragma once

#include <string>
#include <vector>
#include "command.hh"

namespace exec
{
int start_process(const std::string& name,
                  const std::vector<std::string>& args);

int exec_pipe(const std::string& name, const std::vector<std::string>& args);

[[noreturn]] void exec_process(const std::string& name,
                               const std::vector<std::string>& args);

int start_pipeline(const std::string& name,
                   const std::vector<std::string>& args);

} // exec

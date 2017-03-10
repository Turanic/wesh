#pragma once

#include <string>
#include <vector>

namespace exec
{
namespace builtins
{
int builtin(const std::string& name,
            const std::vector<std::string>& args,
            bool user_call = false);
} // builtins
} // exec

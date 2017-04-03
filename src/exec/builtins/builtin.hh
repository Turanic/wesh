#pragma once

#include <experimental/optional>
#include <string>
#include <vector>

namespace exec::builtins
{
std::experimental::optional<int> builtin(const std::string& name,
                                         const std::vector<std::string>& args,
                                         bool user_call = false);
} // exec::builtins

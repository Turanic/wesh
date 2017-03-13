#pragma once

#include <string>
#include <vector>
#include <boost/optional.hpp>

namespace exec
{
namespace builtins
{
boost::optional<int> builtin(const std::string& name,
                             const std::vector<std::string>& args,
                             bool user_call = false);
} // builtins
} // exec

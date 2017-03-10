#include "builtin.hh"
#include <cassert>
#include <cstdio>
#include <unordered_map>
#include <boost/optional.hpp>

namespace exec
{
namespace builtins
{
namespace
{
enum class builtins : uint8_t
{
  BUILTIN = 0,
  ECHO = 1,
};

boost::optional<builtins> builtin_from_name(const std::string& name)
{
  static std::unordered_map<std::string, builtins> builtins_name{
    { "builtin", builtins::BUILTIN }, { "echo", builtins::ECHO },
  };

  const auto iterator = builtins_name.find(name);
  if (iterator == builtins_name.end())
    return boost::optional<builtins>{};

  return iterator->second;
}

} // anonymous

int builtin(const std::string& name,
            const std::vector<std::string>& args,
            bool user_call)
{
  const auto builtin_opt = builtin_from_name(name);
  if (not builtin_opt)
  {
    if (user_call)
      std::printf("builtin: %s is not a builtin\n", name.c_str());
    return 1;
  }

  switch (*builtin_opt)
  {
  case builtins::BUILTIN:
    if (args.empty())
      return 0;

    return builtin(args[0], { std::next(args.begin()), args.end() }, true);
  case builtins::ECHO:
    return 2;
  };
}
} // builtins
} // exec

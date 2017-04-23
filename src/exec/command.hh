#pragma once

#include <memory>
#include <vector>
#include <boost/optional.hpp>

namespace exec
{
class Command
{
public:
  Command();
  Command(std::unique_ptr<Command>&& previous);

  bool operator()();
  void operator+=(const std::string& arg);

  bool executable() const;

private:
  boost::optional<std::string> name{};
  std::vector<std::string> args{};

  std::unique_ptr<Command> previous_;

  void exec_pipeline();
};

std::unique_ptr<Command> push_cmd_in_pipeline(std::unique_ptr<Command>&& cmd);
} // exec

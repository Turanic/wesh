#pragma once

#include <memory>
#include <vector>
#include <boost/optional.hpp>

namespace exec
{
class Command
{
public:
  bool operator()();
  void operator+=(const std::string& arg);

  bool executable() const;
  Command* push_to_pipeline();

private:
  boost::optional<std::string> name{};
  std::vector<std::string> args{};

  std::unique_ptr<Command> next_{nullptr};
};
} // exec

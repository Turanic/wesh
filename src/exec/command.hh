#pragma once

#include <cassert>
#include <experimental/optional>
#include <iostream>
#include <vector>
#include "process.hh"

namespace exec
{
class Command
{
public:
  bool rcode = false;

  void operator()();
  void operator+=(const std::string& arg);

private:

  std::experimental::optional<std::string> name{};
  std::vector<std::string> args{};
};
} // exec

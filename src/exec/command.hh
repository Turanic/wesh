#pragma once

#include <cassert>
#include <iostream>
#include <vector>
#include <boost/optional.hpp>
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
  boost::optional<std::string> name{};
  std::vector<std::string> args{};
};
} // exec

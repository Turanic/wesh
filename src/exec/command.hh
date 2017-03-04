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
private:
  boost::optional<std::string> name{};
  std::vector<std::string> args{};

public:
  bool rcode = false;
  void operator()()
  {
    assert(name);
    std::cerr << "executing command " << *name << '\n';
    rcode = start_process(std::move(*name), std::move(args));
    args = {};
    name = {};
  }

  void operator+=(const std::string& arg)
  {
    std::cerr << " ... adding " << arg << "...\n";
    if (name)
      args.push_back(arg);
    else
      name = arg;
  }
};
} // exec

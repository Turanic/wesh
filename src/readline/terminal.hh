#pragma once

#include <memory>
#include "events/observer_interface.hh"

namespace readline
{
class Terminal
{
public:
  Terminal() ;
  ~Terminal();

  bool next_char();
  std::string input_get();

private:
  struct Implem;
  std::unique_ptr<Implem> pimpl_;
};
} // readline

#pragma once

#include <string>
#include "observer_interface.hh"

namespace readline
{
namespace events
{
class OnExit : public ObserverInterface
{
public:
  [[noreturn]]
  void operator()() override;
  std::string events_get() const override;
};
} // events
} // readline

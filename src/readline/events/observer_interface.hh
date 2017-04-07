#pragma once

#include <string>

namespace readline
{
namespace events
{
class ObserverInterface
{
public:
  ObserverInterface() = default;
  virtual ~ObserverInterface() noexcept = default;

  ObserverInterface(const ObserverInterface&) = delete;
  ObserverInterface& operator=(const ObserverInterface&) = delete;

  ObserverInterface(ObserverInterface&&) noexcept = default;
  ObserverInterface& operator=(ObserverInterface&&) noexcept = default;

  virtual void operator()() = 0;
  virtual std::string events_get() const = 0;
};
} // events
} // readline

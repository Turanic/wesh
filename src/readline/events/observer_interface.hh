#pragma once

#include <string>

namespace readline::events
{
class ObserverInterface
{
public:
  ObserverInterface() noexcept = default;
  virtual ~ObserverInterface() noexcept = default;

  ObserverInterface(const ObserverInterface&) = delete;
  ObserverInterface(ObserverInterface&&) = delete;
  ObserverInterface& operator=(const ObserverInterface&) = default;
  ObserverInterface& operator=(ObserverInterface&&) = default;

  virtual void operator()() noexcept = 0;
  virtual std::string events_get() const noexcept = 0;
};
} // readline::events

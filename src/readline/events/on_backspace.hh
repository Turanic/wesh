#pragma once

#include <memory>
#include <string>
#include <vector>
#include "observer_interface.hh"

namespace readline
{
namespace events
{
class OnBackSpace : public ObserverInterface
{
public:
  OnBackSpace(std::weak_ptr<std::vector<char>> line_buffer) noexcept;

  void operator()() const noexcept override;
  std::string events_get() const noexcept override;

private:
  std::weak_ptr<std::vector<char>> buffer_ref_;
};
} // events
} // readline

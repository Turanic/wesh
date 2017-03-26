#pragma once

#include <memory>
#include <string>
#include <readline/line_buffer.hh>
#include "observer_interface.hh"

namespace readline
{
namespace events
{
class OnArrow : public ObserverInterface
{
public:
  explicit OnArrow(std::weak_ptr<LineBuffer> line_buffer) noexcept;

  void operator()() noexcept override;
  std::string events_get() const noexcept override;

private:
  std::weak_ptr<LineBuffer> buffer_ref_;
};
} // events
} // readline

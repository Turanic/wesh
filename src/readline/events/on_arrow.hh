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
  explicit OnArrow(std::weak_ptr<LineBuffer> line_buffer);

  void operator()() override;
  std::string events_get() const override;

private:
  std::weak_ptr<LineBuffer> buffer_ref_;
};
} // events
} // readline

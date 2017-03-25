#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include "events/observer_interface.hh"

struct termios; // forward declaration of termios structure
namespace readline
{
class Terminal
{
public:
  Terminal();
  ~Terminal();

  void send_event(char key_pressed);
  std::string input_get() const;

private:
  using observer_ptr_t = std::shared_ptr<events::ObserverInterface>;

  std::shared_ptr<std::vector<char>> line_buffer_;
  std::unique_ptr<termios> term_config_;
  std::unordered_map<char, observer_ptr_t> observers_;

  void register_observer(observer_ptr_t&& on_event);
};
} // readline

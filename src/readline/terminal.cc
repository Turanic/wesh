#include "terminal.hh"
<<<<<<< HEAD
#include <cassert>
#include <termios.h>
#include <unistd.h>
=======
>>>>>>> readline: add termcaps handling + functional observer
#include "events/on_backspace.hh"
#include "events/on_arrow.hh"
#include "termcaps.hh"

namespace readline
{
Terminal::Terminal()
    : line_buffer_{ std::make_shared<std::vector<char>>() }
    , term_config_{ nullptr }
    , observers_{}
{
  const auto cfg = termcaps::init_terminal(line_buffer_->data());
  term_config_ = std::make_unique<termios>(cfg);

  /* register key events observers */
  register_observer(std::make_shared<events::OnBackSpace>(line_buffer_));
  register_observer(std::make_shared<events::OnArrow>());
}

Terminal::~Terminal()
{
  termcaps::close_terminal(*term_config_);
}

void Terminal::send_event(char key_pressed)
{
  if (auto observer_ptr = observers_[key_pressed])
    (*observer_ptr)();
  else
  {
    line_buffer_->push_back(key_pressed);
    printf("%c", key_pressed);
  }
}

std::string Terminal::input_get() const
{
  std::string result{ line_buffer_->data(), line_buffer_->size() };
  line_buffer_->clear();

  return result;
}

void Terminal::register_observer(observer_ptr_t&& on_event)
{
  const auto events = on_event->events_get();
  for (const auto symbol : events)
    observers_[symbol] = on_event;
}

} // readline

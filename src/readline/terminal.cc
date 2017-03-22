#include "terminal.hh"
#include <cassert>
#include <termios.h>
#include <unistd.h>
#include "events/on_backspace.hh"

namespace readline
{
Terminal::Terminal()
    : term_config_{ std::make_unique<struct termios>() }
    , line_buffer_{ std::make_shared<std::vector<char>>() }
    , observers_{}
{
  /* store current config */
  tcgetattr(STDIN_FILENO, &*term_config_);

  /* set non canonical non echoing mode */
  auto new_config = *term_config_;
  new_config.c_lflag &= static_cast<unsigned int>(~(ICANON | ECHO));
  tcsetattr(STDIN_FILENO, TCSANOW, &new_config);

  /* register key events observers */
  register_observer(std::make_shared<events::OnBackSpace>(line_buffer_));
}

Terminal::~Terminal()
{
  tcsetattr(STDIN_FILENO, TCSANOW, &*term_config_);
}

void Terminal::send_event(char key_pressed)
{
  line_buffer_->push_back(key_pressed);
  if (auto observer_ptr = observers_[key_pressed])
    (*observer_ptr)();
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

#include "terminal.hh"
#include "events/on_backspace.hh"
#include <unordered_map>
#include <vector>
#include "events/on_arrow.hh"
#include "events/on_backspace.hh"
#include "line_buffer.hh"
#include "termcaps.hh"

namespace readline
{
struct Terminal::Implem
{
  using observer_ptr_t = std::shared_ptr<events::ObserverInterface>;

  std::shared_ptr<LineBuffer> line_buffer_{ std::make_shared<LineBuffer>() };
  std::unique_ptr<termios> term_config_{ std::make_unique<termios>(
    termcaps::init_terminal(*line_buffer_)) };
  std::unordered_map<char, observer_ptr_t> observers_{};

  void register_observer(observer_ptr_t&& on_event);
};

void Terminal::Implem::register_observer(observer_ptr_t&& on_event)
{
  const auto events = on_event->events_get();
  for (const auto symbol : events)
    observers_[symbol] = on_event;
}

Terminal::Terminal()
    : pimpl_{ std::make_unique<Terminal::Implem>() }
{
  /* register key events observers */
  const auto obs1 = std::make_shared<events::OnBackSpace>(pimpl_->line_buffer_);
  const auto obs2 = std::make_shared<events::OnArrow>(pimpl_->line_buffer_);
  pimpl_->register_observer(obs1);
  pimpl_->register_observer(obs2);
}

Terminal::~Terminal()
{
  termcaps::close_terminal(*pimpl_->term_config_);
}

bool Terminal::next_char()
{
  char key_pressed = std::getchar();

  if (key_pressed == '\n')
    return false;

  if (auto observer_ptr = pimpl_->observers_[key_pressed])
    (*observer_ptr)();
  else
  {
    pimpl_->line_buffer_->push_character(key_pressed,
                                         pimpl_->line_buffer_->cursor_pos);
    pimpl_->line_buffer_->cursor_pos++;
    printf("%c", key_pressed);
  }

  return true;
}

std::string Terminal::input_get()
{
  std::string result = *pimpl_->line_buffer_;
  result += '\n';
  pimpl_->line_buffer_->clear_buffer();

  return result;
}

} // readline

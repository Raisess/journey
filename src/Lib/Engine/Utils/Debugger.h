#pragma once

#include <iostream>
#include <vector>

namespace Utils {

class Debugger {
  private:
    std::string ctx;
    std::vector<std::string> messages;

    void dbgln(std::string);

  public:
    Debugger(std::string ctx);

    void draw_debug_log(void);
    void push_message(std::string message);
    void clear(void);
};

}

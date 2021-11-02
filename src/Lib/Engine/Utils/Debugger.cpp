#include "Debugger.h"
#include "Env.h"

#define DEBUG Utils::Env::get_env("DEBUG")

Utils::Debugger::Debugger(std::string ctx) : ctx(ctx) {}

void Utils::Debugger::draw_debug_log(void) {
  if (DEBUG == "true" || DEBUG == "1") {
    std::string message;

    for (int i = 0; i < this->messages.size(); i++) {
      message = this->messages[i];
      this->dbgln(message);
    }
  }
}

void Utils::Debugger::dbgln(std::string message) {
  std::cout << this->ctx << " >> " << message << std::endl;
}

void Utils::Debugger::push_message(std::string message) {
  this->messages.push_back(message);
}

void Utils::Debugger::clear(void) {
  this->messages.clear();
}

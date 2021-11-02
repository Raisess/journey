#pragma once

#include <iostream>

namespace Utils {

class Env {
  private:
    static std::string sanitaze(std::string value);

  public:
    static std::string get_env(std::string env_var);
};

}

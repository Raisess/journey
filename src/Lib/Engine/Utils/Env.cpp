#include <cstdlib>
#include "Env.h"

std::string Utils::Env::get_env(std::string env_var) {
  return sanitaze(std::getenv(env_var.c_str()));
}

std::string Utils::Env::sanitaze(std::string value) {
  int pos = value.find(" ");

  if (pos != std::string::npos) {
    value = value.substr(0, pos);
  }

  return value;
}

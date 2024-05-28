#include "Log.hpp"

Log &Log::operator++() {
  m_counter++;
  return *this;
}

Log Log::operator++(int) {
  Log temp = *this;
  m_counter++;
  return temp;
}

std::ostream &operator<<(std::ostream &os, const Log &log) {
  return os << "log: " << log.m_counter;
}

int Log::getCounter() const {
  return m_counter;
}

Log::Log() = default;

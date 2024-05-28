#ifndef APP_LOG_HPP
#define APP_LOG_HPP

#include <ostream>

class Log {
private:
  int m_counter = 0;

public:
  Log();
  [[nodiscard]] int getCounter() const;
  Log &operator++();
  Log operator++(int);
  friend std::ostream &operator<<(std::ostream &, const Log &);
};


#endif //APP_LOG_HPP

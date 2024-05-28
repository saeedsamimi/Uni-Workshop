project(PhoneBook)
project(Employment)

add_executable(PhoneBook PhoneBook/main.cpp PhoneBook/PhoneBook.hpp PhoneBook/PhoneBook.cpp)
target_include_directories(PhoneBook PRIVATE PhoneBook)

add_executable(Employment Employment/main.cpp Employment/Employee.hpp Employment/Employee.cpp)
target_include_directories(Employment PRIVATE Employment)
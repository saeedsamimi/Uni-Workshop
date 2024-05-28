project(BankAccount)

add_executable(BankAccount BankAccount/main.cpp BankAccount/bankaccount.cpp BankAccount/bankaccount.hpp)
target_include_directories(BankAccount PRIVATE BankAccount)

project(Cube)

add_executable(Cube Cube/main.cpp Cube/cube.cpp Cube/cube.hpp)
target_include_directories(Cube PRIVATE Cube)
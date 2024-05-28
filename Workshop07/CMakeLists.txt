project(BinaryNumber)

add_executable(BinaryNumber BinaryNumber/main.cpp BinaryNumber/BinaryNumber.cpp BinaryNumber/BinaryNumber.hpp)
target_include_directories(BinaryNumber PRIVATE BinaryNumber)

project(LogCounter)

add_executable(LogCounter LogCounter/main.cpp LogCounter/Admin.cpp LogCounter/Admin.hpp LogCounter/Log.cpp LogCounter/Log.hpp)
target_include_directories(LogCounter PRIVATE LogCounter)
cmake_minimum_required(VERSION 3.10)
project(assignment3)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp MadLibsController.cpp MadlibUserWordProvider.cpp MadlibAutoWordProvider.cpp)

add_executable(auto_test auto_test.cpp MadLibsController.cpp MadlibAutoWordProvider.cpp)
add_executable(auto_test_plural auto_test_plural.cpp MadLibsController.cpp MadlibAutoWordProvider.cpp)
add_executable(controller_test controller_test.cpp MadLibsController.cpp)
add_executable(user_test user_test.cpp MadLibsController.cpp MadlibUserWordProvider.cpp)
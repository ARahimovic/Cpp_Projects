cmake_minimum_required(VERSION 3.10...3.25)

project(MyClass VERSION 0.1 LANGUAGES CXX C)

set(myExecutable ${PROJECT_NAME}.exe)

add_executable(
  ${myExecutable}

  src/MyClass.cpp
  test-src/testMyClass.cpp
)

target_include_directories(
  ${myExecutable} PUBLIC

  include
)

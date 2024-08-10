cmake_minimum_required(VERSION 3.10)

set(EXE_NAME "gtk")

project(
  gtk-practice
  VERSION 1.0
  LANGUAGES CXX)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${EXE_NAME} src/main.cc src/radiobuttons.cc src/radiobuttons.h)

target_include_directories(${EXE_NAME} PRIVATE ${GTKMM_INCLUDE_DIRS})

target_link_libraries(${EXE_NAME} PRIVATE ${GTKMM_LIBRARIES})
# # Add necessary compile options target_compile_options(${EXE_NAME} PRIVATE
# ${GTKMM_CFLAGS_OTHER})

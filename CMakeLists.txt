cmake_minimum_required(VERSION 3.1)


project(project_name)

find_library(PTHREAD_LIBRARY pthread)
find_library(PCRE_LIBRARY pcre)

include_directories(include)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror")

add_executable(main main.cpp)

target_link_libraries(main ${PTHREAD_LIBRARY} ${PCRE_LIBRARY})
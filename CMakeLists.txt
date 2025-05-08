cmake_minimum_required(VERSION 4.0.1)

project(cmake-sdl2-starter)

add_executable(${PROJECT_NAME} main.cpp)

### Below is used when library source code is in the same directory as the rest of the source code
# SHARED is for dynamic libraries - linked at runtime
# STATIC (default if not specified) - compiles into executable 
add_library(mylib SHARED lib.cpp)

# Link our library "mylib" to our executable PROJECT_NAME
# So our main.cpp sees the definition(s) of the forward declarations made in the header files included
target_link_libraries(${PROJECT_NAME} mylib)
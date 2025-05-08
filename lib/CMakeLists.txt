# Add the library source code to our library "mylib"
add_library(mylib lib.cpp)

# export this lib directory as part of the search path for header files in this project
target_include_directories(mylib 
    # PRIVATE, PUBLIC, INTERFACE similar to c++ private, protected, public
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})
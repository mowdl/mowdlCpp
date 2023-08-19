cmake_minimum_required(VERSION 3.22)
project(mowdlCpp)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        src/main.cpp
        src/Array.cpp
        src/LinkedList.cpp
        src/Queue.cpp
        )

set(HEADERS
        include/mowdlCpp/Array.h
        include/mowdlCpp/LinkedList.h
        include/mowdlCpp/Queue.h
        )

add_library(mowdlCpp_lib STATIC ${SOURCES} ${HEADERS})
add_executable(mowdlCpp ${SOURCES})

# Link the executable with the library
target_link_libraries(mowdlCpp mowdlCpp_lib)

# Include directories for the library
target_include_directories(mowdlCpp_lib PUBLIC include)

# Include directories for the executable
target_include_directories(mowdlCpp PRIVATE include)

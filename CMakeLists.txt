cmake_minimum_required(VERSION 3.10)

project(PRFProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add some security-related flags
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    add_compile_options(
        -Wall                   # Enable all warnings
        -Wextra                 # Extra warning flags
        -Wpedantic              # Enforce C++ standard compliance
        -Wshadow                # Warn if a local variable shadows another variable
        -fstack-protector-strong # Add stack protection
        -D_FORTIFY_SOURCE=2     # Add checks to detect some buffer overflow errors
        -Wformat                # Check printf and scanf formats
        -Wformat-security       # Additional format checks
        -pie                    # Generate position independent executables
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(
        /W4     # Warning level 4
        /GS     # Add buffer security checks
        /sdl    # Enable additional security checks
    )
endif()

include_directories(./include)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG)
endif()

FILE(GLOB SOURCES ./src/*.cpp ./src/*.hpp)
add_executable(${PROJECT_NAME} ${SOURCES})
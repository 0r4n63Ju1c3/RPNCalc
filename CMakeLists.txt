cmake_minimum_required(VERSION 3.9)

# Set the title of your project and language
project(myExe C)

# Set the version of the C language standard you will be using
set(CMAKE_C_STANDARD 99)

# Turn on helpful compiler warnings
#set(CMAKE_C_FLAGS "-Wall -Werror") # all warnings are on and treated as errors
set(CMAKE_C_FLAGS "-Wall")

# Set the source directory, the place where your main.c and
# other files are located
set(SDIR PEX3/)

# List all files that are required to compile your project
set(SOURCE_FILES
        ${SDIR}listAsLinkedList.h
        ${SDIR}listAsLinkedList.c
        ${SDIR}mathFunctions.h
        ${SDIR}mathFunctions.c
        ${SDIR}main.c)

# Tell cmake the name of your executable and what source files to
# build from
add_executable(myExe ${SOURCE_FILES})

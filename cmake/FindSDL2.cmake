cmake_minimum_required(VERSION 2.8.2)

configure_file(${CMAKE_CURRENT_LIST_DIR}/sdl2-CMakeLists.txt.in sdl2-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sdl2-download )

message("downloads=${CMAKE_CURRENT_BINARY_DIR}/sdl2-download")

if(result)
    message(FATAL_ERROR "CMake step for sdl2 failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sdl2-download )
if(result)
    message(FATAL_ERROR "Build step for sdl2 failed: ${result}")
endif()

if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
    set(ARCH x64)
else()
    set(ARCH x86)
endif()

if(MSVC)
    set(LINK_FILE SDL2.lib)
else()
    set(LINK_FILE SDL2.dll)
endif()

set(DLL ${CMAKE_BINARY_DIR}/sdl2-src/lib/${ARCH}/SDL2.dll)

add_library(SDL2 STATIC IMPORTED)
set_target_properties(SDL2 PROPERTIES
#    IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/sdl2-src/lib/${ARCH}/SDL2main.lib
    IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/sdl2-src/lib/${ARCH}/${LINK_FILE}
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_BINARY_DIR}/sdl2-src/include
    INTERFACE_COMPILE_DEFINITIONS SDL_MAIN_HANDLED
)

FILE(COPY ${DLL} DESTINATION ${CMAKE_BINARY_DIR})

#set(SDL2_FOUND true)
#set(SDL2_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/sdl2-src/SDL2-2.0.5/include)
#set(SDL2_LIBRARIES  ${CMAKE_BINARY_DIR}/sdl2-src/SDL2-2.0.5/lib/${ARCH}/SDL2.lib)
#set(SDL2_DEFINITIONS SDL_MAIN_HANDLED)

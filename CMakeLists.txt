CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

add_subdirectory(privy)

set(SOURCE_LIST
        main.cpp
        )

add_executable(main ${SOURCE_LIST})
target_link_libraries(main privy)
target_include_directories(main PRIVATE ".")
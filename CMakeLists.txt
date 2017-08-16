CMAKE_MINIMUM_REQUIRED(VERSION 3.8)


if(WIN32 OR CYGWIN)
    set(CMAKE_REQUIRED_FLAGS "-mno-cygwin")
    set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
endif()

project(GameEngine)

add_subdirectory(privy)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_LIST
        main.cpp
        util/ini_parser.cpp util/ini_parser.h privy/sprite.cpp privy/include/privy/sprite.h FroggerTexturePack.h util/util.h)

add_executable(main ${SOURCE_LIST})
target_link_libraries(main privy)
target_include_directories(main PRIVATE ".")

set(ASSETS_DIR ${CMAKE_CURRENT_LIST_DIR}/assets)
if(CYGWIN)
    EXECUTE_PROCESS(COMMAND cygpath -w ${ASSETS_DIR}
            OUTPUT_VARIABLE ASSETS_DIR
    )
endif()

CONFIGURE_FILE(config.ini.in ${CMAKE_BINARY_DIR}/config.ini @ONLY)
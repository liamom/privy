project(Privy)

find_package(SDL2 REQUIRED)

set(SOURCE_LIST
        privy.cpp privy.h
        exception_impl.cpp exception_impl.h
        logger.h
        include/privy/exception.h
)

add_library(engine STATIC ${SOURCE_LIST})
target_link_libraries(engine ${SDL2_LIBRARIES})
target_include_directories(engine PUBLIC ${SDL2_INCLUDE_DIRS})
project(Privy)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

#message("SDL2_LIBRARIES=${SDL2_LIBRARIES}")
message("SDL2_FOUND=${SDL2_FOUND}")
message("SDL2=${SDL2}")

set(SOURCE_LIST
        privy.cpp privy.h
        exception_impl.cpp exception_impl.h
        logger.h
        include/privy/exception.h
        Window.cpp Window.h sdl_base.h renderer.cpp renderer.h texture.cpp texture.h surface.cpp surface.h)

add_library(privy STATIC ${SOURCE_LIST})
target_link_libraries(privy SDL2)
#target_link_libraries(privy ${SDL2_LIBRARIES})
#target_include_directories(privy PUBLIC ${SDL2_INCLUDE_DIRS})
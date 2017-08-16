project(Privy)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)

set(SOURCE_LIST
        include/privy/privy.h
        exception_impl.cpp exception_impl.h
        logger.h
        include/privy/exception.h
        Window.cpp include/privy/Window.h include/privy/sdl_base.h renderer.cpp include/privy/renderer.h texture.cpp include/privy/texture.h surface.cpp include/privy/surface.h Game.cpp include/privy/Game.h include/privy/privy_math.h view.cpp include/privy/view.h include/privy/matix.h)

get_target_property(asdf SDL2::IMAGE IMPORTED_LOCATION)
message("asdf=${asdf}")

add_library(privy ${SOURCE_LIST})
target_link_libraries(privy SDL2::CORE SDL2::IMAGE)
target_include_directories(privy
        PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include/privy
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include
)
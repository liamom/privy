include(${CMAKE_CURRENT_LIST_DIR}/DownloadPackage.cmake)
DownloadPackage(SDL2_IMAGE http://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.1-VC.zip SDL2_IMAGE_SOURCE_DIR)

#configure_file(${CMAKE_CURRENT_LIST_DIR}/sdl2_image-CMakeLists.txt.in sdl2_image-download/CMakeLists.txt)

if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
    set(ARCH x64)
else()
    set(ARCH x86)
endif()

set(LIB_DIR ${SDL2_IMAGE_SOURCE_DIR}/lib/${ARCH})

set(DLLS
        ${LIB_DIR}/libjpeg-9.dll
        ${LIB_DIR}/libpng16-16.dll
        ${LIB_DIR}/libtiff-5.dll
        ${LIB_DIR}/libwebp-4.dll
        ${LIB_DIR}/SDL2_image.dll
        ${LIB_DIR}/zlib1.dll
        )

if(CYGWIN)
    set(CMAKE_IMPORT_LIBRARY_SUFFIX .dll)
ENDIF()

add_library(SDL2::IMAGE UNKNOWN IMPORTED)
set_target_properties(SDL2::IMAGE PROPERTIES
#        IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/sdl2_image-src/lib/${ARCH}/${LINK_FILE}
        IMPORTED_LOCATION             ${LIB_DIR}/SDL2_image${CMAKE_IMPORT_LIBRARY_SUFFIX}
        INTERFACE_INCLUDE_DIRECTORIES ${SDL2_IMAGE_SOURCE_DIR}/include
        INTERFACE_COMPILE_DEFINITIONS SDL_MAIN_HANDLED
        )


FILE(COPY ${DLLS} DESTINATION ${CMAKE_BINARY_DIR})

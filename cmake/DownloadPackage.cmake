cmake_minimum_required(VERSION 2.8.2)

function(DownloadPackage PACKAGE_NAME PACKAGE_URL SOURCE_DIR)
    set(DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}/${PACKAGE_NAME}-download)
    set(${SOURCE_DIR} "${DOWNLOAD_DIR}/${PACKAGE_NAME}-src" PARENT_SCOPE)

    configure_file(${CMAKE_CURRENT_LIST_DIR}/DownloadPackage-CMakeLists.txt.in ${DOWNLOAD_DIR}/CMakeLists.txt @ONLY)

    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${DOWNLOAD_DIR} )

    if(result)
        message(FATAL_ERROR "CMake step for ${PACKAGE_NAME} failed: ${result}")
    endif()
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${DOWNLOAD_DIR} )
    if(result)
        message(FATAL_ERROR "Build step for ${PACKAGE_NAME} failed: ${result}")
    endif()
endfunction()
cmake_minimum_required(VERSION 3.10)

ADD_DEFINITIONS(-DLV_BUILD_EXAMPLES=1)

# compile cJSON
FILE(GLOB_RECURSE CJSON_SRC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/cJSON/*.c)
ADD_LIBRARY(cjson ${CJSON_SRC})

# compile iniparser
FILE(GLOB_RECURSE INI_PARSER_SRC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/iniparser/src/*.c)
ADD_LIBRARY(ini_parser ${INI_PARSER_SRC})

# compile thread warpper
FILE(GLOB_RECURSE THREAD_WARPPER_SRC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/thread/*.c)
ADD_LIBRARY(thread_warpper ${THREAD_WARPPER_SRC})

IF((${CMAKE_C_COMPILER} STREQUAL "/usr/bin/cc") AND ((${CMAKE_CXX_COMPILER} STREQUAL "/usr/bin/c++")))
    MESSAGE(STATUS "-----------\n-----X86------\n--------------")
    # compile lvgl
    ADD_DEFINITIONS(-DX86 -DLV_USE_SDL=1 -DLV_CONF_PATH=${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/lv_conf.h)
    FIND_PACKAGE(SDL2 REQUIRED)
    FIND_PACKAGE(JPEG REQUIRED)
    add_subdirectory(thirdparty/lvgl)
    TARGET_INCLUDE_DIRECTORIES(lvgl PRIVATE ${SDL2_INCLUDE_DIRS} ${JPEG_INCLUDE_DIRS})
    MESSAGE(STATUS "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty")

    add_executable(MonitorX main.c)
    TARGET_INCLUDE_DIRECTORIES(MonitorX PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty")
    target_link_libraries(MonitorX lvgl lvgl::examples lvgl::demos lvgl::thorvg m pthread ${SDL2_LIBRARIES} ${JPEG_LIBRARIES})
ELSE()
    MESSAGE(STATUS "-----------\n-----ARM------\n--------------")
    ADD_DEFINITIONS(-DARM -DLV_USE_LINUX_FBDEV=1 -DLV_USE_EVDEV=1)

    SET(THIRD_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/lib/armhf/include")
    SET(THIRD_LIBRARY_PATH "${PROJECT_SOURCE_DIR}/lib/armhf/lib")

    add_subdirectory(thirdparty/lvgl)
    TARGET_INCLUDE_DIRECTORIES(lvgl PRIVATE ${PROJECT_SOURCE_DIR} ${THIRD_INCLUDE_PATH})
    LINK_DIRECTORIES(${THIRD_LIBRARY_PATH})

    add_executable(MonitorX main.c)
    target_link_libraries(MonitorX lvgl lvgl::examples lvgl::demos lvgl::thorvg m pthread jpeg)
ENDIF()

add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/MonitorX DEPENDS MonitorX)

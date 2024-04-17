CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# compile cJSON
FILE(GLOB_RECURSE CJSON_SRC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/cJSON/*.c)
ADD_LIBRARY(cjson ${CJSON_SRC})

# compile iniparser
FILE(GLOB_RECURSE INI_PARSER_SRC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/iniparser/src/*.c)
ADD_LIBRARY(ini_parser ${INI_PARSER_SRC})

# compile thread warpper
FILE(GLOB_RECURSE THREAD_WARPPER_SRC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/thread/*.c)
ADD_LIBRARY(thread_warpper ${THREAD_WARPPER_SRC})

SET(THIRDPARTY_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty")

# compile ui
SET(UI_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/ui")
FILE(GLOB UI_SRC    ${UI_INCLUDE_PATH}/*.c                      # ui.c ui_helper.c
                    ${UI_INCLUDE_PATH}/font/*.c                 # fonts
                    ${UI_INCLUDE_PATH}/page/ui_page_monitor.c
                    ${UI_INCLUDE_PATH}/page/ui_page_git.c
                    ${UI_INCLUDE_PATH}/page/ui_page_bili.c
                    ${UI_INCLUDE_PATH}/page/ui_page_tomato.c
                    ${UI_INCLUDE_PATH}/page/ui_page_clock.c)
ADD_LIBRARY(ui ${UI_SRC})
TARGET_INCLUDE_DIRECTORIES(ui PRIVATE ${THIRDPARTY_INCLUDE_PATH})
TARGET_LINK_LIBRARIES(ui lvgl)

# compile app
SET(APP_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/app")
FILE(GLOB APP_SRC   ${APP_INCLUDE_PATH}/json_parser.c
                    ${APP_INCLUDE_PATH}/util.c
                    ${APP_INCLUDE_PATH}/config.c
                    ${APP_INCLUDE_PATH}/bili.c
                    ${APP_INCLUDE_PATH}/monitor.c)
#ADD_DEFINITIONS(-DnoWformat-overflow)
ADD_LIBRARY(app ${APP_SRC})
TARGET_INCLUDE_DIRECTORIES(app PRIVATE ${APP_INCLUDE_PATH} ${UI_INCLUDE_PATH} ${THIRDPARTY_INCLUDE_PATH})
TARGET_LINK_LIBRARIES(app ui cjson ini_parser)

IF((${CMAKE_C_COMPILER} STREQUAL "/usr/bin/cc") AND ((${CMAKE_CXX_COMPILER} STREQUAL "/usr/bin/c++")))
    MESSAGE(STATUS "-----------\n-----X86------\n--------------")
    # compile lvgl
    ADD_DEFINITIONS(-DLV_BUILD_EXAMPLES=0)
    ADD_DEFINITIONS(-DX86 -DLV_USE_SDL=1 -DLV_CONF_PATH=${THIRDPARTY_INCLUDE_PATH}/lv_conf.h)
    FIND_PACKAGE(SDL2 REQUIRED)
    FIND_PACKAGE(Freetype REQUIRED)
    FIND_PACKAGE(JPEG REQUIRED)
    FIND_PACKAGE(CURL REQUIRED)
    ADD_SUBDIRECTORY(thirdparty/lvgl)
    TARGET_INCLUDE_DIRECTORIES(lvgl PRIVATE ${SDL2_INCLUDE_DIRS} ${JPEG_INCLUDE_DIRS} ${FREETYPE_INCLUDE_DIRS} ${CURL_INCLUDE_DIRS})

    ADD_EXECUTABLE(MonitorX main.c)
    TARGET_INCLUDE_DIRECTORIES(MonitorX PRIVATE ${THIRDPARTY_INCLUDE_PATH} ${UI_INCLUDE_PATH} ${APP_INCLUDE_PATH})
    TARGET_LINK_LIBRARIES(MonitorX lvgl lvgl::examples lvgl::demos lvgl::thorvg 
                            ui app thread_warpper
                            m pthread
                            ${SDL2_LIBRARIES} ${JPEG_LIBRARIES} ${FREETYPE_LIBRARIES} ${CURL_LIBRARIES})
ELSE()
    MESSAGE(STATUS "-----------\n-----ARM------\n--------------")
    ADD_DEFINITIONS(-DARM -DLV_USE_LINUX_FBDEV=1 -DLV_USE_EVDEV=1)

    SET(THIRD_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/lib/armhf/include")
    SET(THIRD_LIBRARY_PATH "${PROJECT_SOURCE_DIR}/lib/armhf/lib")

    ADD_SUBDIRECTORY(thirdparty/lvgl)
    TARGET_INCLUDE_DIRECTORIES(lvgl PRIVATE ${PROJECT_SOURCE_DIR} ${THIRD_INCLUDE_PATH})
    LINK_DIRECTORIES(${THIRD_LIBRARY_PATH})

    ADD_EXECUTABLE(MonitorX main.c)
    TARGET_LINK_LIBRARIES(MonitorX lvgl lvgl::examples lvgl::demos lvgl::thorvg m pthread jpeg)
ENDIF()

ADD_CUSTOM_TARGET (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/MonitorX DEPENDS MonitorX)

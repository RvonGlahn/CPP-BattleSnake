# Lib Includes
set(LIBRARY_SOURCES "Server.cc")
set(LIBRARY_PATH "${PROJECT_SOURCE_DIR}/include/server")
set(LIBRARY_HEADERS "${LIBRARY_PATH}/Server.h")
set(LIBRARY_INCLUDES "${PROJECT_SOURCE_DIR}/include/server/") 

add_library(${LIB_NAME_SERVER} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIB_NAME_SERVER} PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(${LIB_NAME_SERVER} PUBLIC loguru)
target_link_libraries(${LIB_NAME_SERVER} PUBLIC ${LIB_NAME_ENV})


if(${ENABLE_LTO})
target_enable_lto(${LIB_NAME_SERVER} optimized)
endif()
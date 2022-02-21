# Lib Includes
set(LIBRARY_SOURCES "Server.cc" )
set(LIBRARY_HEADERS "${PROJECT_SOURCE_DIR}/include/Server.h")
set(LIBRARY_INCLUDES "${PROJECT_SOURCE_DIR}/include/") 

add_library(${LIBRARY_NAME} ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(${LIBRARY_NAME} PUBLIC loguru)
target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_17)
target_set_warnings(TARGET ${LIBRARY_NAME} ENABLE OFF AS_ERROR OFF)
if(${ENABLE_LTO})
target_enable_lto(${LIBRARY_NAME} optimized)
endif()
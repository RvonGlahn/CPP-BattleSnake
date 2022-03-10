# Lib Includes
set(LIBRARY_SOURCES "AStar.cc" "FloodFill.cc" "MonteCarlo.cc" "Util.cc")
set(LIBRARY_PATH "${PROJECT_SOURCE_DIR}/include/logic")
set(LIBRARY_HEADERS "${LIBRARY_PATH}/AStar.h" "${LIBRARY_PATH}/Util.h" "${LIBRARY_PATH}/FloodFill.h" "${LIBRARY_PATH}/MonteCarlo.h")
set(LIBRARY_INCLUDES "${PROJECT_SOURCE_DIR}/include/logic/") 

add_library(${LIB_NAME_LOGIC} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIB_NAME_LOGIC} PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(${LIB_NAME_LOGIC} PUBLIC ${LIB_NAME_ENV})
target_compile_features(${LIB_NAME_LOGIC} PUBLIC cxx_std_17)
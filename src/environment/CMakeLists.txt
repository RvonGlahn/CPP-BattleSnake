# Lib Includes
set(LIBRARY_SOURCES "Position.cc" "Snake.cc" "BoardState.cc")
set(LIBRARY_PATH "${PROJECT_SOURCE_DIR}/include/environment")
set(LIBRARY_HEADERS "${LIBRARY_PATH}/Position.h" "${LIBRARY_PATH}/Direction.h" "${LIBRARY_PATH}/Snake.h" "${LIBRARY_PATH}/BoardState.h")
set(LIBRARY_INCLUDES "${PROJECT_SOURCE_DIR}/include/environment/") 

add_library(${LIB_NAME_ENV} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIB_NAME_ENV} PUBLIC ${LIBRARY_INCLUDES})
target_compile_features(${LIB_NAME_ENV} PUBLIC cxx_std_17)
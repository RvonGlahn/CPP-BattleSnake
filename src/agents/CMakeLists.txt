# Lib Includes
set(LIBRARY_SOURCES "Agents.cc")
set(LIBRARY_PATH "${PROJECT_SOURCE_DIR}/include/agents")
set(LIBRARY_HEADERS "${LIBRARY_PATH}/Agents.h")
set(LIBRARY_INCLUDES "${PROJECT_SOURCE_DIR}/include/agents/") 

add_library(${LIB_NAME_AGENTS} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIB_NAME_AGENTS} PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(${LIB_NAME_AGENTS} PUBLIC ${LIB_NAME_ENV})


if(${ENABLE_LTO})
target_enable_lto(${LIB_NAME_AGENTS} optimized)
endif()
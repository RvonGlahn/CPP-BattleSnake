set(EXECUTABLE_SOURCES "Main.cc")

add_executable(${EXECUTABLE_NAME} ${EXECUTABLE_SOURCES})
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIB_NAME_AGENTS})
target_compile_features(${EXECUTABLE_NAME} PUBLIC cxx_std_17)
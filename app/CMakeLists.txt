set(EXECUTABLE_SOURCES "main.cc")

add_executable(${EXECUTABLE_NAME} ${EXECUTABLE_SOURCES})
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})
target_compile_features(${EXECUTABLE_NAME} PUBLIC cxx_std_17)
# Executable
add_executable(${TEST_MAIN} "TestPosition.cc" "TestSnake.cc")

# Settings
target_compile_features(${TEST_MAIN} PRIVATE cxx_std_17)
target_link_libraries(${TEST_MAIN} PRIVATE ${LIB_NAME_ENV} ${CONAN_CATCH2})


# Test
add_test(NAME ${LIB_NAME_ENV}.${TEST_MAIN} COMMAND ${TEST_MAIN})


# Coverage
if (ENABLE_COVERAGE)
    set(COVERAGE_MAIN "${PROJECT}_coverage")
    set(COVERAGE_LCOV_EXCLUDES
        "${PROJECT_SOURCE_DIR}/app/*"
        "${PROJECT_SOURCE_DIR}/cmake/*"
        "${PROJECT_SOURCE_DIR}/docs/*"
        "${PROJECT_SOURCE_DIR}/external/*"
        "${PROJECT_SOURCE_DIR}/tests/*"
        "${CONAN_BOOST_ROOT}/*"
        "${CONAN_CATCH2_ROOT}/*"
        "/usr/include/*")
    setup_target_for_coverage_lcov(
        NAME ${COVERAGE_MAIN}
        EXECUTABLE ctest
        DEPENDENCIES ${TEST_MAIN})
endif()
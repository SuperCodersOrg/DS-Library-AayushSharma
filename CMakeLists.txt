cmake_minimum_required(VERSION 3.16)

project(DS_LIBRARY VERSION 1.0 LANGUAGES CXX)

# ------------------------------------------------------------
# C++ Standard
# ------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile_commands.json (helps VS Code IntelliSense)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ------------------------------------------------------------
# Enable Testing
# ------------------------------------------------------------
enable_testing()

# ------------------------------------------------------------
# GoogleTest
# ------------------------------------------------------------
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

# Prevent overriding the parent project's compiler settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# ------------------------------------------------------------
# Include Directories
# ------------------------------------------------------------
include_directories(${PROJECT_SOURCE_DIR}/include)

# ------------------------------------------------------------
# Main Executable
# ------------------------------------------------------------
add_executable(
    DSLibrary
    main.cpp
)

target_include_directories(
    DSLibrary
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# ------------------------------------------------------------
# Test Executable
# ------------------------------------------------------------
add_executable(
    runTests
     
    tests/test_main.cpp
    tests/test_vector.cpp
    tests/test_vector/test_vector_constructor.cpp
    tests/test_vector/test_vector_push_back.cpp
    tests/test_vector/test_vector_pop_back.cpp
    tests/test_vector/test_vector_size.cpp
    tests/test_vector/test_vector_capacity.cpp
    tests/test_vector/test_vector_isempty.cpp
    tests/test_vector/test_vector_operator_index.cpp
    tests/test_vector/test_vector_assignment.cpp
    tests/test_vector/test_vector_copy_constructor.cpp
    tests/test_linkedlist/test_linkedlist_constructor.cpp
tests/test_linkedlist/test_linkedlist_push.cpp
tests/test_linkedlist/test_linkedlist_pop.cpp
tests/test_linkedlist/test_linkedlist_delete_any.cpp
tests/test_linkedlist/test_linkedlist_size.cpp
tests/test_linkedlist/test_linkedlist_isempty.cpp
tests/test_linkedlist/test_linkedlist_operator_index.cpp
tests/test_linkedlist/test_linkedlist_copy_constructor.cpp
tests/test_linkedlist/test_linkedlist_assignment.cpp
tests/test_linkedlist/test_linkedlist_userdefined.cpp
tests/test_vector/test_vector_userdefined.cpp
tests/test_hashmap/test_hash.cpp
tests/test_hashmap/test_constructor.cpp
tests/test_hashmap/test_copy_constructor.cpp
tests/test_hashmap/test_assignment.cpp
tests/test_hashmap/test_push.cpp
tests/test_hashmap/test_find.cpp
tests/test_hashmap/test_pop.cpp
tests/test_hashmap/test_operator_brackets.cpp
tests/test_hashmap/test_keys.cpp
tests/test_hashmap/test_rehash.cpp
tests/test_hashmap/test_userdefined.cpp
tests/redis_lite/test_del.cpp                    
tests/redis_lite/test_keys1.cpp                   
tests/redis_lite/test_set_get.cpp
tests/redis_lite/test_exists.cpp                 
# tests/redis_lite/test_process_command.cpp        
tests/redis_lite/test_size.cpp
)

target_include_directories(
    runTests
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    runTests
    PRIVATE
    GTest::gtest
    GTest::gtest_main
)
target_compile_options(DSLibrary PRIVATE
    -fsanitize=address
    -fno-omit-frame-pointer
    -g
)

target_link_options(DSLibrary PRIVATE
    -fsanitize=address
)

target_compile_options(runTests PRIVATE
    -fsanitize=address
    -fno-omit-frame-pointer
    -g
)

target_link_options(runTests PRIVATE
    -fsanitize=address
)

include(GoogleTest)
gtest_discover_tests(runTests)
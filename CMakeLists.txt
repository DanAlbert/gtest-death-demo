# You can ignore this file. demo_test.cpp is the interesting one.

cmake_minimum_required(VERSION 3.22)
project(GTestDeathDemo CXX)

# Ignore this. In Android this is dealt with by build.gradle depedencies and
# find_package. This isn't even a very good way to do this IMO.
# https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

# Also not relevant for androidx.
enable_testing()

# In androidx you'd use add_library rather than add_executable.
add_executable(demo_test demo_test.cpp)
target_compile_features(demo_test PRIVATE cxx_std_17)

# In androidx you'd use googletest::gtest rather than gtest_main.
target_link_libraries(demo_test PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(demo_test)
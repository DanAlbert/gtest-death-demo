#include <stdlib.h>

#include <variant>

#include <gtest/gtest.h>

// This API doesn't use exceptions, so fatal errors are handled by aborting
// internally. This is how the result type works when it's built in the
// platform because libbase does not use exceptions. std::variant prefers to
// throw exceptions on failure because that's how the C++ standard is written,
// but for clients that disable exceptions (like libbase), bad variant access
// will abort rather than throw.
void api_that_fails_by_aborting() {
    abort();
}

// This API *does* use exceptions, so it signals fatal errors by throwing. This
// is the default behavior for std::variant, so when exceptions are enabled
// (which is the default in androidx), bad variant access will throw rather
// than abort.
void api_that_fails_by_throwing_an_exception() {
    throw std::bad_variant_access();
}

// This test is like the one that was written in libbase, and it works because
// the API being called will abort rather than throw, which is what death tests
// are for. This test will pass.
TEST(DemoTest, DeathTest) {
    ASSERT_DEATH(api_that_fails_by_aborting(), "");
}

// This test is like the one that's in androidx. This test will fail because
// the API is throwing an exception rather than aborting. GTest's docs say that
// exceptions should be tested using ASSERT_THROW.
//
// This test will fail. Fix it by using ASSERT_THROW instead of ASSERT_DEATH.
TEST(DemoTest, ThrowingTest) {
    ASSERT_DEATH(api_that_fails_by_throwing_an_exception(), "");
}
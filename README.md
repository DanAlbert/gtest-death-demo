# GTest Death Demo

This demo shows the two different types of failure tests in gtest:
[death tests] and [exception assertions]. Death tests are used to write tests
which expect a crash, **but not tests that expect to be terminated with an
uncaught exception**. Tests that expect the code to throw an exception which is
not caught should use expected failure tests.

[death tests]: https://github.com/google/googletest/blob/main/docs/advanced.md#death-tests
[exception assertions]: https://github.com/google/googletest/blob/main/docs/reference/assertions.md#exception-assertions-exceptions

To set up the build (you only need to run this the first time):

```bash
cmake -S . -B build
```

To build:

```
cmake --build build
```

To run the tests:

```
build/demo_test
```
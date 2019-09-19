/**
 * Define local test runners here and call them
 * in test_runner.cpp
 *
 * This is quite annoying but platformio by default
 * tries to link all sources in the test folder and subfolders
 * into one binary. So I can't have unique tests with their workflow.
 */

void runner_attiny_header(void);
void runner_common_ops(void);
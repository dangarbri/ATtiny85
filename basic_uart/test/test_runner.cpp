/**
 * Because my tests can't each have their own runner by default...
 */

#include <unity.h>
#include "test_runner.h"

int main()
{
    UNITY_BEGIN();
    runner_attiny_header();
    runner_common_ops();
    UNITY_END();
}
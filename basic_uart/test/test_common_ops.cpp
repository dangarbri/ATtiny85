#include <stdint.h>
#include <unity.h>
#include "common_ops.h"

void test_SET_LOW(void)
{
    struct {
        uint8_t data;
        uint8_t bit; // 0 based
        uint8_t expected;
    } test_cases[] = {
        {0xFF, 0, 0xFE},
        {0x00, 1, 0x00},
        {0xFF, 1, 0xFD},
        {0x12, 4, 0x02}
    };

    for (uint8_t i = 0; i < ARRAY_SIZE(test_cases); i++)
    {
        TEST_ASSERT_EQUAL_HEX(test_cases[i].expected,
                        SET_LOW(test_cases[i].data, test_cases[i].bit));
    }
}

void test_SET_BIT(void)
{
    struct {
        uint8_t data;
        uint8_t bit;   // 0 based
        uint8_t value; // 0 or 1
        uint8_t expected;
    } test_cases[] = {
        {0xFF, 0, 0, 0xFE},
        {0x00, 1, 0, 0x00},
        {0xFF, 1, 0, 0xFD},
        {0x12, 4, 0, 0x02},
        {0x12, 0, 1, 0x13},
        {0x0F, 4, 1, 0x1F},
        {0x1F, 5, 1, 0x3F},
        {0x0F, 5, 1, 0x2F},
    };

    for (uint8_t i = 0; i < ARRAY_SIZE(test_cases); i++)
    {
        TEST_ASSERT_EQUAL_HEX(test_cases[i].expected,
                              SET_BIT(test_cases[i].data,
                                    test_cases[i].bit,
                                    test_cases[i].value));
    }
}

void runner_common_ops(void)
{
    RUN_TEST(test_SET_LOW);
    RUN_TEST(test_SET_BIT);
}
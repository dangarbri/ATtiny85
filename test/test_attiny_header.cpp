#include <stdint.h>
#include <unity.h>
#include "common_ops.h"
#include "my_attiny85.h"

void test_toggle_pin(void) {
    struct TestCase {
        uint8_t port_val;
        uint8_t pin;
        uint8_t expected_val;
    };

    struct TestCase test_cases[] = {
        // Test cases to set all pins low and high individually
        {0xFF, PIN0, 0xFE},
        {0xFE, PIN0, 0xFF},
        {0xFF, PIN1, 0xFD},
        {0xFD, PIN1, 0xFF},
        {0xFF, PIN2, 0xFB},
        {0xFB, PIN2, 0xFF},
        {0xFF, PIN3, 0xF7},
        {0xF7, PIN3, 0xFF},
        {0xFF, PIN4, 0xEF},
        {0xEF, PIN4, 0xFF},
        {0xFF, PIN5, 0xDF},
        {0xDF, PIN5, 0xFF},
        // and a case for setting a pin with all other bits at 0
        {0x00, PIN0, PIN0}
    };

    for (int i = 0; i < ARRAY_SIZE(test_cases); i++)
    {
        struct TestCase test = test_cases[i];
        uint8_t toggled_val = TOGGLE_PORT_PIN(test.port_val, test.pin);
        TEST_ASSERT_EQUAL(test.expected_val, toggled_val);
    }
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_toggle_pin);
    UNITY_END();
}
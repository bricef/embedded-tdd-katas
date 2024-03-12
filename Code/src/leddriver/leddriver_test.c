#include "unity.h"
#include "leddriver.h"

#ifdef BUILD_LOCAL
    #include "mock-pico.h"
#else
    #include "pico/stdlib.h"
#endif

/*
 * Test your LED driver in this file.
 */

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void we_can_write_passing_tests(void){
    TEST_ASSERT_EQUAL(1, 1);
}

void all_leds_are_off_after_driver_is_initialised(void){
    TEST_FAIL_MESSAGE("Start Here");
}

int main(void){
    stdio_init_all();
    UNITY_BEGIN();
    RUN_TEST(we_can_write_passing_tests);
    RUN_TEST(all_leds_are_off_after_driver_is_initialised);
    return UNITY_END();
}
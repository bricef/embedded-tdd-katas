#include "unity.h"
#include "leddriver.h"

#ifdef BUILD_LOCAL
    #include "mock-pico.h"
#else
    #include "pico/stdlib.h"
#endif

#define IS_OK 0
#define IS_NOT_OK 1

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_unity_run(void){
    TEST_ASSERT_EQUAL(1, 1);
}

void test_led_init(void){
    int return_code = LedDriver_init();
    TEST_ASSERT_EQUAL(IS_OK, return_code);
}

int main(void){
    stdio_init_all();
    UNITY_BEGIN();
    RUN_TEST(test_unity_run);
    RUN_TEST(test_led_init);
    return UNITY_END();
}
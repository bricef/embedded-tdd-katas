#include "unity.h"

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

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_unity_run);
    return UNITY_END();
}
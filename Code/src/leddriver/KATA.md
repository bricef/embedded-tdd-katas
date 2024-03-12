# LED Driver Kata

## Introduction

In this kata, you will be creating a hardware driver for an LED array designed to run on the Raspberry Pi Pico Microcontroller.

## The LED Driver Requirement

### Getting started

The driver should be initialised with a memory address pointing to a 16 bit wide unsigned integer (a `uint16_t` type) which represents an array of 16 LEDs, where a bit is 1 if the corresponding LED is on and 0 if the corresponding LED is OFF.

As part of its specification, the LED Driver shoould comply with the follwoing requirements:

1. All LEDs are OFF after the driver is initialized.
2. A single LED can be turned ON.
3. A single LED can be turned OFF.
4. Multiple LEDs can be turned ON/OFF.
5. All LEDs can be turned ON simultaneously.
6. All LEDs can be turned OFF simultaneously.
7. We can query the state of a given LED.
8. It is an error to attempt to write to an LED outside of the 0-15 range.
9. It is an error to attempt to initialised the driver with a null or zero memory address.

To get you started, a failing test has been create in `leddriver_test.c`. You can refer to [The Code Readme](../README.md) for how to compile and test your code locally and in the emulator.

### Going Further

Now that you have an LED Driver, it's time to expand its functionality to accept arbitrary length LED arrays. The number of LEDs your driver should support can now be defined at initialisation, and this the driver should be able to handle LED arrays that are not multiple of 8, using a raw pointer to a memory location, whislt still guaranteeing that it will not overwrite values outside of its bounds. 

For example (your code might look different):

```C
void* LED_ARRAY_LOCATION = /*...*/;
int NUM_LEDS = 12;

// set up your LED Driver
struct* driver = led_driver_initialise(LED_ARRAY_LOCATION, NUM_LEDS);

// Switch an LED ON
bool is_success_a = leddriver_on(driver, 3); // turns fourth LED of array on
TEST_ASSERT_TRUE(is_success_a);

bool is_success_b = leddriver_on(driver, 12); // fails to perform operation due to being out-of-bounds.
TEST_ASSERT_FALSE(is_success_b);
```

### Final steps

Now that you are able to manage an LED array with an arbitrary number of LEDs, refactor your code to manage an arbitrary number of LEDs but with a starting offset from the address provided to your driver. For example: 

```C
uint32_t VIRTUAL_LEDS = 0xffffffff;
int NUM_LEDS = 8;
int ADDRESS_OFFSET_LSB = 3;

struct* driver = led_driver_initialise(
    &VIRTUAL_LEDS, // The address of the memopry mapped LED array
    NUM_LEDS, // The number of LEDs to manage
    ADDRESS_OFFSET // How many biots to ignore at the start
);

bool is_success = leddriver_on(driver, 0); 

TEST_ASSERT_TRUE(is_success)
TEST_ASSERT_EQUAL_UINT32(0x00000004, VIRTUAL_LEDS);
```


## The Unity test framework

You can find a cheatsheet to the unity assertions [at the unity repository](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsCheatSheetSuitableforPrintingandPossiblyFraming.pdf).

## Your TDD cycles

![](../../../Talk/assets/tdd-cycles.png)

Remember the sequence for your embedded TDD cycles, run through the loops a few times to get used to this way of working.




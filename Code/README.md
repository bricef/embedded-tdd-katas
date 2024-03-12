# Code for 'Embedded TDD'

## Reference

- [Getting started with Raspberry Pi Pico (PDF)](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)

## Setting up 

A quick start script is included to get started which will set up the subdirectories and check for dependencies.

```
$ ./setup.sh
```

You will need the following tools on your `PATH`:

- `git`
- `cmake`
- `gcc-arm-none-eabi`
- `node`


## Building and testing locally 

You can build using the provided makefile:

```shell
$ make 
$ make test-all
```

## Building for the target (RP2040)

You can build for the target by going into the `build-pico` dircetory:

```shell
$ cd build-pico
$ make leddriver_test
```

The output will then be created in the `build-pico/src/leddriver/` directory.

## Running the emulator

Once a local build has been created, you can run the build in the emulator by providing the packaged `.hex` file to the simulator script:

```shell
$ ./simulate.sh build-pico/src/leddriver/leddriver_test.hex
```

This will run your code in an [RP2040 emulator written in Javascript](https://github.com/wokwi/rp2040js).

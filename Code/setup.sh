#!/bin/sh


function check_deps {
    # Check for cmake
    if ! [ -x "$(command -v cmake)" ]; then
        echo 'Error: cmake is not installed.' >&2
        exit 1
    fi

    # Check for git
    if ! [ -x "$(command -v git)" ]; then
        echo 'Error: git is not installed.' >&2
        exit 1
    fi

    # Check for gcc-arm-none-eabi
    if ! [ -x "$(command -v arm-none-eabi-gcc)" ]; then
        echo 'Error: gcc-arm-none-eabi is not installed.' >&2
        exit 1
    fi

}


function setup {
    # Make the build directory if id doesn't exist
    mkdir -p build

    # Set up the Pico C SDK
    git submodule update --init

    # Set up the Pico SDK submodules
    cd pico-sdk
    git submodule update --init

    # We should now be ready to build.
    # run cmake
    cd ..
    cd build
    cmake ..

    # Ready for development 
    echo "Setup complete. Ready for development."
}

check_deps && setup
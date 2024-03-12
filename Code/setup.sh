#!/bin/bash


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

    if ! [ -x "$(command -v node)" ]; then
        echo 'Error: node is not installed.' >&2
        exit 1
    fi

}


function setup {
    # Make the build directory if id doesn't exist
    mkdir -p build-pico
    mkdir -p build-local

    # Set up the Pico C SDK
    git submodule update --init

    # Set up the Pico SDK submodules
    cd libs/pico-sdk
    git submodule update --init

    # Set up the seimulator dependencies
    npm install

    # We should now be ready to build.
    # run cmake for the pico SDK
    cd ../../build-pico
    cmake ..

    # Ready for development 
    echo "Setup complete. Ready for development."
}

check_deps && setup
if (TARGET tinyusb_device)
    add_executable(hello hello.c)

    # pull in common dependencies
    target_link_libraries(hello pico_stdlib)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(hello 0)
    pico_enable_stdio_uart(hello 1)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(hello)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello because TinyUSB submodule is not initialized in the SDK")
endif()
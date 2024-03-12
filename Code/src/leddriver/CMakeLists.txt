if (TARGET tinyusb_device)
    add_library(leddriver leddriver.c)
    target_link_libraries(leddriver pico_stdlib)
    target_link_libraries(leddriver unity)
    
    add_executable(leddriver_test leddriver_test.c)
    target_link_libraries(leddriver_test leddriver unity)

    add_executable(leddriver_main leddriver_main.c)
    target_link_libraries(leddriver_main leddriver)

    
    # enable usb output, disable uart output
    pico_enable_stdio_usb(leddriver 1)
    # pico_enable_stdio_uart(leddriver 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(leddriver_main)
    pico_add_extra_outputs(leddriver_test)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building leddriver because TinyUSB submodule is not initialized in the SDK")
endif()
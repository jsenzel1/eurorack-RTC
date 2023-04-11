# Install script for directory: /Users/jonah/pico/pico-sdk/src/rp2_common

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/opt/homebrew/bin/arm-none-eabi-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_base/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_claim/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_adc/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_clocks/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_dma/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_divider/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_exception/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_flash/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_gpio/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_i2c/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_interp/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_irq/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_pio/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_pll/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_pwm/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_resets/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_rtc/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_spi/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_sync/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_timer/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_uart/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_vreg/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_watchdog/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/hardware_xosc/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_bootrom/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_platform/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/boot_stage2/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_bootsel_via_double_reset/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_multicore/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_unique_id/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_bit_ops/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_divider/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_double/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_int64_ops/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_float/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_mem_ops/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_malloc/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_printf/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_stdio/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_stdio_semihosting/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_stdio_uart/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/cmsis/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/tinyusb/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_stdio_usb/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/cyw43_driver/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_lwip/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_cyw43_arch/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_stdlib/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_cxx_options/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_standard_link/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_fix/cmake_install.cmake")
  include("/Users/jonah/pico/pcbrock/firm-1.0.0/build/pico-sdk/src/rp2_common/pico_runtime/cmake_install.cmake")

endif()

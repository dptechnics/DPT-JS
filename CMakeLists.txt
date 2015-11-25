cmake_minimum_required(VERSION 2.8.9)

project (dpt-js)

include(duktape.cmake)
include(uv.cmake)

add_library(dptjs
  src/dptjs.c
  src/refs.c
  src/utils.c
  src/loop.c
  src/req.c
  src/handle.c
  src/timer.c
  src/stream.c
  src/tcp.c
  src/pipe.c
  src/tty.c
  src/fs.c
  src/misc.c
  src/utils.c
  src/uv_schema.c
  src/callbacks.c
  src/miniz.c
)

add_library(dschema
  src/schema.c
)

SET(SOURCES
    src/main.c
    
    src/dptfunctions/gpio/dpt_gpio.c

    src/dptfunctions/i2c/dpt_i2c.c

    src/dptfunctions/serial/dpt_serial.c
)

add_executable(dpt-js ${SOURCES})

FIND_LIBRARY(libpthread NAMES pthread libpthread)

TARGET_LINK_LIBRARIES(dpt-js dptjs dschema duktape uv ${libpthread})

INSTALL(TARGETS dpt-js
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
)

# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/mqtt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/mqtt_autogen.dir/ParseCache.txt"
  "mqtt_autogen"
  )
endif()

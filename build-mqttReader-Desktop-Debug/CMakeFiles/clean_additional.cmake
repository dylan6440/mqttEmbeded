# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/mqttReader_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/mqttReader_autogen.dir/ParseCache.txt"
  "mqttReader_autogen"
  )
endif()

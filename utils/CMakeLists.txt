add_library(Utils STATIC
${CMAKE_CURRENT_SOURCE_DIR}/io.cpp
${CMAKE_CURRENT_SOURCE_DIR}/process_input.cpp
)

target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

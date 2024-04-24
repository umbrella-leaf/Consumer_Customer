get_filename_component(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)

aux_source_directory(${SRC_DIR} SRC_LIST)

set(src ${SRC_LIST} CACHE INTERNAL "src files list")

add_library(consumer consumer.cpp)
add_library(productor productor.cpp)

add_executable(consumer_productor main.cpp)
target_link_libraries(consumer_productor consumer productor)
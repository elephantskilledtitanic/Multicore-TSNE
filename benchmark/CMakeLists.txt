PROJECT(tsne_multicore_benchmark CXX)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)
CMAKE_POLICY(VERSION 2.8)

SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
SET(CMAKE_EXE_LINKER_FLAGS "-lm")

IF(MSVC)
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /fp:fast /O2")
ELSE()
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -fPIC -ffast-math -funroll-loops")
ENDIF()

find_library(TSNE_LIB
    NAMES tsne_multicore
    HINTS "${CMAKE_CURRENT_SOURCE_DIR}/../multicore_tsne/cmake"
)

add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark ${TSNE_LIB})
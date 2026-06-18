cmake_minimum_required(VERSION 3.17.0)
project(homey-perception LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include(FetchContent)

message("Fetching libtorch...")
FetchContent_Declare(
    Torch
    URL https://download.pytorch.org/libtorch/cu130/libtorch-shared-with-deps-2.12.0%2Bcu130.zip
    URL_HASH SHA256=a337e59b671d31c10e415e0435e8a4f2ce30ed84e96e47fb8d380c970c45db12  # guarantees reproducibility
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(Torch)
message("${torch_SOURCE_DIR}")
list(APPEND CMAKE_PREFIX_PATH "${torch_SOURCE_DIR}")

find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)
find_package(realsense2 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Torch REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_subdirectory(src)

option(BUILD_TESTING "Build tests" ON)

if (BUILD_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()

# add_executable(homey-perception
#   src/main.cpp
# )

# target_link_libraries(homey-perception PRIVATE opencv_core)

# include(CTest)

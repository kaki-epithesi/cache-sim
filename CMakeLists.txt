cmake_minimum_required(VERSION 3.20)
project(cache_sim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# Set path for brew-installed packages (Google Benchmark)
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/benchmark")
find_package(benchmark REQUIRED)

# Add include and lib dirs for Homebrew
include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

# Source files
file(GLOB SRC "src/*.cpp")

# Define executable only once
add_executable(sim ${SRC})

# Link necessary libraries
target_link_libraries(sim PRIVATE benchmark::benchmark pthread)

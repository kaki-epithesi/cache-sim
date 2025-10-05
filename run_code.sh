#!/bin/zsh

cmake -S . -B build -G Ninja
cmake --build build

./build/sim

rm -rf build
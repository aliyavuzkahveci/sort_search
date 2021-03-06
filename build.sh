#!/bin/bash

# removing previously built binary
rm sort_search

# cleaning old build
rm -rf build/

# creating build folder
mkdir build

cd build/

# preparation of Makefile
cmake ..

# compile & build
make

# copying the binary to the rott project folder
cp sort_search ../

# starting binary
./sort_search

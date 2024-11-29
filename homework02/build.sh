#!/bin/bash

# Exit on error
set -e

# Clean the build directory every time
echo "Cleaning build directory..."
rm -rf build/*
echo "Cleaned build directory."

# Default to Debug build if no argument is given
BUILD_TYPE=${1:-Debug}  # Accepts Debug or Release as the first argument

# Create the build directory if it doesn't exist
if [ ! -d "build" ]; then
  mkdir build
fi

# Navigate to the build directory
cd build

# Run cmake with the specified build type (Debug/Release)
echo "Configuring with build type $BUILD_TYPE"
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE ..

# Build the project using MSBuild
echo "Building the project..."
cmake --build . --config $BUILD_TYPE

# Find the directory containing the executables (either Debug or Release)
if [ -d "Debug" ]; then
    TARGET_DIR="Debug"
elif [ -d "Release" ]; then
    TARGET_DIR="Release"
else
    echo "No Debug or Release directory found. Exiting."
    exit 1
fi

# Navigate to the target directory (Debug/Release)
cd "$TARGET_DIR"

# Run the executables (Check exit status)
./Question1.exe
./Question2.exe
./Question3.exe
./Question4_part1.exe
./Question4_part2.exe
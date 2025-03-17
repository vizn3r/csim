#!/bin/bash

# Set build directory
BUILD_DIR="build"

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
  mkdir "$BUILD_DIR"
fi

# Navigate to the build directory
cd "$BUILD_DIR" || exit 1

# Run CMake and Make
cmake ..
if make; then
  echo "Build successful!"
else
  echo "Build failed!"
  exit 1
fi

#!/bin/sh

set -e

echo "Building..."
if (g++ main.cpp -o asciipp `pkg-config --cflags --libs opencv4`); then
    echo "Great success!"
    echo "Usage: ./asciipp <path-of-image> [width | default = 100]"
else
    echo "Error while compiling."
fi
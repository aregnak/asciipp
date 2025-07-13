#!/bin/sh

set -e

echo "Building..."
if (g++ src/main.cpp -o asciipp `pkg-config --cflags --libs opencv4`); then
    echo "Great success!"
    echo -e "\nUsage: ./asciipp <path-of-image>"
    echo -e "\nOptions:"
    echo "  -w <width>    Output width, default is 100"
    echo "  -i            Invert characterset"
else
    echo "Error while compiling."
fi
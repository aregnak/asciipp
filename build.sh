#!/bin/sh

set -e

echo "Building..."
if (g++ main.cpp -o asciipp `pkg-config --cflags --libs opencv4`); then
    echo "Great success!"
    echo "Run with './asciipp <image>'"
else
    echo "Error while compiling."
fi
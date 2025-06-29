# ASCIIPP ASCII ART GENERATOR 

## Description

This CLI program will create ASCII art from a given image.

### Usage
`./asciipp <path-of-image> [width | default = 100]`

There are a few sample images in the Samples folder for quick testing.

## Installation
For now, you need to manually build it to install it.

### Dependencies
[OpenCV](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html)

### Building
Using shell build script (linux):
```shell
./build.sh
```
Using CMake (linux & windows):
```shell
mkdir -p build && cd build
cmake ..
make
```

## Thank you!
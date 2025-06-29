#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

#include "art.h"

int main(int argc, char** argv)
{
    if (argc != 2) 
    {
        std::cerr << "usage: ./asciipp <path-of-image>" << std::endl;
        return -1;
    }

    // Read image from command-line
    cv::Mat image = cv::imread(argv[1], 1);
    if (!image.data) 
    {
        std::cerr << "No image data." << std::endl;
        return -1;
    }

    Art art(image);

    return 0;
}
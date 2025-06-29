#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

#include "art.h"

int main(int argc, char** argv)
{
    if (argc < 2 || argc > 3) 
    {
        std::cerr << "usage: ./asciipp <path-of-image> [width | default = 100]" << std::endl;
        return -1;
    }

    // Read image from command-line
    cv::Mat image = cv::imread(argv[1], 1);
    if (!image.data) 
    {
        std::cerr << "No image data." << std::endl;
        return -1;
    }

    if (argc == 3)
    {
        int outputWidth = std::stoi(argv[2]);
        if (outputWidth)
        {
            Art art(image, outputWidth);
        }
        else 
        {
            std::cerr << "usage: ./asciipp <path-of-image> [width | default = 100]" << std::endl;
            return -1;
        }
    }
    else 
    {
        Art art(image, 100);
    }

    return 0;
}
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <stdexcept>
#include <iostream>

#include "art.h"

int main(int argc, char** argv)
{
    try 
    {
        if (argc < 2 || argc > 3) 
        {
            throw std::runtime_error("usage: ./asciipp <path-of-image> [width | default = 100]");
        }

        // Read image from command-line
        cv::Mat image = cv::imread(argv[1], 1);
        if (!image.data) 
        {
            std::cerr << "No image data." << std::endl;
            throw std::runtime_error("Error: No image data.");
        }
        
        // Default output width
        int outputWidth = 100;
        if (argc == 3)
        {
            if (!std::stoi(argv[2]))
            {
                throw std::runtime_error("Error: Width must be a positive integer.");
            }

            outputWidth = std::stoi(argv[2]);
        }
        Art art(image, outputWidth);

        return 0;
    }

    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
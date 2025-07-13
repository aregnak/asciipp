#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <stdexcept>
#include <iostream>

#include "art.h"

std::string helpMessage = "Usage: ./asciipp <path-of-image>\n  -w <width>   Output width, default is 100\n  -i           Invert characterset";

int main(int argc, char** argv)
{
    try 
    {
        if (argc < 2) 
        {
            throw std::runtime_error(helpMessage);
        }

        // Read image from command-line
        cv::Mat image = cv::imread(argv[1], 1);
        if (!image.data) 
        {
            std::cerr << "No image data." << std::endl;
            throw std::runtime_error("Error: No image data.");
        }
        
        // Defaults 
        int outputWidth = 100;
        bool inverted = false;

        // Option checking
        for(int i = 2; i < argc; ++i)
        {
            std::string argvStr = argv[i];

            if (argvStr.find('-') != std::string::npos)
            {
                // Check for width
                if (argvStr == std::string_view("-w"))
                {
                    int widthBuffer = std::stoi(argv[i+1]);
                    if (widthBuffer < 1)
                    {
                        throw std::runtime_error("Error: Width must be a positive integer.");
                    }
                    outputWidth = widthBuffer;
                    
                    i++;
                }

                // Check for inverted characterset
                else if (argvStr == std::string_view("-i"))
                {
                   inverted = true; 
                }
            }
            else
            {
                throw std::runtime_error("Bad argument.");
            }

        }

        Art art(image, outputWidth, inverted);

        return 0;
    }

    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
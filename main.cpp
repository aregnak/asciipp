#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

#include "art.h"

bool isInt(const std::string& str)
{
    try 
    {
        size_t pos;
        unsigned long value = std::stoul(str, &pos);
        return pos == str.size();

        } catch (const std::invalid_argument& e) {
            return false;
        } catch (const std::out_of_range& e) {
            return false;
    }
}


int main(int argc, char** argv)
{
    if (argc >= 2 && argc < 4) 
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
        if (isInt(argv[2]))
        {
            int outputWidth = std::stoi(argv[2]);
            Art art(image, outputWidth);
        }
    }
    else 
    {
        Art art(image, 100);
    }

    return 0;
}
#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

class Art
{
public:
    Art(cv::Mat image, int outputWidth)
    : aspectRatio(0.5)
    , outputHeight((image.rows * outputWidth * aspectRatio) / image.cols)
    {
        cv::cvtColor(image, image, cv::COLOR_RGB2GRAY);

        for (int y = 0; y < image.rows; ++y) 
        {
            for (int x = 0; x < image.cols; ++x) 
            {
            }
        }

    }

    

private:
    std::vector<std::vector<char>> asciiart;

    std::string chars = "$@#%/~-. ";

    float aspectRatio;
    int outputHeight;
};
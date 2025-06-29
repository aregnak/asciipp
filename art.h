#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

class Art
{
public:
    Art(cv::Mat image, int outputWidth)
    : aspectRatio(0.5) // Play with this for different output sizes
    , outputHeight((image.rows * outputWidth * aspectRatio) / image.cols)
    {
        // Convert to grayscale and resize
        cv::cvtColor(image, image, cv::COLOR_RGB2GRAY);
        cv::resize(image, image, cv::Size(outputWidth, outputHeight));

        asciiArt.resize(image.rows , std::vector<char>(image.cols));

        // Now using resized rows and cols
        for (int y = 0; y < image.rows; ++y) 
        {
            for (int x = 0; x < image.cols; ++x) 
            {
                uchar pixel = image.at<uchar>(y, x); // 0-255
                int index = static_cast<int>((pixel / 255.0) * (chars.size()));
                asciiArt[y][x] = chars[index]; 
                if (x == 0)
                {
                    std::cout << std::endl << chars[index];
                }
                else 
                {
                    std::cout << chars[index];
                }
            }
        }
    }

private:
    std::vector<std::vector<char>> asciiArt;

    std::string chars = "$@#%/~-. ";

    float aspectRatio;
    int outputHeight;
};
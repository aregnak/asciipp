#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

class Art
{
public:
    Art(cv::Mat image)
    : aspectRatio(static_cast<float>(image.cols) / image.rows) // Play with this for different output sizes
    , outputWidth(150)
    , outputHeight(static_cast<int>(outputWidth / aspectRatio * 0.5f))
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

    /* Uncomment the line below if you want shadows to have
    the most brightness in ASCII*/
    // std::string chars = "@%#*+=-:. ";

    /* Uncomment the line below if you want shadows to have
    the least brightness in ASCII*/
    std::string chars = " .:-=+*#%@";

    float aspectRatio;
    int outputWidth;
    int outputHeight;
};
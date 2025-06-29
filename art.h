#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

class Art
{
public:
    Art(cv::Mat image, int outputWidth)
    : _aspectRatio(static_cast<float>(image.cols) / image.rows) // Play with this for different output sizes
    , _outputWidth(outputWidth)
    , _outputHeight(static_cast<int>(_outputWidth / _aspectRatio * 0.5f))
    {
        // Convert to grayscale and resize
        cv::cvtColor(image, image, cv::COLOR_RGB2GRAY);
        cv::resize(image, image, cv::Size(_outputWidth, _outputHeight));

        // Now using resized rows and cols
        for (int y = 0; y < image.rows; ++y) 
        {
            for (int x = 0; x < image.cols; ++x) 
            {
                uchar pixel = image.at<uchar>(y, x); // 0-255
                int index = static_cast<int>((pixel / 255.0) * (chars.size()));
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
    /* Uncomment the line below if you want shadows to have
    the most brightness in ASCII*/
    // std::string chars = "@%#*+=-:. ";

    /* Uncomment the line below if you want shadows to have
    the least brightness in ASCII*/
    std::string chars = " .:-=+*#%@";

    float _aspectRatio;
    int _outputWidth;
    int _outputHeight;
};
#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

class Art
{
public:
    Art(cv::Mat image, int outputWidth, bool inverted)
    : _aspectRatio(static_cast<float>(image.cols) / image.rows)
    , _outputHeight(static_cast<int>(outputWidth / _aspectRatio * 0.5f))
    {
        // Convert to grayscale and resize
        cv::cvtColor(image, image, cv::COLOR_RGB2GRAY);
        cv::resize(image, image, cv::Size(outputWidth, _outputHeight));

        if (inverted)
        {
            chars = " .:-=+*#%@";
        }

        // Now using resized rows and cols
        for (int y = 0; y < image.rows; ++y) 
        {
            for (int x = 0; x < image.cols; ++x) 
            {
                // Check each pixel's brightness
                uchar pixel = image.at<uchar>(y, x); // 0-255
                int index = static_cast<int>((pixel / 255.0) * (chars.size()));

                // Newline if on new column
                if (x == 0)
                {
                    std::cout << std::endl;
                }
                std::cout << chars[index];
            }
        }
    }

private:
    std::string chars = "@%#*+=-:. ";

    float _aspectRatio;
    int _outputHeight;
};
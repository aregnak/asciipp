#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

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

    cv::Mat gray;
    cv::cvtColor(image, image, cv::COLOR_RGB2GRAY);

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display Image", image);
    cv::waitKey(0);
    return 0;
}
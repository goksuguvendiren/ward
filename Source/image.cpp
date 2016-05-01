#include "../Header/image.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

Image::Image(const string& path)
{
    _path = path;
    _pixels = imread(path, CV_LOAD_IMAGE_COLOR);
    cv::cvtColor(_pixels, _pixels, CV_BGR2GRAY);

    //namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    //imshow( "Display window", _pixels);

    _width = _pixels.size().width;
    _height = _pixels.size().height;

    CalculateMedian();
}

Image Image::Shrink() const
{
    Image im(_path);
    Size size(_width/2, _height/2);
    resize(_pixels, im._pixels, size); //resize image

    im._width /= 2;
    im._height /= 2;

    im.CalculateMedian();

    return im;
}

void Image::CalculateMedian()
{
    vector<int> medVec;
    for (int i = 0; i < _height; i++){
        for (int j = 0; j < _width; j++){
            medVec.push_back(_pixels.at<uchar>(i, j));
        }
    }

    nth_element(medVec.begin(), medVec.begin() + medVec.size() / 2, medVec.end());
    _medianValue = medVec[medVec.size() / 2];
}
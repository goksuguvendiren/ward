#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <string>
#include <opencv2/core/core.hpp>
#include "aoa_jpeg.h"

using namespace std;
using namespace cv;

class Image
{
private:
	int _width, _height;
	float _exposureTime;
	float _medianValue;

	Mat _pixels;

	void prepare();
	string _path;

public:
	Image(const string& path);

	Image Shrink() const;
    float Med() const { return _medianValue; }

	uchar Value(int i, int j) const { return _pixels.at<uchar>(i, j); }
	int Width() const { return _width; }
	int Height() const { return _height; }
    void CalculateMedian();

	/*Pixel PixelAt(int i) const { return _realPixels[i]; };

	void Vectorize();
	int PixelNum() { return _width * _height; }

	float Exposure() { return _exposureTime; };
	void SetExposure(float x) { _exposureTime = x; }

	string getPath() const { return _path; }*/

};

#endif // __IMAGE_H__
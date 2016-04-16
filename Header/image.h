#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <string>
#include "aoa_jpeg.h"

using namespace std;

class Image
{
private:
	int _width, _height;
	float _exposureTime;
	float _medianValue;

	UCOLOR** _pixels;
	//vector<Pixel> _realPixels;
	//void loadRealPixels();
	void prepare();
	string _path;

public:
	Image(string& path);
	Image(const Image& rhs);
	Image& operator=(Image& rhs);
	~Image();

	void Shrink();
    float Med() const { return _medianValue; }

	float Green(int i, int j) const { return _pixels[i][j][1]; }
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
#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <string>
#include "aoa_jpeg.h"

using namespace std;

/*struct Pixel
{
	UCOLOR pixel;
	Pixel(const UCOLOR& p)
	{
		pixel[0] = p[0] * 255;
		pixel[1] = p[1] * 255;
		pixel[2] = p[2] * 255;
	}

	float operator[](int i) { return pixel[i]; }
};*/


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

	int Width() const { return _width; }
	int Height() const { return _height; }

	/*Pixel PixelAt(int i) const { return _realPixels[i]; };

	void Vectorize();
	int PixelNum() { return _width * _height; }

	float Exposure() { return _exposureTime; };
	void SetExposure(float x) { _exposureTime = x; }

	string getPath() const { return _path; }*/

};

#endif // __IMAGE_H__
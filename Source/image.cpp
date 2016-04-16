#include "../Header/image.h"
#include <iostream>

Image::Image(string& path)
{
	_path = path;

	read_jpeg_header(path.c_str(), &_width, &_height);
	prepare();
	read_jpeg(path.c_str(), _pixels, &_width, &_height, &_medianValue);

	std::cout << _medianValue << std::endl;
	std::cout << _medianValue / (_width * _height) << std::endl;
}

void Image::prepare()
{
	_pixels = new UCOLOR*[_height];
	for(int i = 0; i < _height; i++)
		_pixels[i] = new UCOLOR[_width];
}
Image::~Image()
{
	for (int i = 0; i < _height; i++){
		delete[] _pixels[i];
	}

	delete[] _pixels;
}

Image& Image::operator=(Image& rhs)
{
	if (this == &rhs) return *this;

	this->~Image();

	_width = rhs._width;
	_height = rhs._height;
	_exposureTime = rhs._exposureTime;
	_path = rhs._path;

	prepare();
	for (int i = 0; i < _height; i++){
		for (int j = 0; j < _width; j++){
			_pixels[i][j][0] = rhs._pixels[i][j][0];
			_pixels[i][j][1] = rhs._pixels[i][j][1];
			_pixels[i][j][2] = rhs._pixels[i][j][2];
		}
	}

	return *this;
}

Image::Image(const Image& rhs)
{
	_width = rhs._width;
	_height = rhs._height;
	_exposureTime = rhs._exposureTime;
	_path = rhs._path;

	prepare();
	for (int i = 0; i < _height; i++){
		for (int j = 0; j < _width; j++){
			_pixels[i][j][0] = rhs._pixels[i][j][0];
			_pixels[i][j][1] = rhs._pixels[i][j][1];
			_pixels[i][j][2] = rhs._pixels[i][j][2];
		}
	}
}
#include "../Header/image.h"

Image::Image(string& path)
{
	read_jpeg_header(path, _width, _height);
}
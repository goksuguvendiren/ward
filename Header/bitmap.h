#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <vector>
#include "image.h"

using std::vector;

class Bitmap
{
    int _width, _height;
    vector<bool> _bitmapImage;
public:
    Bitmap();
    void Compute();
};

#endif //__BITMAP_H__
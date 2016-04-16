#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <vector>
#include "image.h"

using std::vector;

class Bitmap
{
    int _width, _height;
    int _ones;
    vector<bool> _bitmapImage;
    UCOLOR** _bm;
public:
    Bitmap();
    void Compute(const Image& image);
    Bitmap XOR(const Bitmap& bitmap) const;
    int CountOnes() const;
};

#endif //__BITMAP_H__
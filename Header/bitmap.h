#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <vector>
#include "image.h"

using std::vector;

class Bitmap
{
    int _width, _height;
    int _ones;
    int _beginIndex;
public:
    vector<bool> _bitmapImage;

    Bitmap();

    int CountOnes() const;

    void Compute(const Image& image);
    void ComputeEx(const Image& image);
    Bitmap Shift(int x, int y);     // returns the shifted bitmap

    Bitmap XOR(const Bitmap& bitmap) const;
    Bitmap AND(const Bitmap& bitmap) const;
};

#endif //__BITMAP_H__
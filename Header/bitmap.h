#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <deque>
#include <vector>
#include "image.h"

using std::deque;

class Bitmap
{
    int _width, _height;
    int _ones;
    deque<bool> _bitmapImage;
    vector<bool> lel;
    UCOLOR** _bm;
public:

    Bitmap();

    int CountOnes() const;

    void Compute(const Image& image);
    void Shift(int x, int y);

    deque<bool>& BitmapImage() { return _bitmapImage; }

    Bitmap XOR(const Bitmap& bitmap) const;
    Bitmap AND(const Bitmap& bitmap) const;
};

#endif //__BITMAP_H__
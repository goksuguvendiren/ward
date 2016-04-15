#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <vector>

using std::vector;

class Bitmap
{
    vector<bool> _bitmapImage;
public:
    void Compute();
};

#endif //__BITMAP_H__
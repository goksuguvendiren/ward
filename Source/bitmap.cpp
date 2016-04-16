#include "../Header/bitmap.h"
#include <iostream>
#include "../Header/image.h"
#include "../Header/aoa_jpeg.h"

using namespace std;

Bitmap::Bitmap()
{
    _ones = 0;
}

Bitmap Bitmap::XOR(const Bitmap& bitmap) const
{
    Bitmap bm;
    bm._bitmapImage.resize(_width * _height);
    for (int i = 0; i < _bitmapImage.size(); i++){
        bm._bitmapImage[i] = _bitmapImage[i] ^ bitmap._bitmapImage[i];
        bm._ones += bm._bitmapImage[i];
    }

    int x = CountOnes();
    cout << _ones << endl;
    return bm;
}

int Bitmap::CountOnes() const
{
    return _ones;
}

void Bitmap::Compute(const Image& image)
{
    _width = image.Width();
    _height = image.Height();
    for(int i = 0; i < _height; i++){
        for(int j = 0; j < _width; j++){
            _bitmapImage.push_back(image.Green(i, j) > image.Med());
            _ones += image.Green(i, j) > image.Med() ? 1 : 0;
        }
    }

   // string path = "/home/goksu/Samples/output.jpg";
   // write_jpeg(path.c_str(), _bm, _width, _height);
}


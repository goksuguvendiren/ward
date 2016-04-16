#include "../Header/bitmap.h"
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

    return bm;
}

Bitmap Bitmap::AND(const Bitmap &bitmap) const
{
    Bitmap bm;
    bm._bitmapImage.resize(_width * _height);
    for (int i = 0; i < _bitmapImage.size(); i++){
        bm._bitmapImage[i] = _bitmapImage[i] & bitmap._bitmapImage[i];
        bm._ones += bm._bitmapImage[i];
    }

    return bm;
}

int Bitmap::CountOnes() const
{
    return _ones;
}

void Bitmap::Shift(int x, int y)
{
    _width = 10;
    if (y == -1){
        for (int i = 0; i < _width; i++){
            auto it = _bitmapImage.begin();
            _bitmapImage.erase(it);
            _bitmapImage.push_back(0);
        }
    }
    else if (y == 1){
        for (int i = 0; i < _width; i++){
            _bitmapImage.push_front(0);
            auto it = _bitmapImage.end() - 1;
            _bitmapImage.erase(it);
        }
    }

    if (x == -1){
        auto it = _bitmapImage.begin();
        _bitmapImage.erase(it);
        _bitmapImage.push_back(0);
    }
    else if (x == 1){
        auto it = _bitmapImage.end() - 1;
        _bitmapImage.erase(it);
        _bitmapImage.push_front(0);
    }
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
}


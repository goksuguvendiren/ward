#include "../Header/bitmap.h"
#include "../Header/image.h"
#include "../Header/aoa_jpeg.h"
#include <iostream>

using namespace std;

Bitmap::Bitmap()
{
}

Bitmap Bitmap::XOR(const Bitmap& bitmap) const
{
    Bitmap bm;
    bm._width = _width;
    bm._height = _height;
    bm._bitmapImage.resize(_width * _height);

    for (int i = 0; i < bm._bitmapImage.size(); i++){
        bm._bitmapImage[i] = _bitmapImage[i] ^ bitmap._bitmapImage[i];
    }

    return bm;
}

Bitmap Bitmap::AND(const Bitmap &bitmap) const
{
    Bitmap bm;
    bm._width = _width;
    bm._height = _height;
    bm._bitmapImage.resize(_width * _height);
    for (int i = 0; i < bm._bitmapImage.size(); i++){
        bm._bitmapImage[i] = _bitmapImage[i] & bitmap._bitmapImage[i];
    }

    return bm;
}

int Bitmap::CountOnes() const
{
    int sum = 0;
    for (int i = 0; i < _width * _height; i++){
        sum += _bitmapImage[i];
    }

    return sum;
}

Bitmap Bitmap::Shift(int x, int y)
{
    Bitmap bm;
    bm._height = _height;
    bm._width = _width;
    bm._bitmapImage.resize(_width * _height);

    int total = y * _width + x;

    if (total < 0){
        total *= -1;
        for (int i = total; i < _width * _height; i++){
            if ((x < 0 && ((i - total) % _width) > _width + x) || (x > 0 && ((i - total) % _width) < x) || (y > 0 && (i - total) < _width * y) || (y < 0 && (i - total) > _width * (_height - y))){
                bm._bitmapImage[i - total] = false;
                continue;
            }

            bm._bitmapImage[i - total] = _bitmapImage[i];
        }
        for (int i = 0; i < total; i++){
            bm._bitmapImage[i + _width * _height - total] = false;
        }
    }
    else{
        for (int i = 0; i < total; i++){
            bm._bitmapImage[i] = false;
        }
        for (int i = total; i < _width * _height; i++){
            if ((x < 0 && (i % _width) > _width + x) || (x > 0 && (i % _width) < x) || (y > 0 && i < _width * y) || (y < 0 && i > _width * (_height - y))){
                bm._bitmapImage[i - total] = false;
                continue;
            }

            bm._bitmapImage[i] = _bitmapImage[i - total];
        }
    }

    return bm;
}

void Bitmap::ComputeEx(const Image& image)
{
    _width = image.Width();
    _height = image.Height();
    for(int i = 0; i < _height; i++){
        for(int j = 0; j < _width; j++){
            if (image.Value(i, j) > image.Med() - 4 && image.Value(i, j) < image.Med() + 4){
                _bitmapImage.push_back(false);
            }
            else {
                _bitmapImage.push_back(true);
            }
        }
    }
}

void Bitmap::Compute(const Image& image)
{
    _width = image.Width();
    _height = image.Height();
    for(int i = 0; i < _height; i++){
        for(int j = 0; j < _width; j++){
            _bitmapImage.push_back(image.Value(i, j) > image.Med());
        }
    }
}
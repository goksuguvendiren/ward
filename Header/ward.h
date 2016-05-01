//
// Created by goksu on 16.04.2016.
//

#ifndef WARD_WARD_H
#define WARD_WARD_H

#include <vector>
#include "image.h"
#include "bitmap.h"

using std::vector;

class Ward
{
    vector<Image> _images;
    void iterate(const Image& image1, const Image& image2, int shBits, int& shRet1, int& shRet2);
public:
    Ward(const Image& imageRef, const Image& image);
    void Compute();
};


#endif //WARD_WARD_H

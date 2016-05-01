//
// Created by goksu on 16.04.2016.
//

#include <iostream>
#include "../Header/ward.h"
#include "../Header/bitmap.h"

Ward::Ward(const Image& imageRef, const Image& image)
{
    _images.push_back(imageRef);
    _images.push_back(image);
}

void Ward::Compute()
{
    int shX, shY;
    iterate(_images[0], _images[1], 7, shX, shY);

    std::cout << "shX : " << shX << "shY : " << shY << std::endl;
}

void Ward::iterate(const Image &image1, const Image &image2, int shBits, int& shRet1, int& shRet2)
{
    int shiftX, shiftY;
    Bitmap bitmap1, bitmap2;
    Bitmap exBitmap1, exBitmap2;

    if (shBits > 0){
        Image im1 = image1.Shrink();
        Image im2 = image2.Shrink();

        iterate(im1, im2, shBits - 1, shiftX, shiftY);

        shiftX *= 2;
        shiftY *= 2;
    }
    else {
        shiftX = 0;
        shiftY = 0;
    }

    bitmap1.Compute(image1);
    bitmap2.Compute(image2);

    exBitmap1.ComputeEx(image1);
    exBitmap2.ComputeEx(image2);

    int minError = image1.Width() * image1.Height();

    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            int xShift = shiftX + i;
            int yShift = shiftY + j;

            Bitmap bm = bitmap2.Shift(xShift, yShift);
            Bitmap exclusionbm = exBitmap2.Shift(xShift, yShift);

            Bitmap difference = bitmap1.XOR(bm);
            difference = difference.AND(exBitmap1);
            difference = difference.AND(exclusionbm);

            int currentError = difference.CountOnes();

            if (currentError < minError) {
                shRet1 = xShift;
                shRet2 = yShift;

                minError = currentError;
            }
        }
    }
}
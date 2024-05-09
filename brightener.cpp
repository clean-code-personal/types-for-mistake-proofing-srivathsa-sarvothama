#include "brightener.h"

uint8_t brightenPixel(uint8_t inputPixel, uint8_t brighteningGrayscale, int& attenuatedPixelCount) {
    uint8_t brightened = inputPixel;
    if (int(inputPixel) + brighteningGrayscale > 255) {
        ++attenuatedPixelCount;
        brightened = 255;
    }
    else {
        brightened += brighteningGrayscale;
    }
    return brightened;
}

shared_ptr<Image> BrightenWholeImage(shared_ptr<Image> inputImage, int& attenuatedPixelCount) {
    // For brightening, we add a certain grayscale (25) to every pixel.
    // While brightening, some pixels may cross the max brightness. They are
    // called 'attenuated' pixels
    attenuatedPixelCount = 0;
    auto brightenedImage = 
        make_shared<Image>(inputImage->m_rows, inputImage->m_columns,
            [inputImage, &attenuatedPixelCount](uint8_t* initPixels) {
            for (int x = 0; x < inputImage->m_rows; x++) {
                for (int y = 0; y < inputImage->m_columns; y++) {
                    int index = inputImage->pixelIndex(x, y);
                    initPixels[index] =
                        brightenPixel(inputImage->getPixel(x, y), 25, attenuatedPixelCount);
                }
            }
        });
    return brightenedImage;
}

shared_ptr<Image> AddBrighteningImage(shared_ptr<Image> inputImage, shared_ptr<Image> imageToAdd,
    int& attenuatedPixelCount) {
    // Try converting this into an exception, so callers don't always need to check the returned bool
    // if (imageToAdd->m_rows != m_inputImage->m_rows || imageToAdd->m_columns != m_inputImage->m_columns) {
    //     return false;
    // }
    attenuatedPixelCount = 0;
    auto brightenedImage =
        make_shared<Image>(inputImage->m_rows, inputImage->m_columns,
            [inputImage, imageToAdd, &attenuatedPixelCount](uint8_t* initPixels) {
            for (int x = 0; x < inputImage->m_rows; x++) {
                for (int y = 0; y < inputImage->m_columns; y++) {
                    int index = inputImage->pixelIndex(x, y);
                    initPixels[index] =
                        brightenPixel(inputImage->getPixel(x, y), imageToAdd->getPixel(x, y), attenuatedPixelCount);
                }
            }
    });
    return brightenedImage;
}

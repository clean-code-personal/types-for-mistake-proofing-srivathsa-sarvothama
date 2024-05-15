#include <cstdint>
#include "image.h"

using namespace std;

shared_ptr<BrightenedImage> BrightenWholeImage(const shared_ptr<RawImage> inputImage, int& attenuatedPixelCount);
shared_ptr<BrightenedImage> AddBrighteningImage(const shared_ptr<RawImage> inputImage,const shared_ptr<Image> imageToAdd,
    int& attenuatedPixelCount);

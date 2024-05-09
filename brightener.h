#include <cstdint>
#include "image.h"

using namespace std;

shared_ptr<Image> BrightenWholeImage(shared_ptr<Image> inputImage, int& attenuatedPixelCount);
shared_ptr<Image> AddBrighteningImage(shared_ptr<Image> inputImage, shared_ptr<Image> imageToAdd,
    int& attenuatedPixelCount);

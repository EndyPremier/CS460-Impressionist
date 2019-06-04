//
// ImageFilter.h
//
// Output a new bmp image given an input bitmap image and it's width and height
//

#ifndef IMAGEFILTER_H
#define IMAGEFILTER_H

class ImageFilter
{
public:
  ImageFilter();

  unsigned char* grayscale(unsigned char* bmp, int width, int height);
  unsigned char* horSobal(unsigned char* bmp, int width, int height);
  unsigned char* verSobal(unsigned char* bmp, int width, int height);
  unsigned char* gaussian(unsigned char* bmp, int width, int height);
};

#endif
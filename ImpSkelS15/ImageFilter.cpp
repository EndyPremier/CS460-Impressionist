//
// ImageFilter.cpp
//
// Output a new bmp image given an input bitmap image and it's width and height
//

#include "ImageFilter.h"
#include <math.h>
#include <iostream>

ImageFilter::ImageFilter()
{
}

unsigned char* ImageFilter::grayscale(unsigned char* bmp, int width, int height)
{
  unsigned char* output = new unsigned char[width * height * 3];
  memset(output, 0, sizeof(output));

  for (int y = 0; y < height; ++y)
  {
    for (int x = 0; x < width; ++x)
    {
      int rpos = (y * width + x) * 3;  // current pixel position at r pixel

      float r = (float)bmp[rpos + 0] / 255;
      float g = (float)bmp[rpos + 1] / 255;
      float b = (float)bmp[rpos + 2] / 255;

      float weight = r * 0.299 + g * 0.587 + b * 0.114;
      char cweight = (char)(weight * 255);

      output[rpos + 0] = output[rpos + 1] = output[rpos + 2] = cweight;
    }
  }

  return output;
}

unsigned char* ImageFilter::horSobal(unsigned char* bmp, int width, int height)
{
  unsigned char* output = new unsigned char[width * height * 3];
  memset(output, 0, sizeof(output));

  int matrix[3][3] = {{-1, 0, 1},
                      {-2, 0, 2},
                      {-1, 0, 1}};

  for (int y = 0; y < height; ++y)
  {
    for (int x = 0; x < width; ++x)
    {
      int rpos = (y * width + x) * 3;  // current pixel position at r pixel
      int weight = 0;                  // output weight for the pixel

      // calculate the surrounding pixel with matrix
      for (int yp = -1; yp <= 1; ++yp)
      {
        for (int xp = -1; xp <= 1; ++xp)
        {
          int xf = (int)fmin(fmax(0, x + xp),  width - 1);
          int yf = (int)fmin(fmax(0, y + yp), height - 1);

          int rf = (yf * width + xf) * 3;

          weight += matrix[yp+1][xp+1] * bmp[rf];
        }
      }

      weight = weight / 8 + 128;
      output[rpos + 0] = output[rpos + 1] = output[rpos + 2] = weight;

    }
  }

  return output;
}

unsigned char* ImageFilter::verSobal(unsigned char* bmp, int width, int height)
{
  unsigned char* output = new unsigned char[width * height * 3];
  memset(output, 0, sizeof(output));

  int matrix[3][3] = {{-1,-2,-1},
                      { 0, 0, 0},
                      { 1, 2, 1}};

  for (int y = 0; y < height; ++y)
  {
    for (int x = 0; x < width; ++x)
    {
      int rpos = (y * width + x) * 3;  // current pixel position at r pixel
      int weight = 0;                  // output weight for the pixel

      // calculate the surrounding pixel with matrix
      for (int yp = -1; yp <= 1; ++yp)
      {
        for (int xp = -1; xp <= 1; ++xp)
        {
          int xf = (int)fmin(fmax(0, x + xp), width - 1);
          int yf = (int)fmin(fmax(0, y + yp), height - 1);

          int rf = (yf * width + xf) * 3;

          weight += matrix[yp + 1][xp + 1] * bmp[rf];
        }
      }

      weight = weight / 8 + 128;
      output[rpos + 0] = output[rpos + 1] = output[rpos + 2] = weight;

    }
  }

  return output;
}


unsigned char* ImageFilter::gaussian(unsigned char* bmp, int width, int height)
{
  unsigned char* output = new unsigned char[width * height * 3];
  memset(output, 0, sizeof(output));

  int matrix[5][5] = { { 1,  4,  7,  4,  1},
                       { 4, 16, 26, 16,  4},
                       { 7, 26, 41, 26,  7},
                       { 4, 16, 26, 16,  4},
                       { 1,  4,  7,  4,  1}};

  for (int y = 0; y < height; ++y)
  {
    for (int x = 0; x < width; ++x)
    {
      int rpos = (y * width + x) * 3;  // current pixel position at r pixel
                                       
      // for each color in pixel
      for (int c = 0; c < 3; ++c)
      {
        int weight = 0;                  // output weight for the pixel

        // calculate the surrounding pixel with matrix
        for (int yp = -2; yp <= 2; ++yp)
        {
          for (int xp = -2; xp <= 2; ++xp)
          {
            int xf = (int)fmin(fmax(0, x + xp), width - 1);
            int yf = (int)fmin(fmax(0, y + yp), height - 1);

            int rf = (yf * width + xf) * 3 + c;

            weight += matrix[yp + 2][xp + 2] * bmp[rf];
          }
        }

        weight = weight / 273;
        output[rpos + c] = weight;

      }

    }
  }

  return output;
}
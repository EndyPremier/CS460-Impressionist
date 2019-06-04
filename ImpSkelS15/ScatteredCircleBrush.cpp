//
// ScatteredPointBrush.cpp
//
// Implementation of ScattteredPointBrush (kind of ImpBrush)
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ScatteredCircleBrush.h"

#include <math.h>
#define PI 3.14159265
#define DENSITY 0.002
#define CIRC_RES 32

extern float frand();

ScatteredCircleBrush::ScatteredCircleBrush(ImpressionistDoc* pDoc, char* name) :
  ImpBrush(pDoc, name)
{
}

void ScatteredCircleBrush::BrushBegin(const Point source, const Point target)
{
  ImpressionistDoc* pDoc = GetDocument();
  ImpressionistUI* dlg = pDoc->m_pUI;

  BrushMove(source, target);
}

void ScatteredCircleBrush::BrushMove(const Point source, const Point target)
{
  ImpressionistDoc* pDoc = GetDocument();
  ImpressionistUI* dlg = pDoc->m_pUI;

  float size = pDoc->getSize() / 2;
  float alpha = pDoc->getAlpha();

  int width = pDoc->m_nPaintWidth;
  int height = pDoc->m_nPaintHeight;

  if (pDoc == NULL) {
    printf("ScatteredPointBrush::BrushMove  document is NULL\n");
    return;
  }

  float delta = size / 2;

  glBegin(GL_TRIANGLE_FAN);
  
  for (int x = target.x - delta; x <= target.x + delta; x += 1)
    for (int y = target.y - delta; y <= target.y + delta; y += 1)
      if (rand() < 32768 * DENSITY)
      {
        int xf = x < width  ? x : width  - (x % width );
        int yf = y < height ? y : height - (y % height);
        SetColor(Point(xf, yf));
        
        for (int i = 0; i < CIRC_RES; ++i)
        {
          float angle = (float)i / CIRC_RES * 2 * PI;
          float xDif = size * cos(angle);
          float yDif = size * sin(angle);

          glVertex2d(x + xDif, y + yDif);
        }
      }

  glEnd();
}

void ScatteredCircleBrush::BrushEnd(const Point source, const Point target)
{
  // do nothing so far
}
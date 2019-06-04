//
// LineBrush.cpp
//
// Implementation of LineBrush (kind of ImpBrush)
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "CircleBrush.h"

#include <math.h>
#define PI 3.14159265

#define CIRC_RES 32

extern float frand();

CircleBrush::CircleBrush(ImpressionistDoc* pDoc, char* name) :
  ImpBrush(pDoc, name)
{
}

void CircleBrush::BrushBegin(const Point source, const Point target)
{
  ImpressionistDoc* pDoc = GetDocument();
  ImpressionistUI* dlg = pDoc->m_pUI;

  BrushMove(source, target);
}

void CircleBrush::BrushMove(const Point source, const Point target)
{
  ImpressionistDoc* pDoc = GetDocument();
  ImpressionistUI* dlg = pDoc->m_pUI;

  float size = pDoc->getSize() / 2;
  float alpha = pDoc->getAlpha();

  if (pDoc == NULL) {
    printf("CircleBrush::BrushMove  document is NULL\n");
    return;
  }

  glBegin(GL_TRIANGLE_FAN);
    SetColor(source);

    for (int i = 0; i < CIRC_RES; ++i)
    {
      float angle = (float)i / CIRC_RES * 2 * PI;
      float xDif = size * cos(angle);
      float yDif = size * sin(angle);

      glVertex2d(target.x + xDif, target.y + yDif);
    }

  glEnd();
}

void CircleBrush::BrushEnd(const Point source, const Point target)
{
  // do nothing so far
}


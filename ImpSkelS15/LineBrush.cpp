//
// LineBrush.cpp
//
// Implementation of LineBrush (kind of ImpBrush)
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "linebrush.h"

#include <math.h>
#define PI 3.14159265

extern float frand();

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name) :
  ImpBrush(pDoc, name)
{
}

void LineBrush::BrushBegin(const Point source, const Point target)
{
  ImpressionistDoc* pDoc = GetDocument();
  ImpressionistUI* dlg = pDoc->m_pUI;

  float width = pDoc->getWidth();

  glLineWidth(width);

  BrushMove(source, target);
}

void LineBrush::BrushMove(const Point source, const Point target)
{
  ImpressionistDoc* pDoc = GetDocument();
  ImpressionistUI* dlg = pDoc->m_pUI;

  float size  = pDoc->getSize();
  float angle = pDoc->getAngle();
  float alpha = pDoc->getAlpha();
  float width = pDoc->getWidth();

  glLineWidth(width);

  if (pDoc == NULL)
  {
    printf("LineBrush::BrushMove  document is NULL\n");
    return;
  }

  float xDif = size / 2 * cos(angle * PI / 180);
  float yDif = size / 2 * sin(angle * PI / 180);

  glBegin(GL_LINES);
    SetColor(source);

    glVertex2d(target.x + xDif, target.y + yDif);
    glVertex2d(target.x - xDif, target.y - yDif);

  glEnd();
}

void LineBrush::BrushEnd(const Point source, const Point target)
{
  // do nothing so far
}
//
// ScatteredLineBrush.cpp
//
// Implementation of ScatteredLineBrush (kind of ImpBrush)
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ScatteredLineBrush.h"

#include <math.h>
#define DENSITY 0.002
#define PI 3.14159265

extern float frand();

ScatteredLineBrush::ScatteredLineBrush(ImpressionistDoc* pDoc, char* name) :
  ImpBrush(pDoc, name)
{
}

void ScatteredLineBrush::BrushBegin(const Point source, const Point target)
{
  ImpressionistDoc* pDoc = GetDocument();
  ImpressionistUI* dlg = pDoc->m_pUI;

  float width = pDoc->getWidth();

  glLineWidth((float)width);

  BrushMove(source, target);
}

void ScatteredLineBrush::BrushMove(const Point source, const Point target)
{
  ImpressionistDoc* pDoc = GetDocument();
  ImpressionistUI* dlg = pDoc->m_pUI;

  float size = pDoc->getSize();
  float angle = pDoc->getAngle();
  float alpha = pDoc->getAlpha();
  float thick = pDoc->getWidth();

  float width = pDoc->m_nPaintWidth;
  float height = pDoc->m_nPaintHeight;

  glLineWidth(thick);

  if (pDoc == NULL) {
    printf("ScatteredLineBrush::BrushMove  document is NULL\n");
    return;
  }

  float delta = size / 2;

  float xDif = size / 2 * cos(angle * PI / 180);
  float yDif = size / 2 * sin(angle * PI / 180);

  glBegin(GL_LINES);

  for (int x = max(0, target.x - delta); x <= min(target.x + delta, width - 1); x += 1)
    for (int y = max(0, target.y - delta); y <= min(target.y + delta, height - 1); y += 1)
        if (rand() < 32768 * DENSITY)
        {
          SetColor(Point(x, y));
          glVertex2d(x + xDif, y + yDif);
          glVertex2d(x - xDif, y - yDif);
        }

  glEnd();
}

void ScatteredLineBrush::BrushEnd(const Point source, const Point target)
{
  // do nothing so far
}

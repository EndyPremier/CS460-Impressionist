//
// ScatteredPointBrush.cpp
//
// Implementation of ScattteredPointBrush (kind of ImpBrush)
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ScatteredPointBrush.h"

#include <math.h>
#define DENSITY 0.05

extern float frand();

ScatteredPointBrush::ScatteredPointBrush(ImpressionistDoc* pDoc, char* name) :
  ImpBrush(pDoc, name)
{
}

void ScatteredPointBrush::BrushBegin(const Point source, const Point target)
{
  ImpressionistDoc* pDoc = GetDocument();
  ImpressionistUI* dlg = pDoc->m_pUI;

  glPointSize(1);

  BrushMove(source, target);
}

void ScatteredPointBrush::BrushMove(const Point source, const Point target)
{
  ImpressionistDoc* pDoc = GetDocument();
  ImpressionistUI* dlg = pDoc->m_pUI;

  float size = pDoc->getSize();
  float alpha = pDoc->getAlpha();

  float width = pDoc->m_nPaintWidth;
  float height = pDoc->m_nPaintHeight;

  if (pDoc == NULL) {
    printf("ScatteredPointBrush::BrushMove  document is NULL\n");
    return;
  }

  float delta = size / 2;

  glBegin(GL_POINTS);
    
    for (int x = max(0, target.x - delta); x <= min(target.x + delta, width - 1); x += 1)
      for (int y = max(0, target.y - delta); y <= min(target.y + delta, height - 1); y += 1)
        if (rand() < 32768 * DENSITY)
        {
          SetColor(Point(x, y));
          glVertex2d(x, y);
        }

  glEnd();
}

void ScatteredPointBrush::BrushEnd(const Point source, const Point target)
{
  // do nothing so far
}

//
// originalview.h
//
// The header file for original view of the input images
//

#ifndef ORIGINALVIEW_H
#define ORIGINALVIEW_H

#include <FL/Fl.H>

#include <FL/Fl_Gl_Window.H>
#include <FL/gl.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <stdlib.h>

#include "ImpBrush.h"

class ImpressionistDoc;

class OriginalView : public Fl_Gl_Window
{
public:
	OriginalView(int x, int y, int w, int h, const char *l);
	
	void draw();
	void refresh();
  void setView(int pic);

	void resizeWindow(int width, int height);

  static OriginalView* getInstance();

	ImpressionistDoc*	m_pDoc;
  unsigned char** currentView;

private:
	int	m_nWindowWidth, 
		m_nWindowHeight;
  static OriginalView* instance;
};

#endif
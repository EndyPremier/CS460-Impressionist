// 
// impressionistDoc.h
//
// header file for Doc 
//

#ifndef ImpressionistDoc_h
#define ImpressionistDoc_h

#include "impressionist.h"
#include "bitmap.h"
#include "ImageFilter.h"

class ImpressionistUI;

class ImpressionistDoc 
{
public:
	ImpressionistDoc();

	void	setUI(ImpressionistUI* ui);		// Assign the UI to use

	int		loadImage(char *iname);			// called by the UI to load image
	int		saveImage(char *iname);			// called by the UI to save image


	int     clearCanvas();                  // called by the UI to clear the drawing canvas
	void	setBrushType(int type);			// called by the UI to set the brushType
  void  setBrushDirection(int type);

	int		getSize();						        // get the UI size
	void	setSize(int size);		        // set the UI size
  int   getWidth();                   // get the UI width
  void  setWidth(int width);          // set the UI width
  int   getAngle();                   // get the UI angle
  void  setAngle(int angle);          // set the UI angle
  int   getAlpha();                   // get the UI alpha
  void  setAlpha(int alpha);          // set the UI alpha

	char*	getImageName();					// get the current image name
	

// Attributes
public:
	// Dimensions of original window.
	int				m_nWidth, 
					m_nHeight;
	// Dimensions of the paint window.
	int				m_nPaintWidth, 
					m_nPaintHeight;	
	// Bitmaps for original image and painting and edge maps.
	unsigned char*	m_ucBitmap;
	unsigned char*	m_ucPainting;

  unsigned char*  m_ucGrayscaleMap;
  unsigned char*  m_ucHorEdgeMap;
  unsigned char*  m_ucVerEdgeMap;

  unsigned char** m_ucCurrent;


	// The current active brush.
	ImpBrush*			m_pCurrentBrush;
  int m_pCurrentDirection;
	// Properties of the brush.
	int m_nSize, m_nLWidth, m_nLAngle, m_nAlpha;

	ImpressionistUI*	m_pUI;
  ImageFilter* imageFilter;

// Operations
public:
	// Get the color of the original picture at the specified coord
	GLubyte* GetOriginalPixel( int x, int y );   
	// Get the color of the original picture at the specified point	
	GLubyte* GetOriginalPixel( const Point p );  

  static ImpressionistDoc* getInstance();

private:
	char			m_imageName[256];
  static ImpressionistDoc* instance;
};

extern void MessageBox(char *message);

#endif

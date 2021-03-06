/* 
 * marker_controller.hpp
 */

#ifndef __MARKER_CONTROLLER_HPP__
#define __MARKER_CONTROLLER_HPP__

#include <vector>
#include <string>
using namespace std;

#include <GL/glut.h>
#include <FTGL/ftgl.h>
#include "artkglut_marker.hpp"

class Marker_Controller : public ARTKGLUT_Marker
{
public:
	Marker_Controller();
	~Marker_Controller();
	int draw();
	int process(bool b);
	
protected:
	FTGLTextureFont *_font1;
	FTGLTextureFont *_font2;
	GLuint _panelList;
	GLuint _panelList2;
	GLuint _blockList;
	GLuint _mapList;
	string result;
	int _cursor;
};

#endif


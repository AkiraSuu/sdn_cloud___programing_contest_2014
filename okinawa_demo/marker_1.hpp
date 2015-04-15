/* 
 * marker_1.hpp
 */

#ifndef __MARKER_1_HPP__
#define __MARKER_1_HPP__

#include <vector>
using namespace std;

#include <GL/glut.h>
#include <FTGL/ftgl.h>
#include "artkglut_marker.hpp"
#include "vm.hpp"
#include "port.hpp"

class Marker_1 : public ARTKGLUT_Marker
{
public:
	Marker_1();
	~Marker_1();
	int draw();
	int process(bool b);
	
protected:
	FTGLTextureFont *_font1;
	FTGLTextureFont *_font2;
	GLuint _panelList;
	GLuint _mapList;
	vector<VM *> _vms;
	vector<Port *> _ports;
	
	int _cursor;
};

#endif


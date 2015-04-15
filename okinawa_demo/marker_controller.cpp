/* 
 * marker_controller.cpp
 */

#include <stdexcept>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <FTGL/ftgl.h>
#include "marker_controller.hpp"
#include "artkglut_marker.hpp"
//#include "draw_utils.hpp"

extern void draw_panel_map(float x, float y, float w, float h);
extern void draw_panel_xywh_3(float x, float y, float w, float h);
extern void draw_panel_xywh_2(float x, float y, float w, float h);
extern void draw_panel_xywh(float x, float y, float w, float h);

Marker_Controller::Marker_Controller()
	: ARTKGLUT_Marker("data/patt.controller", 120)
{
	_cursor = 0;
	_font1 = new FTGLTextureFont("Aller_Bd.ttf");
	if (_font1->Error()) {
		throw runtime_error("FTGLTextureFont()");
	}
	_font1->FaceSize(8);
	
	_font2 = new FTGLTextureFont("rounded-mgenplus-2pp-light.ttf");
	if (_font2->Error()) {
		throw runtime_error("FTGLTextureFont()");
	}
	_font2->FaceSize(16);

	_panelList = glGenLists(1);
	glNewList(_panelList, GL_COMPILE);
		draw_panel_xywh_2(-100, 100, 200, 200);
		glTranslatef(0, 0, 20);
	glEndList();

	_panelList2 = glGenLists(1);
	glNewList(_panelList2, GL_COMPILE);
		draw_panel_xywh_2(-80, 100, 160, 200);
		glTranslatef(0, 0, 20);
	glEndList();
	
	_blockList = glGenLists(1);
	glNewList(_blockList, GL_COMPILE);
		draw_panel_xywh(-10, 10, 20, 20);
		glTranslatef(0, 0, 5);
	glEndList();
	
	_mapList = glGenLists(1);
	glNewList(_mapList, GL_COMPILE);
		draw_panel_map(0, 0, 140, 120);
	glEndList();
}

Marker_Controller::~Marker_Controller()
{
}

int
Marker_Controller::process(bool b)
{
	static int frame = 0;
	if (!(frame % 100)) {
		FILE *pipe = popen("cat network.conf", "r");
		if (!pipe) {
			return -1;
		}
		char buffer[2048];
		result = "";
		while (!feof(pipe)) {
			if (fgets(buffer, 2048, pipe) != NULL)
				result += buffer;
		}
		pclose(pipe);
	}
	cout << result << endl;
	frame++;
	return 0;
}

int
Marker_Controller::draw()
{
	process(true);

	glPushMatrix(); // Save world coordinate system.
	//glTranslatef(0, 0, -30);

	glTranslatef(0, 0, 10);
	glCallList(_panelList2);
	
	glTranslatef(-30, 30, 0);
	glCallList(_blockList);
	glTranslatef(0, 0, 0.2);
	glCallList(_blockList);
	//_font1->Render("0xabc");
	
	glTranslatef(10, 0, 0);
	_font1->Render("0xabc");
	glTranslatef(-10, 0, 0);

	
	glTranslatef(0, 0, -20);
	glTranslatef(60, -60, 0);
	glCallList(_blockList);
	glTranslatef(0, 0, 0.2);
	glCallList(_blockList);
	//_font1->Render("0x1");
	
	glTranslatef(10, 0, 0);
	_font1->Render("0x1");
	glTranslatef(-10, 0, 0);

	glBegin(GL_LINES);
		glVertex2d(0, 0);
		glVertex2d(-60, 60);
	glEnd();

	glPopMatrix();	// Restore world coordinate system.




	glPushMatrix(); // Save world coordinate system.
	
	
	glDisable(GL_LIGHTING);	// Just use colours.
	glTranslatef(0, 300, 50);
	glRotatef(50, 1, 0, 0);
	glCallList(_panelList);

	istringstream iss(result);
	string headertoken;
	glTranslatef(-80, 40, 0);
	while (getline (iss, headertoken, '\n')) {
		_font1->Render(headertoken.c_str());
		glTranslatef(0, -10, 0);
	}
	glPopMatrix();	// Restore world coordinate system.


	
	
	return 0;
}


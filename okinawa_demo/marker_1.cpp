/* 
 * marker_1.cpp
 */

#include <stdexcept>
#include <vector>
#include <iostream>
using namespace std;

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <FTGL/ftgl.h>
#include "marker_1.hpp"
#include "artkglut_marker.hpp"
#include "draw_utils.hpp"

Marker_1::Marker_1()
	: ARTKGLUT_Marker("data/patt.switch_b", 120)
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
	_font2->FaceSize(42);
	

	_ports.push_back(new Port(2, "0/2"));
	_ports.push_back(new Port(3, "0/3"));
	_ports.push_back(new Port(4, "0/4"));
	_ports.push_back(new Port(5, "0/5"));
	_ports.push_back(new Port(6, "0/6"));
	_ports.push_back(new Port(7, "0/7"));
	_ports.push_back(new Port(8, "0/8"));
	_ports.push_back(new Port(9, "0/9"));
	_ports.push_back(new Port(1, "0/1"));

	_panelList = glGenLists(1);
	glNewList(_panelList, GL_COMPILE);
		//glColor4f(0, 1, 0, 0.7);
		glTranslatef(-390, -70, 0);
		draw_panel_xywh_3(0, 0, 240, 30);
		glTranslatef(20, -8, 10);
		for (int i = 0; i < 8; i++) {
			draw_panel_xywh_2(0, 0, 10, 10);
			glTranslatef(26, 0,-2.5);
		}
		glTranslatef(26, 0, 0);
		draw_panel_xywh_3(0, 0, 10, 10);

	glEndList();
	
	_mapList = glGenLists(1);
	glNewList(_mapList, GL_COMPILE);
		draw_panel_map(0, 0, 140, 120);
	glEndList();
}

Marker_1::~Marker_1()
{
	_vms.clear();
}

int
Marker_1::process(bool b)
{
	if (b) {
		if (++_cursor == 8)
			_cursor = 0;
	} else {
		if (--_cursor == -1)
			_cursor = 7;
	}

	return 0;
}

int
Marker_1::draw()
{
	//process();
	glPushMatrix(); // Save world coordinate system.
	
	glDisable(GL_LIGHTING);	// Just use colours.

	glCallList(_panelList);
	
	glTranslatef(-228, 125, 0);
	glTranslatef(_cursor*26, 0, 0);
	glCallList(_mapList);
	
	/* */
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D( 0, 1280, 0, 960 );

	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	glLoadIdentity();
	//glRasterPos2i( 80, 30 );  // move in 10 pixels from the left and bottom edges
	glTranslatef(30, 160, 0);
	glColor4f(0, 0, 0, 0.2);
	glBegin(GL_POLYGON);
		glVertex2f(-10, 50);
		glVertex2f(-10, -85);
		glVertex2f(560, -85);
		glVertex2f(560, 50);
	glEnd();
	glColor4f(1, 1, 1, .8);
	if (_cursor == 0) {

		_font2->Render("interface FastEthernet 0/1");
		glTranslatef(0, -35, 0);
		_font2->Render("no ip address");
		glTranslatef(0, -35, 0);
		_font2->Render("vlan mode trunk");
	}
	if (_cursor == 1) {
		_font2->Render("interface FastEthernet 0/2");
		glTranslatef(0, -35, 0);
		_font2->Render("no ip address");
		glTranslatef(0, -35, 0);
		_font2->Render("vlan mode access 43");
	}
	if (_cursor == 2) {
		_font2->Render("interface FastEthernet 0/3");
		glTranslatef(0, -35, 0);
		_font2->Render("no ip address");
		glTranslatef(0, -35, 0);
		_font2->Render("vlan mode trunk");
	}
	if (_cursor == 3) {
		_font2->Render("interface FastEthernet 0/4");
		glTranslatef(0, -35, 0);
		_font2->Render("no ip address");
		glTranslatef(0, -35, 0);
		_font2->Render("vlan mode trunk");
	}
	if (_cursor == 4) {
		_font2->Render("interface FastEthernet 0/5");
		glTranslatef(0, -35, 0);
		_font2->Render("no ip address");
		glTranslatef(0, -35, 0);
		_font2->Render("vlan mode trunk");
	}
	if (_cursor == 5) {
		_font2->Render("interface FastEthernet 0/6");
		glTranslatef(0, -35, 0);
		_font2->Render("no ip address");
		glTranslatef(0, -35, 0);
		_font2->Render("vlan mode trunk");
	}
	if (_cursor == 6) {
		_font2->Render("interface FastEthernet 0/7");
		glTranslatef(0, -35, 0);
		_font2->Render("no ip address");
		glTranslatef(0, -35, 0);
		_font2->Render("vlan mode access 42");
	}
	if (_cursor == 7) {
		_font2->Render("interface FastEthernet0/8");
		glTranslatef(0, -35, 0);
		_font2->Render("no ip address");
		glTranslatef(0, -35, 0);
		_font2->Render("vlan mode trunk");
	}
	//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'a');

	glPopMatrix();

	glMatrixMode( GL_PROJECTION );
	glPopMatrix();
	glMatrixMode( GL_MODELVIEW );
	/**/
		
//	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	// Restore world coordinate system.
	
	glPushMatrix();
/*
		glTranslatef(40, 0, 0);
		glRotatef(80, 1, 0, 0);
		glRotatef(-40, 0, 1, 0);
		glCallList(_mapList);
		
		glTranslatef(-70, -20, 10);
		_font2->Render("ほげ");
		*/
	glPopMatrix();
	
	return 0;
}


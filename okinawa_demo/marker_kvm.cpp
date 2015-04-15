/* 
 * marker_kvm.cpp
 */

#include <stdexcept>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include <stdio.h>

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <FTGL/ftgl.h>
#include "marker_kvm.hpp"
#include "artkglut_marker.hpp"
//#include "draw_utils.hpp"

extern void draw_panel_xywh(float x, float y, float w, float h);
extern void draw_panel_xywh_red(float x, float y, float w, float h);
extern void draw_panel_xywh_blue(float x, float y, float w, float h);

Marker_KVM::Marker_KVM()
	: ARTKGLUT_Marker("data/patt.kvm", 120)
{
	_state = 0;
	_font1 = new FTGLTextureFont("Aller_Bd.ttf");
	if (_font1->Error()) {
		throw runtime_error("FTGLTextureFont()");
	}
	_font1->FaceSize(10);
	
	_font2 = new FTGLTextureFont("rounded-mgenplus-2pp-light.ttf");
	if (_font2->Error()) {
		throw runtime_error("FTGLTextureFont()");
	}
	_font2->FaceSize(8);
	
	_panelList = glGenLists(1);
	glNewList(_panelList, GL_COMPILE);
		draw_panel_xywh(-120, 80, 240, 160);
	glEndList();

	_panelListRed = glGenLists(1);
	glNewList(_panelListRed, GL_COMPILE);
		draw_panel_xywh_red(-120, 80, 240, 160);
	glEndList();

	_panelListBlue = glGenLists(1);
	glNewList(_panelListBlue, GL_COMPILE);
		draw_panel_xywh_blue(-120, 80, 240, 160);
	glEndList();
	
	_mapList = glGenLists(1);
	glNewList(_mapList, GL_COMPILE);
		draw_panel_xywh(-90, 60, 190, 120);
	glEndList();
}

Marker_KVM::~Marker_KVM()
{
	_vms.clear();
}

int
Marker_KVM::process(bool b)
{
	if (b == true) {
		if (++_state == 3)
			_state = 0;
		return 0;
	}
	static int frame = 0;
	if (!(frame % 100)) {
		FILE *pipe = popen("./run_virt_top.rb", "r");
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
		_vms.clear();
		
		istringstream iss(result);
		string headertoken;
		int n = 0;
		while (getline (iss, headertoken, ' ')) {
			if (n == 0)
				str1 = headertoken;
			else if (n == 1)
				str2 = headertoken;
			else if (n == 2)
				str3 = headertoken;
			else if (n == 3)
				str4 = headertoken;
			else if (n == 4)
				str5 = headertoken;
			else if (n == 5)
				str6 = headertoken;
			else if (n == 6)
				str7 = headertoken;
			else if (n == 7)
				str8 = headertoken;
			if (++n == 8)
				break;
		}


		string token;
		string line;

		int i = 0;
		string s1;
		string s2;
		string s3;
		//cout << result << endl;
		while (getline(iss, line)) {
			istringstream iss2(line);
			while (getline(iss2, token, ' ')) {
				if (i == 0) {
					s1 = token;
				} else if (i == 1) {
					s2 = token;
				} else if (i == 2) {
					s3 = token;
				}
				if (++i == 3) {
					_vms.push_back(new VM(s1, atof(s2.c_str()), atof(s3.c_str())));
					i = 0;
				}
			}
		}
			
		//cout << result << endl;
		/*
		_vms.push_back(new VM("crunchbang64", 0.992530530407, 12));
		_vms.push_back(new VM("mininet", 0.661687020271, 12));
		_vms.push_back(new VM("winxp", 1.07524140794, 12));*/
	}
	frame++;
	return 0;
}

int
Marker_KVM::draw()
{
	process(false);
	glPushMatrix(); // Save world coordinate system.
	
	glDisable(GL_LIGHTING);	// Just use colours.
	glTranslatef(-50, 0, 160);
	glRotatef(80.0, 1.0, 0, 0);
	
	if (_state == 0)
		glCallList(_panelList);
	else if (_state == 1)
		glCallList(_panelListRed);
	else if (_state == 2) {
		glCallList(_panelListBlue);
	}
		//glCallList(_panelListBlue);
	
	if (_state == 0)
		glColor4f(0, 1, 0, 0.7);
	else
		glColor4f(1, 1, 1, 0.7);

	glTranslatef(-110, 60, 10.0);
//	glEnable(GL_TEXTURE_2D);
	_font1->Render("Domain Name");
	glTranslatef(80, 0, 0);
	_font1->Render("\% CPU");
	glTranslatef(80, 0, 0);
	_font1->Render("\% Memory");
	
	glTranslatef(0, -5, 0);
	
	for (int i = 0; i < (signed int)_vms.size(); i++) {
		glTranslatef(-160, -10, 0);
		_font1->Render(_vms.at(i)->get_name().c_str());
		glTranslatef(80, 0, 0);
		_font1->Render(to_string(_vms.at(i)->get_cpu_usage()).c_str());
		glTranslatef(80, 0, 0);
		_font1->Render(to_string(_vms.at(i)->get_mem_usage()).c_str());
	}

	//glTranslatef(-160, -10, 0);
	//_font1->Render(result.c_str());	

		
//	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	// Restore world coordinate system.
	
	glPushMatrix();

		glTranslatef(180, 200, 0);
		glRotatef(80, 1, 0, 0);
		glRotatef(-40, 0, 1, 0);
		glCallList(_mapList);

		glColor4f(.9, .9, .9, 0.7);
		glTranslatef(-75, 40, 10);
		_font1->Render("Hostname: ");
		glTranslatef(0, -10, 0);
		_font1->Render("Time: ");
		glTranslatef(0, -10, 0);
		_font1->Render("Arch: ");
		glTranslatef(0, -10, 0);
		_font1->Render("Physical CPUs: ");
		glTranslatef(0, -10, 0);
		_font1->Render("Total hw mem (KB): ");
		glTranslatef(0, -10, 0);
		_font1->Render("Total mem (KB): ");
		glTranslatef(0, -10, 0);
		_font1->Render("Total guest mem (KB): ");
		glTranslatef(0, -10, 0);
		_font1->Render("\% CPUs: ");
		
		glTranslatef(110, 70, 0);
		_font1->Render(str1.c_str());
		glTranslatef(0, -10, 0);
		_font1->Render(str2.c_str());
		glTranslatef(0, -10, 0);
		_font1->Render(str3.c_str());
		glTranslatef(0, -10, 0);
		_font1->Render(str4.c_str());
		glTranslatef(0, -10, 0);
		_font1->Render(str5.c_str());
		glTranslatef(0, -10, 0);
		_font1->Render(str6.c_str());
		glTranslatef(0, -10, 0);
		_font1->Render(str7.c_str());
		glTranslatef(0, -10, 0);
		_font1->Render(str8.c_str());
	glPopMatrix();
	
	return 0;
}


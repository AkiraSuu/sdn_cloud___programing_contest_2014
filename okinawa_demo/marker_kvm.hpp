/* 
 * marker_kvm.hpp
 */

#ifndef __MARKER_KVM_HPP__
#define __MARKER_KVM_HPP__

#include <vector>
using namespace std;

#include <GL/glut.h>
#include <FTGL/ftgl.h>
#include "artkglut_marker.hpp"
#include "vm.hpp"

class Marker_KVM : public ARTKGLUT_Marker
{
public:
	Marker_KVM();
	~Marker_KVM();
	int draw();
	int process(bool b);
	
protected:
	FTGLTextureFont *_font1;
	FTGLTextureFont *_font2;
	GLuint _panelList;
	GLuint _panelListRed;
	GLuint _panelListBlue;
	GLuint _mapList;
	vector<VM *> _vms;
	string result;
	string str1;
	string str2;
	string str3;
	string str4;
	string str5;
	string str6;
	string str7;
	string str8;
	string str9;
	int _state;
};

#endif


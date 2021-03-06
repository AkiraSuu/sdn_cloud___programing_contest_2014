/* 
 * main.cpp
 */

#include <stdexcept>
#include <memory>
#include <iostream>
using namespace std;

#include <GL/glut.h>

#include "okinawa_demo.hpp"
#include "artkglut_app.hpp"
#include "artkglut_context.hpp"
#include "artkglut_marker.hpp"
#include "marker_1.hpp"
#include "marker_kvm.hpp"
#include "marker_controller.hpp"
#include "marker_face.hpp"

static unique_ptr<Okinawa_Demo> _okinawa_demo;



Okinawa_Demo::Okinawa_Demo(int argc, char *argv[])
{
	_artkglut_context = unique_ptr<ARTKGLUT_Context>(new ARTKGLUT_Context(argc, argv, OKINAWA_DEMO_WIDTH, OKINAWA_DEMO_HEIGHT));
}

Okinawa_Demo::~Okinawa_Demo()
{
}

static void
_display()
{
	_okinawa_demo->display();
}

static void
_idle()
{
	_okinawa_demo->idle();
}

static void
_reshape(int x, int y)
{
	_okinawa_demo->reshape(x, y);
}

static void
_visibility(int v)
{
	if (v == GLUT_VISIBLE) {
		glutIdleFunc(_idle);
	} else {
		glutIdleFunc(NULL);
	}
}

static void
_keyboard(unsigned char key, int x, int y)
{
	_okinawa_demo->keyboard(key, x, y);
}

int
Okinawa_Demo::start()
{
	Marker_1 *m1 = new Marker_1();
	Marker_KVM *m2 = new Marker_KVM();
	Marker_Controller *m3 = new Marker_Controller();
	Marker_Face *m4 = new Marker_Face();
	glutDisplayFunc(_display);
	glutReshapeFunc(_reshape);
	glutVisibilityFunc(_visibility);
	glutKeyboardFunc(_keyboard);
	
	_artkglut_context->add_marker(m1);
	_artkglut_context->add_marker(m2);
	_artkglut_context->add_marker(m3);
	_artkglut_context->add_marker(m4);

	_artkglut_context->start();
	return 0;
}

int
main(int argc, char *argv[])
{
	try {
		_okinawa_demo = unique_ptr<Okinawa_Demo>(new Okinawa_Demo(argc, argv));
		if (_okinawa_demo->start() < 0) {
			cerr << "Failed while running demo." << endl;
			return 1;
		}
		
	} catch (runtime_error &e) {
		cerr << e.what() << endl;
	} catch (...) {
		cerr << "Unhandled exception." << endl;
	}
	
	return 0;
}


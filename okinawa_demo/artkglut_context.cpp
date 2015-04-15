/* 
 * artkglut_context.cpp
 */

#include <stdexcept>
#include <memory>
#include <string>
#include <iostream>
using namespace std;

#include <GL/glut.h>
#include <AR/config.h>
#include <AR/video.h>
#include <AR/ar.h>
#include <AR/gsub_lite.h>

#include "artkglut_context.hpp"
#include "artkglut_camera.hpp"
#include "artkglut_marker.hpp"


ARTKGLUT_Context::ARTKGLUT_Context(int argc, char *argv[], int width, int height)
{
	_detection_threshold = 100;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow(argv[0]);

	// Setup argl library for current context.
	if ((_argl_settings = arglSetupForCurrentContext()) == nullptr) {
		throw runtime_error("arglSetupForCurrentContext()");
	}
	
	//glEnable(GL_DEPTH_TEST);
	glEnable (GL_LINE_SMOOTH);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glEnable (GL_POLYGON_SMOOTH);
	glDisable (GL_DEPTH_TEST);
	arUtilTimerReset();
}

ARTKGLUT_Context::~ARTKGLUT_Context()
{
	_markers.clear();
	arglCleanup(_argl_settings);
}

void
ARTKGLUT_Context::idle()
{
	static int ms_prev;
	int ms;
	float s_elapsed;
	ARUint8 *image;

	ARMarkerInfo    *marker_info;					// Pointer to array holding the details of detected markers.
    int             marker_num;						// Count of number of markers detected.
    int             i, j, k;
	
	// Find out how long since Idle() last ran.
	ms = glutGet(GLUT_ELAPSED_TIME);
	s_elapsed = (float)(ms - ms_prev) * 0.001;
	if (s_elapsed < 0.01f) return;
	ms_prev = ms;
	
	// Update drawing.
	//DrawCubeUpdate(s_elapsed);
	
	// Grab a video frame.
	if ((image = arVideoGetImage()) != NULL) {
		_art_image = image;	// Save the fetched image.
		
		
		
		// Detect the markers in the video frame.
		if (arDetectMarker(_art_image, _detection_threshold, &marker_info, &marker_num) < 0) {
			exit(-1);
		}
		
		// Check through the marker_info array for highest confidence
		// visible marker matching our preferred pattern.
		
		
		for (i = 0; i < (signed int)_markers.size(); i++) {
			k = -1;
			ARTKGLUT_Marker *temp_marker = _markers.at(i);
			for (j = 0; j < marker_num; j++) {
				
				if (marker_info[j].id == temp_marker->get_id()) {
					if (k == -1)
						k = j; // First marker detected.
					else if(marker_info[j].cf > marker_info[k].cf)
						k = j; // Higher confidence marker detected.
				}
			}

			if (k != -1) {
				// Get the transformation between the marker and the real camera into gPatt_trans.
	//			arGetTransMat(&(marker_info[k]), _markers.at(0)->_center, _markers.at(0)->_width, _markers.at(0)->_trans);
				
				if (temp_marker->get_detected()) {
					arGetTransMatCont(&(marker_info[k]), temp_marker->_trans, temp_marker->_center, temp_marker->get_width(), temp_marker->_trans);
				} else {
					arGetTransMat(&(marker_info[k]), temp_marker->_center, temp_marker->get_width(), temp_marker->_trans);
				}
				temp_marker->set_detected(true);
			} else {
				temp_marker->set_detected(false);
			}
		
		}
		
		// Tell GLUT the display has changed.
		glutPostRedisplay();
	}
}

void
ARTKGLUT_Context::reshape(int x, int y)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, (GLsizei) x, (GLsizei) y);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void
ARTKGLUT_Context::display()
{

	GLdouble p[16];
	GLdouble m[16];
	
	// Select correct buffer for this context.
	glDrawBuffer(GL_BACK);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the buffers for new frame.
	
	arglDispImage(_art_image, &_art_c_param, 1.0, _argl_settings);	// zoom = 1.0.
	arVideoCapNext();
	_art_image = NULL; // Image data is no longer valid after calling arVideoCapNext().
	
	// Projection transformation.
	arglCameraFrustumRH(&_art_c_param, VIEW_DISTANCE_MIN, VIEW_DISTANCE_MAX, p);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(p);
	glMatrixMode(GL_MODELVIEW);
	
	// Viewing transformation.
	glLoadIdentity();
	// Lighting and geometry that moves with the camera should go here.
	// (I.e. must be specified before viewing transformations.)
	//none
	
	
	for (int i = 0; i < (signed int)_markers.size(); i++) {
		ARTKGLUT_Marker *temp_marker = _markers.at(i);
		if (temp_marker->get_detected()) {
		
			// Calculate the camera position relative to the marker.
			// Replace VIEW_SCALEFACTOR with 1.0 to make one drawing unit equal to 1.0 ARToolKit units (usually millimeters).
			arglCameraViewRH(temp_marker->_trans, m, VIEW_SCALEFACTOR);
			glLoadMatrixd(m);

			// All lighting and geometry to be drawn relative to the marker goes here.
			temp_marker->draw();
		
		} // gPatt_found
	}
	
	// Any 2D overlays go here.
	//none
	
	
	/*
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D( 0, 640, 0, 480 );

	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i( 10, 10 , 0 );  // move in 10 pixels from the left and bottom edges
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'a');

	glPopMatrix();

	glMatrixMode( GL_PROJECTION );
	glPopMatrix();
	glMatrixMode( GL_MODELVIEW );
	*/
	glutSwapBuffers();
}

void
ARTKGLUT_Context::keyboard(unsigned char key, int x, int y)
{
	if (key == 'n') {
		_markers.at(0)->process(false);
	}
	else if (key == 'm') {
		_markers.at(0)->process(true);
	}
	else if (key == 'p') {
		_markers.at(1)->process(true);;
	}
}

int
ARTKGLUT_Context::add_marker(ARTKGLUT_Marker *marker)
{
	marker->set_id(arLoadPatt(marker->get_path().c_str()));
	cout << "Marker: " << marker->get_id() << endl;
	if (marker->get_id() < 0)
		return -1;
	
	_markers.push_back(marker);
	return 0;
}

int
ARTKGLUT_Context::start()
{
	_camera = unique_ptr<ARTKGLUT_Camera>(new ARTKGLUT_Camera());
	if (_camera->setup(&_art_c_param) < 0)
		return -1;
	
	if(_camera->capture_start() < 0)
		return -1;
	
	glutMainLoop();
	return 0;
}


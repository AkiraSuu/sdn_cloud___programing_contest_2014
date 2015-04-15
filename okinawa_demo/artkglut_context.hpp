/* 
 * artkglut_context.hpp
 */

#ifndef __ARTKGLUT_CONTEXT_HPP__
#define __ARTKGLUT_CONTEXT_HPP__

#include <memory>
#include <vector>
using namespace std;

#include <AR/config.h>
#include <AR/video.h>
#include <AR/param.h>			// arParamDisp()
#include <AR/ar.h>
#include <AR/gsub_lite.h>

#include "artkglut_camera.hpp"
#include "artkglut_marker.hpp"

#define VIEW_SCALEFACTOR		1		// 1.0 ARToolKit unit becomes 0.025 of my OpenGL units.
#define VIEW_DISTANCE_MIN		0.1		// Objects closer to the camera than this will not be displayed.	0.1
#define VIEW_DISTANCE_MAX		10000.0		// Objects further away from the camera than this will not be displayed.

class ARTKGLUT_Context
{
public:
	ARTKGLUT_Context(int argc, char *argv[], int width, int height);
	~ARTKGLUT_Context();
	int start();
	int add_marker(ARTKGLUT_Marker *marker);
	void idle();
	void display();
	void reshape(int x, int y);
	void keyboard(unsigned char key, int x, int y);

private:
	unique_ptr<ARTKGLUT_Camera> _camera;
	ARUint8 *_art_image;
	ARParam _art_c_param;
	int _detection_threshold;
	ARGL_CONTEXT_SETTINGS_REF _argl_settings;
	vector<ARTKGLUT_Marker *> _markers;
};

#endif


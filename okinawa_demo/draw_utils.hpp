/* 
 * draw_utils.hpp
 */

#ifndef __DRAW_UTILS_HPP__
#define __DRAW_UTILS_HPP__

#include <GL/glut.h>

void
draw_panel_xywh(float x, float y, float w, float h)
{

	glBegin(GL_POLYGON);
		glColor4f(0.0, .1, 0.0, 0.9);
			glVertex3f(x, y, 0.0);
		glColor4f(0.0, .1, 0.0, 0.4);
			glVertex3f(x, y-h, 0.0);
		glColor4f(0.0, .1, 0.0, 0.9);
			glVertex3f(x+w, y-h, 0.0);
		glColor4f(0.0, .1, 0.0, 0.9);
			glVertex3f(x+w, y, 0.0);
	glEnd();
	
	glLineWidth(2);	
	glTranslatef(0.0, 0.0, -2.5);
	for (int i = 0; i < 2; i++) {
		glTranslatef(0.0, 0.0, 5.0*i);
		glBegin (GL_LINE_LOOP);
			glColor4f (0.8, 0.8, 0.8, 0.8);
				glVertex3f(x-1, y+1, 0);
				glVertex3f(x-1, y-h-1, 0);
				glVertex3f(x+w+1, y-h-1, 0);
				glVertex3f(x+w+1, y+1, 0);
		glEnd();
		

	}
}

void
draw_panel_xywh_blue(float x, float y, float w, float h)
{

	glBegin(GL_POLYGON);
		glColor4f(0.0, 0, 1, 0.5);
			glVertex3f(x, y, 0.0);
		glColor4f(0.0, 0, 1, 0.1);
			glVertex3f(x, y-h, 0.0);
		glColor4f(0.0, 0, 1, 0.5);
			glVertex3f(x+w, y-h, 0.0);
		glColor4f(0.0, 0, 1, 0.5);
			glVertex3f(x+w, y, 0.0);
	glEnd();
	
	glLineWidth(2);	
	glTranslatef(0.0, 0.0, -2.5);
	for (int i = 0; i < 2; i++) {
		glTranslatef(0.0, 0.0, 5.0*i);
		glBegin (GL_LINE_LOOP);
			glColor4f (0.8, 0.8, 0.8, 0.8);
				glVertex3f(x-1, y+1, 0);
				glVertex3f(x-1, y-h-1, 0);
				glVertex3f(x+w+1, y-h-1, 0);
				glVertex3f(x+w+1, y+1, 0);
		glEnd();
		

	}
}

void
draw_panel_xywh_red(float x, float y, float w, float h)
{

	glBegin(GL_POLYGON);
		glColor4f(1.0, 0, 0.0, 0.5);
			glVertex3f(x, y, 0.0);
		glColor4f(1.0, 0, 0.0, 0.1);
			glVertex3f(x, y-h, 0.0);
		glColor4f(1.0, 0, 0.0, 0.5);
			glVertex3f(x+w, y-h, 0.0);
		glColor4f(1.0, 0, 0.0, 0.5);
			glVertex3f(x+w, y, 0.0);
	glEnd();
	
	glLineWidth(2);	
	glTranslatef(0.0, 0.0, -2.5);
	for (int i = 0; i < 2; i++) {
		glTranslatef(0.0, 0.0, 5.0*i);
		glBegin (GL_LINE_LOOP);
			glColor4f (0.8, 0.8, 0.8, 0.8);
				glVertex3f(x-1, y+1, 0);
				glVertex3f(x-1, y-h-1, 0);
				glVertex3f(x+w+1, y-h-1, 0);
				glVertex3f(x+w+1, y+1, 0);
		glEnd();
		

	}
}

void
draw_panel_xywh_2(float x, float y, float w, float h)
{

	glBegin(GL_POLYGON);
		glColor4f(0.7, .5, 0.0, 0.2);
			glVertex3f(x, y, 0.0);
		glColor4f(0.7, .5, 0.0, 0.1);
			glVertex3f(x, y-h, 0.0);
		glColor4f(0.7, .5, 0.0, 0.2);
			glVertex3f(x+w, y-h, 0.0);
		glColor4f(0.7, .5, 0.0, 0.2);
			glVertex3f(x+w, y, 0.0);
	glEnd();
	
	glLineWidth(2);	
	glTranslatef(0.0, 0.0, -2.5);
	for (int i = 0; i < 2; i++) {
		glTranslatef(0.0, 0.0, 5.0*i);
		glBegin (GL_LINE_LOOP);
			glColor4f (0.8, 0.8, 0.8, 0.8);
				glVertex3f(x-1, y+1, 0);
				glVertex3f(x-1, y-h-1, 0);
				glVertex3f(x+w+1, y-h-1, 0);
				glVertex3f(x+w+1, y+1, 0);
		glEnd();
		

	}
}

void
draw_panel_xywh_3(float x, float y, float w, float h)
{

	glBegin(GL_POLYGON);
		glColor4f(0.7, .5, 0.0, 0.4);
			glVertex3f(x, y, 0.0);
		glColor4f(0.7, .5, 0.0, 0.2);
			glVertex3f(x, y-h, 0.0);
		glColor4f(0.7, .5, 0.0, 0.4);
			glVertex3f(x+w, y-h, 0.0);
		glColor4f(0.7, .5, 0.0, 0.4);
			glVertex3f(x+w, y, 0.0);
	glEnd();
	
	glLineWidth(2);	
	glTranslatef(0.0, 0.0, -2.5);
	for (int i = 0; i < 2; i++) {
		glTranslatef(0.0, 0.0, 5.0*i);
		glBegin (GL_LINE_LOOP);
			glColor4f (0.8, 0.8, 0.8, 0.8);
				glVertex3f(x-1, y+1, 0);
				glVertex3f(x-1, y-h-1, 0);
				glVertex3f(x+w+1, y-h-1, 0);
				glVertex3f(x+w+1, y+1, 0);
		glEnd();
		

	}
}

void
draw_panel_map(float x, float y, float w, float h)
{
	glBegin(GL_LINES);
		glVertex2d(0, 0);
		glVertex2d(0, -h);
	glEnd();
}


#endif


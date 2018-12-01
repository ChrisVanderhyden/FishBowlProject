#ifndef FISH_HPP_
#define FISH_HPP_

#include <GL/glut.h>

#include "rectangle.hpp"
#include "solar/Sphere.hpp"
#include "Pyramid.hpp"

class fish: public Shape{
protected:
Sphere body ;
Pyramid tail ;
Pyramid dorsal ;
Pyramid larm ;
Pyramid rarm ;
Sphere leye ;
Sphere reye ;
double size ;
double schange ;
float yp ; // y position
float zp ; // z  position
float xp ; //x position //describes the bounds for animation
int facing ; //describes the direction the fish is looking (0 = right/ 1 = left/ 2 = front/ 3 = back)
int rising ; // 0 is falling 1 is rising
int eating ; //0 is not eating 1 is eating
public:
float maxx, minx, maxy, miny, maxz, minz, fx, fy, fz ;
int textureID2 ;
	~fish();
	fish(double schange);
	void tfish(double x, double y, double z) ;
	void otfish(double x, double y, double z) ;
	void rfish(double x, double y, double z, double ang) ;
	void setsize(double size) ;
	void draw();
	void moveto(double x, double y, double z,int cont) ;
	void faceleft() ;
	void faceright() ;
	void facefront() ;
	void faceback() ;
	void fronttoright() ;
	void backtoright() ;
	void swim(float speed) ;
	void hitglass() ;
	void life() ;
	void rturn() ;
	void toright() ;
	void food(float x, float y, float z) ;
	void towardsfood() ;
	void setcolor() ;
};


#endif /* FISH_HPP_ */

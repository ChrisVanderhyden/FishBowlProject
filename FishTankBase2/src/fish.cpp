#include "fish.hpp"
#include <stdio.h>
fish::fish()
{
//	bl.setParentMC(&mc);
	body.setParentMC(&mc) ;
	tail.setParentMC(&mc) ;
	dorsal.setParentMC(&mc) ;
	larm.setParentMC(&mc) ;
	rarm.setParentMC(&mc) ;
	leye.setParentMC(&mc) ;
	reye.setParentMC(&mc) ;
	size = 1 ;
	xp = 0.0 ;
	yp = 0.0 ;
	zp = 0.0 ;
	otfish(xp, yp, zp) ;
	//5, 0.25, -0.25, 4.25, -4.25, -6.25, 6.25
	//int text, float yt, float yb, float zcl, float zf, float xl, float xr
}

fish::~fish()
{
}

void fish::draw()
{
	setsize(0) ;
	tfish(0, 0.0, 0) ;
	rfish(0,1,0,50) ;
	//body
    body.sx = 2 ;
    body.sy = 1.5 ;
    body.textureID = 3 ;
    //eyes
    reye.textureID = 2 ;
    leye.textureID = 1 ;
    reye.translate(size*2,0,size) ;
    leye.translate(size*2,0,-size) ;
    reye.scaleChange(-size*2) ;
    leye.scaleChange(-size*2) ;
    //draw
	body.draw();
    reye.draw() ;
    leye.draw() ;
}

void fish::tfish(double x, double y, double z) {
	body.translate(x,y,z) ;
	tail.translate(x,y,z) ;
	dorsal.translate(x,y,z) ;
	larm.translate(x,y,z) ;
	rarm.translate(x,y,z) ;
	leye.translate(x,y,z) ;
	reye.translate(x,y,z) ;
	xp = xp + x ;
	yp = yp + y ;
	zp = zp + z ;

}
void fish::otfish(double x, double y, double z) {
	body.translate(x,y,z) ;
	tail.translate(x,y,z) ;
	dorsal.translate(x,y,z) ;
	larm.translate(x,y,z) ;
	rarm.translate(x,y,z) ;
	leye.translate(x,y,z) ;
	reye.translate(x,y,z) ;

}
void fish::rfish(double x, double y, double z, double ang) {
	body.rotateRelative(xp,yp,zp,x,y,z,ang) ;
	tail.rotateRelative(xp,yp,zp,x,y,z,ang) ;
	dorsal.rotateRelative(xp,yp,zp,x,y,z,ang) ;
	larm.rotateRelative(xp,yp,zp,x,y,z,ang) ;
	rarm.rotateRelative(xp,yp,zp,x,y,z,ang) ;
	leye.rotateRelative(xp,yp,zp,x,y,z,ang) ;
	reye.rotateRelative(xp,yp,zp,x,y,z,ang) ;

}
void fish::setsize(double size) {
	body.scaleChange(size) ;
	tail.scaleChange(size) ;
	dorsal.scaleChange(size) ;
	larm.scaleChange(size) ;
	rarm.scaleChange(size) ;
	leye.scaleChange(size) ;
	reye.scaleChange(size) ;
}


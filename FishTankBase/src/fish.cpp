#include "fish.hpp"
#include <stdio.h>
fish::fish(double schange)
{
	//default facing right
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
	textureID2 = 8 ;
	eating = 0 ;
	rising = 0 ;
	maxx = 0 ; minx = 0 ; maxy = 0 ; miny = 0 ; maxz = 0 ; minz = 0 ;
	facing = 0 ; //default looking right
	otfish(xp, yp, zp) ;
	double adj = 1.0 ;
	//shape
    body.sx = size*2 ;
    body.sy =  size*1.35 ;
    dorsal.sx =  size*1.45 ;
    dorsal.sz =  size*0.25 ;
    dorsal.sy =  size*1.6 ;
    tail.sx = size*1.6 ;
    tail.sz = size*0.32 ;
    tail.sy = size*1.5 ;
    rarm.sx = size*1.2 ;
    rarm.sy = size*1.25 ;
    rarm.sz = size*0.08 ;
    larm.sy = size*1.25 ;
    larm.sz = size*0.08;
    //texture
    body.textureID =  3 ;
    tail.textureID = 5 ;
    reye.textureID = 8 ;
    leye.textureID = 8 ;
    dorsal.textureID = 4 ;
    rarm.textureID = 4 ;
    larm.textureID = 4 ;
    //scale fish
    setsize(schange) ; //-0.7
    reye.scaleChange(-size*0.5) ;
    leye.scaleChange(-size*0.5) ;
    //move
    reye.translate(size*1.35*adj,0,0.7*size*adj) ;
    leye.translate(size*1.35*adj,0,0.7*-size*adj) ;
    dorsal.translate(-size*0.3*adj,size*0.65*adj,0) ;
    tail.translate(-size*2.65*adj, 0, 0) ;
    rarm.translate(0,-size*0.60,size*0.60) ;
    larm.translate(0,-size*0.6,-size*0.6) ;
    //scale
    dorsal.rotateMC(0,0,1, 15) ;
    tail.rotateMC(0,0,1,270) ;
    rarm.rotateMC(1,0,0,148) ;
    larm.rotateMC(1,0,0,360-148) ;
    reye.rotateMC(1,0,0,90) ;
    reye.rotateMC(0,1,0,-60) ;
    leye.rotateMC(1,0,0,-90) ;
    leye.rotateMC(0,1,0,60) ;
//	tfish(0, 0.0, 0) ;
	//rfish(0,1,0,90) ;
    //draw
    tfish(xp,yp,zp) ;
	//5, 0.25, -0.25, 4.25, -4.25, -6.25, 6.25
	//int text, float yt, float yb, float zcl, float zf, float xl, float xr
}

fish::~fish()
{
}

void fish::draw()
{

	body.draw();
    reye.draw() ;
    leye.draw() ;
    dorsal.draw() ;
    tail.draw() ;
    rarm.draw() ;
    larm.draw() ;
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
	 //mySolar.Moon->rotateRelative(mySolar.Sun->getMC().mat[0][3], mySolar.Sun->getMC().mat[1][3],  mySolar.Sun->getMC().mat[2][3], 0, -1, 0, 5);
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
	this->size = this->size + size ;

}
void fish::faceleft() { //from facing right
	//flip eyes
    reye.translate(-size*1.35*2,0,0) ;
    leye.translate(-size*1.35*2,0,0) ;
    //flip fin
    dorsal.translate(size*0.3*2,0,0) ;
    dorsal.rotateMC(0,0,1, -30) ;
    //tail flip
    tail.translate(2*size*2.65, 0, 0) ;
    tail.rotateMC(0,0,1,180) ;
    facing = 1 ;
}
void fish::faceright() { //from facing left
	//flip eyes
    reye.translate(size*1.35*2,0,0) ;
    leye.translate(size*1.35*2,0,0) ;
    //flip fin
    dorsal.translate(-size*0.3*2,0,0) ;
    dorsal.rotateMC(0,0,1, 30) ;
    //tail flip
    tail.translate(-2*size*2.65, 0, 0) ;
    tail.rotateMC(0,0,1,180) ;
    facing = 0 ;

}
 void fish::facefront() { //from facing right
	 //rotate body
	 body.rotateMC(0,1,0,90) ;
	 //reset eyes
	 reye.translate(-size*1.35, 0, -0.7*size) ;
	 leye.translate(-size*1.35, 0, 0.7*size) ;
	 //reposition eyes
	 reye.translate(-0.7*size,0,size*1.35) ;
	 leye.translate(0.7*size,0,size*1.35) ;
	 //move tail
	 tail.translate(size*2.65, 0, 0) ;
	 tail.rotateMC(0,0,1,-270) ;

	 tail.rotateMC(0,1,0,90) ;
	 tail.translate(0,0,-size*2.65) ;
	 tail.rotateMC(1,0,0,90) ;
	 //move dorsal
	 dorsal.translate(size*0.3,0,0) ;
	 dorsal.translate(0,0,-size*0.3) ;
	 dorsal.rotateMC(0,1,0, 270) ;
	 //arms
	 rarm.translate(0,0,-size*0.60) ;
	 larm.translate(0,0,size*0.6) ;
	 rarm.translate(-size*0.60,0,0) ;
	 larm.translate(size*0.6,0,0) ;
	 rarm.rotateMC(0,1,0,270) ;
	 larm.rotateMC(0,1,0,270) ;
	 facing = 2 ;

 }
 void fish::faceback() { //from facing right
	 //rotate body
	 body.rotateMC(0,1,0,90) ;
	 //reset eyes
	 reye.translate(-size*1.35, 0, -0.7*size) ;
	 leye.translate(-size*1.35, 0, 0.7*size) ;
	 //reposition eyes
	 reye.translate(0.7*size,0,-size*1.35) ;
	 leye.translate(-0.7*size,0,-size*1.35) ;
	 //move tail
	 tail.translate(size*2.65, 0, 0) ;
	 tail.translate(0, 0, size*2.65) ;
	 tail.rotateMC(0,1,0,90) ;
	 //move dorsal
	 dorsal.translate(size*0.3,0,0) ;
	 dorsal.translate(0,0,size*0.3) ;
	 dorsal.rotateMC(0,1,0, 90) ;
	 //arms
	 rarm.translate(0,0,-size*0.60) ;
	 larm.translate(0,0,size*0.6) ;
	 rarm.translate(-size*0.60,0,0) ;
	 larm.translate(size*0.6,0,0) ;
	 rarm.rotateMC(0,1,0,270) ;
	 larm.rotateMC(0,1,0,270) ;
	 facing = 3 ;

 }
 void fish::fronttoright() { //from facing right
	 //rotate body
	 body.rotateMC(0,1,0,-90) ;
	 //reset eyes
	 reye.translate(size*1.35, 0, 0.7*size) ;
	 leye.translate(size*1.35, 0, -0.7*size) ;
	 //reposition eyes
	 reye.translate(0.7*size,0,-size*1.35) ;
	 leye.translate(-0.7*size,0,-size*1.35) ;
	 //move tail
	 tail.translate(-size*2.65, 0, 0) ;
	 tail.rotateMC(0,0,1,270) ;

	 tail.rotateMC(0,1,0,-90) ;
	 tail.translate(0,0,size*2.65) ;
	 tail.rotateMC(1,0,0,-90) ;
	 tail.rotateMC(0,0,1,180) ;
	 //move dorsal
	 dorsal.translate(-size*0.3,0,0) ;
	 dorsal.translate(0,0,size*0.3) ;
	 dorsal.rotateMC(0,1,0, -270) ;
	 //arms
	 rarm.translate(0,0,size*0.60) ;
	 larm.translate(0,0,-size*0.6) ;
	 rarm.translate(size*0.60,0,0) ;
	 larm.translate(-size*0.6,0,0) ;
	 rarm.rotateMC(0,1,0,-270) ;
	 larm.rotateMC(0,1,0,-270) ;
	 facing = 0 ;


 }
 void fish::backtoright() { //from facing right
	 //rotate body
	 body.rotateMC(0,1,0,-90) ;
	 //reset eyes
	 reye.translate(size*1.35, 0, 0.7*size) ;
	 leye.translate(size*1.35, 0, -0.7*size) ;
	 //reposition eyes
	 reye.translate(-0.7*size,0,size*1.35) ;
	 leye.translate(0.7*size,0,size*1.35) ;
	 //move tail
	 tail.translate(-size*2.65, 0, 0) ;
	 tail.translate(0, 0, -size*2.65) ;
	 tail.rotateMC(0,1,0,-90) ;
	 //move dorsal
	 dorsal.translate(-size*0.3,0,0) ;
	 dorsal.translate(0,0,-size*0.3) ;
	 dorsal.rotateMC(0,1,0, -90) ;
	 //arms
	 rarm.translate(0,0,size*0.60) ;
	 larm.translate(0,0,-size*0.6) ;
	 rarm.translate(size*0.60,0,0) ;
	 larm.translate(-size*0.6,0,0) ;
	 rarm.rotateMC(0,1,0,-270) ;
	 larm.rotateMC(0,1,0,-270) ;
	 facing = 0 ;

 }

 void fish::swim(float speed) {
	this->hitglass() ;
	if (eating ==0) {
	this->life() ;
	}
	else if(eating == 1){
		this->towardsfood() ;
	}
	 if(facing == 0) { // swimming right
		 tfish(speed,0,0) ;
	 }
	 if(facing == 1) { //swimming left
		 tfish(-speed,0,0) ;
	 }
	 if(facing == 2) { //swimming front
		 tfish(0,0,speed) ;
	 }
	 if (facing == 3) { //swimming to back
		 tfish(0,0,-speed) ;
	 }
	 if(rising == 1) {
		 tfish(0,speed,0) ;
	 }
	 if(rising == 0) {
		 tfish(0,-speed,0) ;
	 }
 }

void fish::hitglass(){ // spins the fish if he hits a bound
if(xp > maxx) {
	this->faceleft() ;
	return ;
}
if(xp < minx) {
	this->faceright() ;
	return ;
}
if(zp > maxz) {
	this->fronttoright() ;
	this->faceback() ;
	return ;
}
if(zp < minz) {
	this->backtoright() ;
	this->facefront() ;
	return ;
}
if(yp > maxy) {
	rising = 0 ;
	return ;
}
if(yp < miny) {
	rising = 1 ;
	return ;
}

 }
void fish::life() { //determines random fish movements
	if(abs(maxx - xp) > 0.5 && abs(minx - xp) > 0.5 && abs(minz - zp) > 0.5 &&  abs(maxz - zp) > 0.5) {
	int v1 = rand() % 100;
	if(v1 > 0 && v1 < 7) {
		rturn() ;
	if(v1 > 0 && v1 < 2) {
		rising = 0 ;
	}
	else {
		rising = 1 ;
	}
	}
	}
}
void fish::rturn() { //determines random fish turn directions
this->toright() ;
int look = rand()% 4 ;
if(look == 0) {
	return ;
}
if(look == 1) {
	this->faceleft() ;
	return ;
}
if(look == 2) {
	this->facefront() ;
}
if(look == 3) {
	this->faceback() ;
}
}
void fish::toright() { //sets the fish to base (right face)
if(facing == 0) {
	return ;
}
if (facing == 1){
	this->faceright() ;
	return ;
}
if(facing ==2 ) {
	this->fronttoright() ;
	return ;
}
if(facing == 3) {
	this->backtoright() ;
	return ;
}
}
void fish::food(float x, float y, float z) { //entices the fish to a position
	this->toright() ;
	fx = x ;
	fy = y ;
	fz = z ;
}

void fish::towardsfood(){
if(abs(xp - fx) < 0.3 && abs(zp - fz) < 0.3 && abs(yp - fy) < 0.3){
	eating = 0 ;
	return ;
}
if(yp > fy){
	rising = 0 ;
}
if(yp < fy){
	rising = 1 ;
}
if(xp > fx) {
	this->toright() ;
	this->faceleft() ;
	return ;
}
if(xp < fx) {
	this->toright() ;
	return ;
}
if(zp > fz){
	this->toright() ;
	this->faceback() ;
	return ;
}
if(zp < fz){
	this->toright() ;
	this->facefront() ;
	return ;
}

}

void fish::setcolor() {
    body.textureID =  textureID2 + 1;
    tail.textureID = textureID2 ;
    dorsal.textureID = textureID2 ;
    rarm.textureID = textureID2 ;
    larm.textureID = textureID2 ;
}


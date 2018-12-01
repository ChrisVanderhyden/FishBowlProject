
#include "World.hpp"
#include "Pyramid.hpp"
#include "House.hpp"
#include "table/table_leg.hpp"
#include "table/table_top.hpp"
#include "pebble.hpp"
#include "rectangle.hpp"
#include "tank.hpp"
#include "fish.hpp"
extern GLint selected;


extern GLint isAll;
fish *myfish ;
fish *fish2  ;
tank *t ;
float tmaxx, tminx, tmaxy, tminy, tmaxz, tminz ; //tank parameters
float tox, toy, toz ; //middle of the tank
int nfish = 5 ; //number of fish
float randsize() ;
int randcol() ;
World::World() {
	counter = 4;
	t = new tank() ;
	//back left leg
	list[0] = new table_leg();
	list[0]->translate(-2.5, -7, -2);

	//back right leg
	list[3] = new table_leg();
	list[3]->translate(2.5, -7, -2);

	//front left leg
	list[1] = new table_leg();
	list[1]->translate(-2.5, -7,2.5);

	//front right leg
	list[2] = new table_leg();
	list[2]->translate(2.5, -7, 2.5);

	//front right leg
	//tank params
	tminx = -4.6 ;
	tmaxx = 0.8 ;
	tminy = -4 ;
	tmaxy = -1.45 ;
	tmaxz = 2.5 ;
	tminz = -1.7 ;
	tox = - 3 ;
	toy = - 3 ;
	toz = 1.5 ;
	for(int i = 0 ; i < nfish ; i++) {
		float si = randsize() ;
		fishes[i] = new fish(si) ;
		fishes[i]->tfish(tox,toy,toz) ;
		fishes[i]->minx =  tminx ;
		fishes[i]->maxx = tmaxx ;
		fishes[i]->maxy = tmaxy;
		fishes[i]->miny = tminy;
		fishes[i]->maxz = tmaxz ;
		fishes[i]->minz = tminz ;
		int col = randcol() ;
		fishes[i]->textureID2 = col ;
		fishes[i]->setcolor() ;
	}
//	myfish->tfish(tox,toy,toz) ;
//	fish2->tfish(tox,toy,toz) ;
//
//	myfish->minx =  tminx ;
//	myfish->maxx = tmaxx ;
//	myfish->maxy = tmaxy;
//	myfish->miny = tminy;
//	myfish->maxz = tmaxz ;
//	myfish->minz = tminz ;
//
//	fish2->minz = tminz ;
//	fish2->maxz = tmaxz ;
//	fish2->maxy = tmaxy ;
//	fish2->miny = tminy ;
//	fish2->maxx = tmaxx ;
//	fish2->minx = tminx ;
	//fish2->facefront() ;
	//myfish->faceleft() ;
	t->translate(0,-3.6,0) ;
	t->rotate(0,1,0,0) ;

}

World::~World(){
	for (int i=0; i < counter; i++)
		delete list[i];
}


void World::drawWorld() {
	if (isAll) {
		for (int i=0; i<counter; i++){
		list[i]->draw();
		}
		pebble peb ;

		peb.draw() ;
//		table_top table ;
//		table.translate(0, -5, 0);
//		table.draw() ;
		rectangle *rec = new rectangle(); //ytop ybot zcl zfar xl xr
		rec->set(5, 0.25, -0.25, 4.25, -4.25, -6.25, 6.25); //ytop ybot zcl zfar xl xr
		rec->translate(0,-5,0) ;
		rec->draw() ;
		t->draw() ; //draw table
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D,texture[5]);
		for(int i = 0 ; i < nfish ; i++) {
			fishes[i]->draw() ;
		}
	}
	else
		list[selected]->draw();
}
void World::fishdance() {
	for(int i = 0 ; i < nfish ; i++) {
		fishes[i]->swim(0.1) ;
	}
}

void World::resetWorld(){
	list[0]->reset();
	list[1]->reset();
	list[2]->reset();
}
void World::feedfish(float x, float y, float z) {
myfish->food(x,y,z) ;
fish2->food(x,y,z) ;
}
float randsize() {
	int v1 = rand() % 10;
	float si = -0.7 ;
	if (v1 > 0 && v1 < 3) {
		si = -0.8 ;
		return si ;
	}
	if (v1 > 3 && v1 < 5) {
		si = -0.6 ;
		return si ;
	}
	if (v1 > 5 && v1 < 7) {
		si = -0.5 ;
		return si ;
	}
	if (v1 > 7 && v1 < 9) {
		si = -0.9 ;
		return si ;
	}
	else {return si;
	}
	}
int randcol() {
	int v1 = rand() % 3;
	if (v1 == 0) {
		return 7 ;
	}
	if (v1 == 1) {
		return 8 ;
	}
	if (v1 == 2) {
		return 9 ;
	}
	return 10 ;
	}




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

World::World() {
	counter = 4;


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
		tank *t = new tank() ;
		t->translate(0,-3.6,0) ;
		t->rotate(0,1,0,0) ;
		t->draw() ;
		fish *f = new fish() ;
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D,texture[5]);
		f->draw() ;
	}
	else
		list[selected]->draw();
}

void World::resetWorld(){
	list[0]->reset();
	list[1]->reset();
	list[2]->reset();
}


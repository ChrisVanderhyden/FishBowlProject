/*
 * HBF
 */
#ifndef CWORLD_HPP
#define CWORLD_HPP

#include "Cube.hpp"
#include "solar/Sphere.hpp"
#include "fish.hpp"
//#include "mesh.hpp"
#include <iostream>
#include <list>
#include <vector>

class World {

public:
	GLint counter;
	Shape *list[5];
	fish *fishes[10];
	World();
	~World();
	void drawWorld();  // draw all objects in the world
	void resetWorld(); //resets all objects
	void fishdance() ;
	void feedfish(float x, float y, float z) ;
};

#endif

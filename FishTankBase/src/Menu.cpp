#include "Menu.hpp"

extern GLint coordinate, selected;
extern GLint type, xBegin, a4option;
extern World myWorld;
extern Camera myCamera;
extern Light myLight;
extern bool isShading, isTexture;

extern GLint a3option;

//extern GLuint ProgramObject;

//extern GLint solarAnimation;
extern Solar mySolar;
extern fish *myfish ;
extern GLint isAll;

void fishMove(int i) ;

// light properties
GLfloat ambient[] = { 0.1f, 0.1f, 0.3f, 1.0f };
GLfloat diffuse[] = { .6f, .6f, 1.0f, 1.0f };
GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat positionSolar[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat position[] = { 1.8, 1.8, 1.5, 1.0 };
GLfloat lmodel_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat local_view[] = { 0.0 };

//Material
GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat mat_ambient_color[] = { 1, 1, 1, 1 };
GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 1, 1, 1, 1 };

void menu() {
	GLint Object_Menu = glutCreateMenu(ObjSubMenu);
	glutAddMenuEntry(" Cube ", 1);
	glutAddMenuEntry(" Pyramid", 2);
	glutAddMenuEntry(" House ", 3);

	GLint MCTrans_Menu = glutCreateMenu(MCTransMenu);
	glutAddMenuEntry(" Rotate x ", 1);
	glutAddMenuEntry(" Rotate y ", 2);
	glutAddMenuEntry(" Rotate z", 3);
	glutAddMenuEntry(" Scale", 4);

	GLint WCTrans_Menu = glutCreateMenu(WCTransMenu);
	glutAddMenuEntry(" Rotate x ", 1);
	glutAddMenuEntry(" Rotate y ", 2);
	glutAddMenuEntry(" Rotate z", 3);
	glutAddMenuEntry(" Translate x ", 4);
	glutAddMenuEntry(" Translate y ", 5);
	glutAddMenuEntry(" Translate z", 6);

	GLint VCTrans_Menu = glutCreateMenu(VCTransMenu);
	glutAddMenuEntry(" Rotate x ", 1);
	glutAddMenuEntry(" Rotate y ", 2);
	glutAddMenuEntry(" Rotate z", 3);
	glutAddMenuEntry(" Translate x ", 4);
	glutAddMenuEntry(" Translate y ", 5);
	glutAddMenuEntry(" Translate z", 6);
	glutAddMenuEntry(" Clipping Near ", 7);
	glutAddMenuEntry(" Clipping Far ", 8);


	GLint Light_Menu = glutCreateMenu(LightMenu);
	glutAddMenuEntry(" Rotate x ", 1);
	glutAddMenuEntry(" Rotate y ", 2);
	glutAddMenuEntry(" Rotate z", 3);
	glutAddMenuEntry(" Translate x ", 4);
	glutAddMenuEntry(" Translate y ", 5);
	glutAddMenuEntry(" Translate z", 6);
	glutAddMenuEntry(" Point Light Intensity I", 7);
	glutAddMenuEntry(" Point Light Reflection Rd", 8);
	glutAddMenuEntry(" Ambient Reflection Ra",9);
	glutAddMenuEntry(" Show Point Light ", 10);
	glutAddMenuEntry(" Hide Point Light ", 11);

	//A_3 menu
	GLint A3_Menu = glutCreateMenu(A3Menu);
	glutAddMenuEntry(" Show Table", 1);
	glutAddMenuEntry(" OpenGL Hidden Face Removal", 2);
	glutAddMenuEntry(" My Light & Shading ", 3);
	glutAddMenuEntry(" OpenGL Light & Shading", 4);
	glutAddMenuEntry(" Object animation ", 5);
	glutAddMenuEntry(" Simple Solar System ", 6);

	GLint Rotation_Menu = glutCreateMenu(RotationMenu);
	glutAddMenuEntry(" R->45 ", 1);
	glutAddMenuEntry(" R->90 ", 2);
	glutAddMenuEntry(" R->135 ", 3);
	glutAddMenuEntry(" R->180 ", 4);
	glutAddMenuEntry(" R->225 ", 5);
	glutAddMenuEntry(" R->270 ", 6);
	glutAddMenuEntry(" R->315 ", 7);
	glutAddMenuEntry(" R->360 ", 8);
	glutAddMenuEntry(" S->5 ", 9);
	glutAddMenuEntry(" S->10 ", 10);
	glutAddMenuEntry(" S->15 ", 11);
	glutAddMenuEntry(" T->5 ", 12);
	glutAddMenuEntry(" T->10 ", 13);
	glutAddMenuEntry(" T->15 ", 14);
	glutAddMenuEntry(" T->20 ", 15);
	glutAddMenuEntry(" T->25 ", 16);

	//A_4 menu
	GLint A4_Menu = glutCreateMenu(A4Menu);
	glutAddMenuEntry("Control Point Selection ", 1);
	glutAddMenuEntry("Bezier Curve Generation ", 2);
	glutAddMenuEntry("Rotation Surface Generation ", 3);
	glutAddSubMenu("Rotation Configuration ", Rotation_Menu);
	glutAddMenuEntry("Wired Mesh ", 4);
	glutAddMenuEntry("Solid Mesh OpenGL Shading ", 5);
	glutAddMenuEntry("Solid Mesh GLSL Shading ", 6);
	glutAddMenuEntry("Cube Texture ",7);
	glutAddMenuEntry("Animation",8);
	glutAddMenuEntry("Solar System Texture ", 9);

	glutCreateMenu(mainMenu);      // Create main pop-up menu.
	glutAddMenuEntry(" Reset ", 1);
	glutAddSubMenu(" A4", A4_Menu);
	glutAddSubMenu(" A3", A3_Menu);
	glutAddSubMenu(" Object Selection ", Object_Menu);
	glutAddSubMenu(" Model Transformations ", MCTrans_Menu);
	glutAddSubMenu(" WC Transformations ", WCTrans_Menu);
	glutAddSubMenu(" View Transformations ", VCTrans_Menu);
	glutAddSubMenu(" Light Transformations ", Light_Menu);

	glutAddMenuEntry(" Quit", 2);
}


void MCTransMenu(GLint transOption) {
	coordinate = 1;
	type = transOption;
	glutPostRedisplay();
}


void WCTransMenu(GLint transOption) {
	coordinate = 2;
	type = transOption;
	glutPostRedisplay();
}

void mainMenu(GLint option) {
	switch (option){
		case 1:
			myCamera.setDefaultCamera();
			myWorld.resetWorld();
			myLight.reset();
			mySolar.reset();

			a4option = 0;
			//BCgen = 0;
			//BCRotation = 0;

			glUseProgram(0);  // disable GLSL shader

			glutIdleFunc(NULL);
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0);
			isShading = false;

			break;
		case 2:
			exit(0);
			break;
	}
	glutPostRedisplay();
}

void VCTransMenu(GLint transOption) {
	coordinate = 3;
	type = transOption;
	glutPostRedisplay();
}

void ObjSubMenu(GLint objectOption)
{
	selected = objectOption - 1;
	Matrix mp = myWorld.list[selected]->getMC();
	myCamera.setRef(mp.mat[0][3], mp.mat[1][3], mp.mat[1][3]);
	glutPostRedisplay();
}

void LightMenu(GLint transOption) {
	coordinate = 4;
	type = transOption;

	if (type == 10) {
		myLight.on = true;
	}
	else if (type == 11) {
		myLight.on = false;
	}

	glutPostRedisplay();
}

void A3Menu(GLint option) {

	glutIdleFunc(NULL);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	isShading = false;
	type = option;

	isAll = true;

	a4option = 4;  // no option

	isTexture = false;

	if(option == 1){ // my backface
		glDisable( GL_LIGHTING );
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		fishMove(1) ;
//		pebble peb ;
//		peb.draw() ;
	}
	else if(option == 2) { // OpenGL backface and depth buffer
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
	}
	else if(option == 3) { // my light & shading
		isShading = true;
		glDisable( GL_LIGHTING );
		glDisable(GL_CULL_FACE);
		glDisable(GL_DEPTH_TEST);


	}
	else if(option == 4) { // OpenGL light
			glCullFace(GL_BACK);
			glEnable(GL_CULL_FACE);
			glEnable(GL_DEPTH_TEST);

			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			glEnable(GL_NORMALIZE);

			 // Light model parameters:
			 GLfloat lmKa[] = {0.0, 0.0, 0.0, 0.0 };
			 glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmKa);
			 glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1.0);
			 glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 0.0);

			 // Spotlight Attenuation
			 GLfloat spot_direction[] = {4.0, 4.0, 4.0 };
			 GLint spot_exponent = 30;
			 GLint spot_cutoff = 180;
			 glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
			 glLighti(GL_LIGHT0, GL_SPOT_EXPONENT, spot_exponent);
			 glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, spot_cutoff);

			 GLfloat Kc = 1.0;
			 GLfloat Kl = 0.0;
			 GLfloat Kq = 0.0;
			 glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION,Kc);
			 glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, Kl);
			 glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, Kq);

			 // -------------------------------------------
			 // Lighting parameters:
			 GLfloat light_pos[] = {myLight.getMC().mat[0][3], myLight.getMC().mat[1][3], myLight.getMC().mat[1][3], 1.0f};
			 GLfloat light_Ka[]  = {1.0f, 0.5f, 0.5f, 1.0f};
			 GLfloat light_Kd[]  = {1.0f, 0.1f, 0.1f, 1.0f};
			 GLfloat light_Ks[]  = {1.0f, 1.0f, 1.0f, 1.0f};
			 glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
			 glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ka);
			 glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Kd);
			 glLightfv(GL_LIGHT0, GL_SPECULAR, light_Ks);

			 // -------------------------------------------
			 // Material parameters:
			 GLfloat material_Ka[] = {0.5f, 0.0f, 0.0f, 1.0f};
			 GLfloat material_Kd[] = {0.4f, 0.4f, 0.5f, 1.0f};
			 GLfloat material_Ks[] = {0.8f, 0.8f, 0.0f, 1.0f};
			 GLfloat material_Ke[] = {0.1f, 0.0f, 0.0f, 0.0f};
			 GLfloat material_Se = 20.0f;
			 glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
			 glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
			 glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
			 glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_Ke);
			 glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);
			glEnable(GL_LIGHT0);
		}

	else if(option == 5){ //cube animation
		a3option = 0;
		glutIdleFunc(move);
	}

	else if(option == 6){ //solar system

		a3option = 1;
		myLight.on = false;
		glDisable(GL_LIGHTING);
		glutIdleFunc(move);
	}

	glutPostRedisplay();

}


void worldTransforms(GLint x){
	GLfloat theta = (xBegin - x > 0) ? 1 : -1;
	if (type == 1) { //WC rotate x
		myWorld.list[selected]->rotateOrigin(1, 0, 0, theta * 0.5);
	}
	else if (type == 2) { //WC rotate y
		myWorld.list[selected]->rotateOrigin(0, 1, 0, theta * 0.5);
	}
	else if(type == 3) {//WC rotate z
		myWorld.list[selected]->rotateOrigin(0, 0, 1, theta * 0.5);
	}
	else if (type == 4) { //WC translate x
		myWorld.list[selected]->translate(theta * 0.02, 0, 0);
	}
	else if(type == 5){ //WC translate y
		myWorld.list[selected]->translate(0, theta * 0.02, 0);
	}
	else if(type == 6){ //WC translate z
		myWorld.list[selected]->translate(0, 0, theta * 0.02);
	}
}

void viewTransforms(GLint x){
	GLfloat theta = (xBegin - x > 0) ? 1 : -1;
	if (type == 1) { //view rotate x
		myCamera.rotate(1.0, 0.0, 0.0, theta*0.5);
	}
	else if (type == 2) { //view rotate y
		myCamera.rotate(0.0, 1.0, 0.0, theta*0.5);
	}
	else if(type == 3) { //view rotate z
		myCamera.rotate(0.0, 0.0, 1.0, theta*0.5);
	}
	else if (type == 4) { //view translate x
		myCamera.translate(theta, 0.0, 0.0);
	}
	else if(type == 5) { //view translate y
		myCamera.translate(0.0, theta, 0.0);
	}
	else if(type == 6){ //view translate z
		myCamera.translate(0.0, 0.0, theta);
	}
	else if(type == 7) {
		myCamera.dnear += theta * .1;
	}
	else if(type == 8){
		myCamera.dfar += theta *.1;
	}
}

void modelTransforms(GLint x){
	GLfloat rx, ry, rz, theta;
	theta = (xBegin - x > 0) ? 1 : -1;

	if (type == 1) { //model rotate x
		rx = myWorld.list[selected]->getMC().mat[0][0];
		ry = myWorld.list[selected]->getMC().mat[1][0];
		rz = myWorld.list[selected]->getMC().mat[2][0];
		myWorld.list[selected]->rotateMC(rx, ry, rz, theta * 0.5);
	}
	else if (type == 2) { //model rotate y
		rx = myWorld.list[selected]->getMC().mat[0][1];
		ry = myWorld.list[selected]->getMC().mat[1][1];
		rz = myWorld.list[selected]->getMC().mat[2][1];
		myWorld.list[selected]->rotateMC(rx, ry, rz, theta * 0.5);
	}else if (type == 3){  //model rotate z
		rx = myWorld.list[selected]->getMC().mat[0][2];
		ry = myWorld.list[selected]->getMC().mat[1][2];
		rz = myWorld.list[selected]->getMC().mat[2][2];
		myWorld.list[selected]->rotateMC(rx,ry,rz, theta * 0.5);
	}
	else if (type == 4) { //model scale
		myWorld.list[selected]->scaleChange(theta * 0.02);
	}
}

void lightTransforms(GLint x) {
	GLfloat theta = (xBegin - x > 0) ? 1 : -1;

	if (type == 1) {
		myLight.rotateOrigin(1, 0, 0, theta * 0.5);
	}

	else if (type == 2) {
		myLight.rotateOrigin(0.0, 1.0, 0.0, theta*0.5);
	}

	else if (type == 3) {
		myLight.rotateOrigin(0.0, 0.0, 1.0, theta*0.5);
	}

	else if (type == 4) {
		myLight.translate(theta*0.02, 0.0, 0.0);
	}

	else if (type == 5) {
		myLight.translate(0.0, theta*0.02, 0.0);
	}

	else if (type == 6) {
		myLight.translate(0.0, 0.0, theta*0.02);
	}

	else if (type == 7) {
		myLight.Increment(theta*0.02,0, 0);
	}

	else if (type == 8) {
		myLight.Increment(0, 0, theta*0.02);

	}
	else if (type == 9) {
		myLight.Increment(0, theta*0.02, 0);
	}


	position[0] = myLight.getMC().mat[0][3];
	position[1] = myLight.getMC().mat[1][3];
	position[2] = myLight.getMC().mat[2][3];
	glLightfv(GL_LIGHT0, GL_POSITION, position);

}

void A4Menu(GLint option) {
//    isAll = false;
//    a3option = 0;
//    a4option = 4;  // no option
//	isTexture = false;
//	glUseProgram(0);

	switch (option) {
		case 1:
			a4option = 0;
			fishMove(1) ;
			break;
		case 2:
			selected = 3;
			a4option = 1;
			myWorld.feedfish(0,0.5,2.5) ;
			break;

		case 3:
			selected = 3;
			a4option = 2;
			break;

		case 4:
			selected = 3;

			a4option = 2;
			glDisable(GL_DEPTH_TEST);
			glDisable(GL_CULL_FACE);
			glDisable(GL_LIGHTING);
			glDisable(GL_NORMALIZE);
			glDisable(GL_COLOR_MATERIAL);
			glDisable(GL_LIGHT0);
			break;

		case 5:
			selected = 3;
			a4option = 2;
			glEnable(GL_DEPTH_TEST); // enable OpenGL depth buffer algorithm for hidden surface removal
			glEnable(GL_CULL_FACE);
			glEnable(GL_LIGHTING);
			glEnable( GL_NORMALIZE);
			glEnable(GL_COLOR_MATERIAL);
			glEnable(GL_LIGHT0);
			glCullFace(GL_BACK);
			break;

		case 6:
			selected = 3;
			a4option = 2;

			myLight.on  = true;
			myLight.draw();
			position[0] = myLight.getMC().mat[0][3];
			position[1] = myLight.getMC().mat[1][3];
			position[2] = myLight.getMC().mat[2][3];

			glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
			glLightfv(GL_LIGHT0, GL_POSITION, position);

			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
			glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ambient);
			glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
			glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

			glEnable(GL_DEPTH_TEST); // enable OpenGL depth buffer algorithm for hidden surface removal
			glEnable(GL_CULL_FACE);
			glEnable(GL_LIGHTING);
			glEnable( GL_NORMALIZE);
			glEnable(GL_COLOR_MATERIAL);
			glEnable(GL_LIGHT0);
			glCullFace(GL_BACK);

			break;

		case 7: // cube texture
			selected = 0;
			isTexture = true;
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_TEXTURE_2D);
			glDisable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			break;

		case 8: // animation of selected object
			isTexture = true;
			glutIdleFunc(move);
			break;

		case 9: // solar system
			selected = 4;
			a4option = 3;
			isTexture = true;

			glutIdleFunc(NULL);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_CULL_FACE);
			glEnable(GL_NORMALIZE);

			//Enable material properties for lighting
			glEnable(GL_COLOR_MATERIAL);
			glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

			solarMove(1);
			break;

		default: break;

	}

	glutPostRedisplay();
}

void RotationMenu(GLint option) {
// add your implemenation
	glutPostRedisplay();
}


void move(void){
	GLfloat rx,ry,rz, tx, ty, tz;

	if(a3option == 0) {
		rx = myWorld.list[selected]->getMC().mat[0][1];
		ry = myWorld.list[selected]->getMC().mat[1][1];
		rz = myWorld.list[selected]->getMC().mat[2][1];
		myWorld.list[selected]->rotateMC(rz, ry, rz, 0.1);
	}

	else if (a3option == 1) {

		//sun
		rx = myWorld.list[0]->getMC().mat[0][1];
		ry = myWorld.list[0]->getMC().mat[1][1];
		rz = myWorld.list[0]->getMC().mat[2][1];
		myWorld.list[0]->rotateMC(rx,ry,rz, 0.05);


		// earth self rotation
		rx = myWorld.list[1]->getMC().mat[0][1];
		ry = myWorld.list[1]->getMC().mat[1][1];
		rz = myWorld.list[1]->getMC().mat[2][1];
		myWorld.list[1]->rotateMC(rx,ry,rz, 0.4);

		// earth rotate wrt sun
		tx = myWorld.list[0]->getMC().mat[0][3];
		ty = myWorld.list[0]->getMC().mat[1][3];
		tz = myWorld.list[0]->getMC().mat[2][3];
		myWorld.list[1]->translate(-tx, -ty, -tz);
		myWorld.list[1]->rotateOrigin(rx,ry,rz, 0.1);
		myWorld.list[1]->translate(tx, ty, tz);
	}

	glutPostRedisplay();

}

void solarMove(int keepGoing)
{
      mySolar.Sun->rotateMC(0, -1, 0, 5);
      mySolar.Earth->rotateMC(mySolar.Earth->getMC().mat[0][0], mySolar.Earth->getMC().mat[1][0], mySolar.Earth->getMC().mat[2][0], 5);
      mySolar.Earth->rotateRelative(mySolar.Sun->getMC().mat[0][3], mySolar.Sun->getMC().mat[1][3],  mySolar.Sun->getMC().mat[2][3], 0, -1, 0, 5);

      mySolar.Moon->rotateMC(mySolar.Moon->getMC().mat[0][0], mySolar.Moon->getMC().mat[1][0], mySolar.Moon->getMC().mat[2][0], 5);
      mySolar.Moon->rotateRelative(mySolar.Sun->getMC().mat[0][3], mySolar.Sun->getMC().mat[1][3],  mySolar.Sun->getMC().mat[2][3], 0, -1, 0, 5);
      mySolar.Moon->rotateRelative(mySolar.Earth->getMC().mat[0][3], mySolar.Earth->getMC().mat[1][3], mySolar.Earth->getMC().mat[2][3],  0, -1, 0, 5);

     if (keepGoing && a4option == 3) {
    	  glutTimerFunc(40, solarMove, 1);
      }
     glutPostRedisplay();
}
void fishMove(int cont) {
	myWorld.fishdance() ;
	glutTimerFunc(40, fishMove,1);
	glutPostRedisplay();



}

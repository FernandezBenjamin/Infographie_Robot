/**

GROUPE:
    BENJAMIN FERNANDEZ
    CAROLINE TANG SONG
    NOHA ABDELMALKI

PROJET D'INFOGRAPHIE - ANIMATION D'UN ROBOT EN 3D

**/
#include<windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>

#endif

#include<stdlib.h>
#include<stdio.h>
#include <math.h>
#include "header.h"
#include "functions.c"
#define PI 3.14159265


float epaule = 35.0;
float avant_bras = 0.0;
float coude = 0.0;
float xcoude = 3.0;
float ycoude = -2.0;
float xpoigne = 6.2;
float ypoigne = -2.0;
float tete = 90;



int main(int argc,  char **argv){

	//INITIALISATION DE GLUT ET LA CREATION DE FENETRE
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Pascal le robot");

	//INITIALISATION D'OPENGL
	initRendering();

	//ENREGISTREMENT DES FONCTIONS D'APPELS
    glutDisplayFunc(display); //AFFICHAGE DES OBJETS
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	//glutMouseWheelFunc(mouseWheel);
	glutMouseFunc(mouseWheel);



	//TRAITEMENT DES EVENEMENTS DANS LA BOUCLE PRINCIPALE DE GLUT
    glutMainLoop();
    return 0;
}

//INITIALISATION D'OPENGL: RENDU DE LA SCENE
void initRendering() {

    //ACTIVE LE Z-BUFFER
    glEnable(GL_DEPTH_TEST);


	//ACTIVATION DES COULEURS
	glEnable(GL_COLOR_MATERIAL);

	//DEFINIT LA COULEUR D'EFFACEMENT ET LA COULEUR DE FOND
	glClearColor(0.0, 0.0, 0.0, 0.0); //NOIR

	/* Les normales (crées par glNormal(*)) sont automatiquement unitaires */
	glEnable(GL_NORMALIZE);


	/* Activation du mode ombrage (shading) et lissage (smooth) des couleur */
	glShadeModel(GL_SMOOTH);

	//DEFINIT LA TAILLE D'UN PIXEL: 2.0
	glPointSize(2.0);

}
//DESSINE LE REPERE X, Y, Z
void drawAxes(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glBegin(GL_LINES);
      glVertex2i(0,0);glVertex2i(0,50);
      glVertex2i(0,0);glVertex2i(50,0);
      glVertex2i(0,0);glVertex3i(0,0,50);
    glEnd();
    glutSwapBuffers();
    glutPostRedisplay();
}

//CREATION DE LA SCENE AVEC LAMPES
void display(void){

	/* Déclaration des couleurs et positions des lampes */
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};   // Color (0.2, 0.2, 0.2)

	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};    // Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f};      // Positioned at (4, 0, 8)

	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};    // Color (0.5, 0.2, 0.2)
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};     // Coming from the direction (-1, 0.5, 0.5)

    GLfloat lightColor2[] = {0.0f, 1.0f, 0.0f, 1.0f};    // Color (0.5, 0.5, 0.5)

    GLfloat lightPos2[] = {-3.0, 0.0f, 0.0, 1.0f};      // Positioned at (-3, 0, 0)



	/* Déclaration des différents types de matière des sphères */
	GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat mat_ambient_color[] = {0.8, 0.8, 0.2, 1.0};
	GLfloat mat_diffuse[] = {0.1, 0.5, 0.8, 1.0};
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat no_shininess[] = {0.0};
	GLfloat low_shininess[] = {5.0};
	GLfloat high_shininess[] = {100.0};
	GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);



	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);


	glLoadIdentity();

    /** CAMERA **/

    //camera(); //CALCUL DE LA CAMERA
    //ON VA UNIQUEMENT CHANGER LA POSITION DE LA CAMERA
                //POSITION               //VISEE
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
    drawAxes();

	//AJOUT DE LA LUMIERE AMBIANTE
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    	// Ajout lumière positionnelle L0
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);        // lumière diffuse
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);         // position

	// Ajout lumière positionnelle L1
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor1);       // lumiére spéculaire
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);


    //COMPOSANTS DU ROBOT

    robotLeftLeg();
    robotRightLeg();

    arms(epaule,avant_bras,coude,xcoude,ycoude,xpoigne,ypoigne);

    body();

    head(tete);



	glutSwapBuffers();

	//FORCE L'AFFICHAGE
	glFlush();
}


//MISE EN FORME DE LA SCENE POUR L'AFFICHAGE
void reshape(int w, int h){
	glViewport(0, 0,(GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 200.0);

}
//TRANSFORMER LES ANGLES EN RADIAN
void setRadian(float a){

    float result;
    result = 360.0 / PI;

    a = a * result;

}

//MOUVEMENT DE LA CAMERA
//CALCUL DE LA POSITION : CAMERA CENTREE
void cameraPosition(){

    setRadian(alpha);
    setRadian(beta);
    eyeX = r * cos(beta) * sin(alpha);

    eyeY = r * sin(beta);

    eyeZ = r * cos(alpha) * cos(beta);
}
//CALCUL DE LA VISEE : CAMERA LIBRE
void cameraVisee(){
    //DEFINIR LA POSITION X1
    cameraPosition();
    centerX = (r * cos(beta) * sin(alpha)) + eyeX;

    centerY = (r * sin(beta)) + eyeY;

    centerZ = (r * cos(alpha) * cos(beta)) + eyeZ;


}
//REDEFINITION DE LA POSITION ET DE LA VISEE : FINALISATION DE LA CAMERA LIBRE
void calcul(){

    //t = X1 - X0

    cameraVisee();
    t1 = centerX - eyeX;
    t2 = centerY - eyeY;
    t3 = centerZ - eyeZ;

    //CALCUL DU LA POSITION X0
    //X0 = X0 + t(X1 - X0)
    eyeX = eyeX + (coef * t1);
    eyeY = eyeY + (coef * t2);
    eyeZ = eyeZ + (coef * t3);

    //DEPLACEMENT DU POINT DE MIRE EN PARALLELE
    //X1 = X1 + t(X1 - X0)
    centerX = centerX + (coef * t1);
    centerY = centerY + (coef * t2);
    centerZ = centerZ + (coef * t3);


}
//FONCTION CLAVIER: COMMANDES DE LA CAMERA ET LUMIERE
void keyboard(unsigned char key, int x, int y) {

		switch (key){
            case 'w':
                optionCamera = 1;
                printf("\nCamera libre");
                break;
            case 'x':
                optionCamera = 0;
                printf("\nCamera centrée");
                break;

			case 'a':
				glutPostRedisplay();
				break;

            //MOUVEMENT DE LA CAMERA
            case 'z':

				beta -= 0.2;
				r -= 0.2;

				if(optionCamera == 1){
                    cameraPosition();
				}else{
                    calcul();
				}
				glutPostRedisplay();
				break;
            case 's':

				beta += 0.2;
				r += 0.2;
				if(optionCamera == 1){
                    cameraPosition();
				}else{
                    calcul();
				}
				glutPostRedisplay();
				break;
            case 'd':

				alpha -= 0.2;
				if(optionCamera == 1){
                    cameraPosition();
				}else{
                    calcul();
				}
				glutPostRedisplay();
				break;
            case 'q':

				alpha += 0.2;
				if(optionCamera == 1){
                    cameraPosition();
				}else{
                    calcul();
				}
				glutPostRedisplay();
				break;
            case 'r':

				coef += 0.2;
				if(optionCamera == 1){
                    cameraPosition();
				}else{
                    calcul();
				}
				glutPostRedisplay();
				break;
            case 'f':

				coef -= 0.2;
				if(optionCamera == 1){
                    cameraPosition();
				}else{
                    calcul();
				}
				glutPostRedisplay();
				break;


            case 'l':
				if ((avant_bras+15.0) < -45.0){
                    avant_bras = 45.0;
                } else if ((avant_bras+15.0) > 45.0){
                    avant_bras = -45.0;
                } else {
                    avant_bras += 15.0;
                }
				glutPostRedisplay();
				break;


            case 'e':
                if (epaule == 360.0){
                    epaule = 0.0;
                } else {
                    epaule -= 30.0;
                }
                coude += 15.0;
				glutPostRedisplay();

				break;


            case 'p':
                if (epaule == 360.0){
                    epaule = 0.0;
                } else {
                    epaule += 30.0;
                }
                coude -= 15.0;
				glutPostRedisplay();

				break;



            case 'm':
                if ((avant_bras-15.0) < -45.0){
                    avant_bras = 30.0;
                } else if ((avant_bras-15.0) > 45.0){
                    avant_bras = -30.0;
                } else {
                    avant_bras -= 15.0;
                }
				glutPostRedisplay();

				break;

		}
}

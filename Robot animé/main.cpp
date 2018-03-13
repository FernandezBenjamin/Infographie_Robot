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

int main(int argc,  char **argv){

	//INITIALISATION DE GLUT ET LA CREATION DE FENETRE
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Le robot animé!");

	//INITIALISATION D'OPENGL
	initRendering();

	//ENREGISTREMENT DES FONCTIONS D'APPELS
    glutDisplayFunc(display); //AFFICHAGE DES OBJETS
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);



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


/* Création de la scène avec lampes */
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



	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);


	glLoadIdentity();

    /** CAMERA **/

    camera(); //CALCUL DE LA CAMERA
    //ON VA UNIQUEMENT CHANGER LA POSITION DE LA CAMERA
                //POSITION               //VISEE
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);


	//AJOUT DE LA LUMIERE AMBIANTE
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    	// Ajout lumière positionnelle L0
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);        // lumière diffuse
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);         // position

	// Ajout lumière positionnelle L1
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor1);       // lumiére spéculaire
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    /*glRotatef(a, 1.0, 0.0, 0.0);
    glRotatef(b, 0.0, 1.0, 0.0);
    glRotatef(c, 0.0, 0.0, 1.0);
    glTranslatef(a, b, c);*/ //     /!\

    //COMPOSANTS DU ROBOT

    robotLeg();

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
void setRadian(double a){

    double result;
    result = 180.0 / PI;

    a = a * result;

}

//MOUVEMENT DE LA CAMERA
void camera(){

    setRadian(alpha);
    setRadian(beta);
    eyeX = r * cos(beta) * sin(alpha);

    eyeY = r * sin(beta);

    eyeZ = r * cos(alpha) * cos(beta);
}
//FONCTION CLAVIER: COMMANDES DE LA CAMERA ET LUMIERE
void keyboard(unsigned char key, int x, int y) {
		switch (key){

			case 'a':
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);
				glDisable(GL_LIGHT1);
				glDisable(GL_LIGHT2);
				glutPostRedisplay();
				break;

            //MOUVEMENT DE LA CAMERA
            case 'z':
				beta += 0.2;
				glutPostRedisplay();
				break;
            case 's':
				beta -= 0.2;
				glutPostRedisplay();
				break;
            case 'd':
				alpha += 0.2;
				glutPostRedisplay();
				break;
            case 'q':
				alpha -= 0.2;
				glutPostRedisplay();
				break;
            case 'r':
				r += 0.2;
				glutPostRedisplay();
				break;
            case 'f':
				r -= 0.2;
				glutPostRedisplay();
				break;

		}
}

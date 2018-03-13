#include<windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include<stdlib.h>
#include<stdio.h>
#define PI 3.14159265
void robotLeg(){

    //SPHERE PIVOT 1
    glPushMatrix();
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glutSolidSphere(0.7, 20.0, 20.0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glTranslatef(0.0f, -1.0f, 0.0f);
            glPushMatrix();
                glScalef(1.0, 2.5, 0.7);
                glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();

        //PIED
        glPushMatrix();
            glTranslatef(0.0f, -2.5f, 0.0f);
            glPushMatrix();
                glScalef(3.5, 0.4, 2.0);
                glutSolidCube(1.0);
            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
}
void arm(){

    //EPAULE
    glPushMatrix();
		glTranslatef(-1.0f, 0.0f, 0.0f);
		glutSolidSphere(0.5, 20.0, 20.0);
	glPopMatrix();


    //BRAS1 (EPAULE)
	glPushMatrix();
        glTranslatef(-1.0f, 0.0f, 0.0f);
        /*glRotated(angle, 0.0, 0.0, 1.0);
        glRotated(angle3, 0.0, 1.0, 0.0);
        glRotated(angle5, 1.0, 0.0, 0.0);*/
        glTranslatef(1.0f, 0.0f, 0.0f);
        glPushMatrix();
            glScalef(2.0, 1.0, 0.5);
            glutSolidCube(1.0);
        glPopMatrix();

        //COUDE
        glPushMatrix();
            glTranslatef(1.0f, 0.0f, 0.0f);
            glutSolidSphere(0.5, 20.0, 20.0);
        glPopMatrix();

        //BRAS2
        glTranslatef(1.0f, 0.0f, 0.0f); //ON AVANCE DE 1.0: PREMIER POINT DE PIVOT
        /*glRotated(angle2, 0.0, 0.0, 1.0);
        glRotated(angle4, 0.0, 1.0, 0.0);
        glRotated(angle6, 1.0, 0.0, 0.0);*/
        glTranslatef(1.0f, 0.0f, 0.0f); //ON AVANCE DE 1.0: EXTREMITE DU BRAS = LA MOITIE DE LA LARGEUR DU QUAD
        glPushMatrix();
            glScalef(2.0, 1.0, 0.5);
            glutSolidCube(1.0);
        glPopMatrix();

        //POIGNET
        glTranslatef(0.5f, 0.0f, 0.0f); //ON AVANCE DE 1.0: PREMIER POINT DE PIVOT
        /*glRotated(angle2, 0.0, 0.0, 1.0);
        glRotated(angle4, 0.0, 1.0, 0.0);
        glRotated(angle6, 1.0, 0.0, 0.0);*/
        glTranslatef(0.5f, 0.0f, 0.0f); //ON AVANCE DE 1.0: EXTREMITE DU BRAS = LA MOITIE DE LA LARGEUR DU QUAD
        glPushMatrix();
            glutSolidCube(0.5);
        glPopMatrix();

	glPopMatrix();
}

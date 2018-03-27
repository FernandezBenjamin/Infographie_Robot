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


void robotLeftLeg(){
//robotLeg devient LeftLeg
    //SPHERE PIVOT 1
    glPushMatrix();
        glPushMatrix();
            glTranslatef(4.0f, -5.0f, 0.0f);
            glTranslatef(-2.0f, -1.0f, 0.0f);
            glutSolidSphere(0.7, 20.0, 20.0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(4.0f, -7.0f, 0.0f);
            glTranslatef(-2.0f, -1.0f, 0.0f);
            glPushMatrix();
                glScalef(1.0, 2.5, 0.7);
                glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();

        //PIED
        glPushMatrix();
            glTranslatef(4.0f, -8.5f, 0.0f);
            glTranslatef(-2.0f, -1.0f, 0.0f);
            glPushMatrix();
                glScalef(2.0, 0.4, 3.5);
                glutSolidCube(1.0);
            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
}

void robotRightLeg(){
//robotLeg devient LeftLeg
    //SPHERE PIVOT 1
    glPushMatrix();
        glPushMatrix();
            glTranslatef(-0.0f, -5.0f, 0.0f);
            glTranslatef(-2.0f, -1.0f, 0.0f);
            glutSolidSphere(0.7, 20.0, 20.0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.0f, -7.0f, 0.0f);
            glTranslatef(-2.0f, -1.0f, 0.0f);
            glPushMatrix();
                glScalef(1.0, 2.5, 0.7);
                glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();

        //PIED
        glPushMatrix();
            glTranslatef(-0.0f, -8.5f, 0.0f);
            glTranslatef(-2.0f, -1.0f, 0.0f);
            glPushMatrix();
                glScalef(2.0, 0.4, 3.5);
                glutSolidCube(1.0);
            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
}



void arms(float epaule, float avant_bras, float coude, float xcoude, float ycoude, float xpoigne, float ypoigne){


    /* Epaule */
	glPushMatrix();
		glRotatef(180.0,0.0f,1.0f,0.0f);
		glTranslatef(4.0f, 0.0f, 0.0f);
		glRotatef(90.0,0.0f,1.0f,0.0f);
		glutSolidSphere(0.8, 12.0, 12.0);



        /* Coude */
        glPushMatrix();
            glRotatef(coude,0.0,0.0,1.0f);
            glTranslatef(xcoude, ycoude, 0.0f);
            glutSolidSphere(0.8, 12.0, 12.0);
        glPopMatrix();


        /* Bras */
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(90, 0, 1, 0);
            glRotatef(coude, 1, 0, 0);
            glRotatef(epaule, 1, 0, 0);
            glBegin(GL_POLYGON);
            GLUquadricObj *obj = gluNewQuadric();
            gluCylinder(obj, 0.8, 0.8, 3.4, 30, 30);
        glPopMatrix();


        /* Avant bras */
        glPushMatrix();
            glRotatef(coude,0.0,0.0,1.0f);
            glTranslatef(xcoude, ycoude, 0.0f);
            glRotatef(90, 0, 1, 0);
            glRotatef(avant_bras, 1, 0, 0);
            glBegin(GL_POLYGON);
            GLUquadricObj *obj2 = gluNewQuadric();
            gluCylinder(obj2, 0.8, 0.5, 3.2, 30, 30);
        glPopMatrix();


        /* Poigne */
        glPushMatrix();
            glRotatef(coude,0.0,0.0,1.0f);
            glTranslatef(xpoigne, ypoigne, 0.0f);
            glRotatef(avant_bras,0.0,0.0,1.0f);
            glutSolidSphere(0.5, 12.0, 12.0);
            hand(xpoigne, ypoigne, -avant_bras, coude);
        glPopMatrix();






	glPopMatrix();


	/* Bras Droit */
	glPushMatrix();
        /* Epaule */
		glRotatef(180.0,0.0f,1.0f,0.0f);
		glTranslatef(-4.0f, 0.0f, 0.0f);
		glRotatef(90.0,0.0f,1.0f,0.0f);
		glutSolidSphere(0.8, 12.0, 12.0);



        /* Coude */
        glPushMatrix();
            glRotatef(coude,0.0,0.0,1.0f);
            glTranslatef(xcoude, ycoude, 0.0f);
            glutSolidSphere(0.8, 12.0, 12.0);
        glPopMatrix();


        /* Bras */
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(90, 0, 1, 0);
            glRotatef(coude, 1, 0, 0);
            glRotatef(epaule, 1, 0, 0);
            glBegin(GL_POLYGON);
            GLUquadricObj *obj3 = gluNewQuadric();
            gluCylinder(obj3, 0.8, 0.8, 3.4, 30, 30);
        glPopMatrix();


        /* Avant bras */
        glPushMatrix();
            glRotatef(coude,0.0,0.0,1.0f);
            glTranslatef(xcoude, ycoude, 0.0f);
            glRotatef(90, 0, 1, 0);
            glRotatef(avant_bras, 1, 0, 0);
            glBegin(GL_POLYGON);
            GLUquadricObj *obj4 = gluNewQuadric();
            gluCylinder(obj4, 0.8, 0.5, 3.2, 30, 30);
        glPopMatrix();


                /* Poigne */
        glPushMatrix();
            glRotatef(coude,0.0,0.0,1.0f);
            glTranslatef(xpoigne, ypoigne, 0.0f);
            glRotatef(avant_bras,0.0,0.0,1.0f);
            glutSolidSphere(0.5, 12.0, 12.0);
        glPopMatrix();
        hand(xpoigne, ypoigne, -avant_bras, coude);

	glPopMatrix();



}




void hand(float xcoude, float ycoude, float rotation, float rotation2){

    //MAIN

    glPushMatrix();
        glRotatef(rotation,0.0,0.0,1.0f);
        glTranslatef(xcoude, ycoude, 0.0f);
        glRotatef(rotation2,0.0,0.0,1.0f);
        glPushMatrix();
            //PAUME
            glScaled(0.7, 0.2, 0.5);
            glutSolidCube(2.0);
        glPopMatrix();
        glPushMatrix();
            finger(0.3);
        glPopMatrix();
        glPushMatrix();
            finger(-0.3);
        glPopMatrix();

    glPopMatrix();

}


void finger(float zPosition){
    //CREATION DE DEUX DOIGTS IDENTIQUES A POSITION Z DIFFERENTES

    glTranslatef(0.7f, 0.0f, zPosition);
    glPushMatrix();
        //JOINT ENTRE LA PAUME ET LE DOIGT 1.1
        glutSolidSphere(0.2, 12.0, 12.0);
    glPopMatrix();
    glTranslatef(0.35f, 0.0f, 0.0f);
    glPushMatrix();
        //DOIGT 1.1
        glScaled(0.4, 0.2, 0.2);
        glutSolidCube(1.5);

    glPopMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);
    glPushMatrix();
        //JOINT LE DOIGT 1.1: AVANCE DE 0.75 EN X
        glutSolidSphere(0.2, 12.0, 12.0);
    glPopMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);
    glPushMatrix();
        //DOIGT 1.2
        glScaled(0.4, 0.2, 0.2);
        glutSolidCube(1.5);
    glPopMatrix();



}

void body(){

/* Corps */
	glPushMatrix();

        /* Tete */
		glRotatef(180.0,0.0f,1.0f,0.0f);
		glTranslatef(0.0f, 0.0f, 1.0f);
		glRotatef(90.0,0.0f,1.0f,0.0f);
		glutSolidSphere(3.4, 12.0, 12.0);

        /* Base 1 */
        glPushMatrix();
            glTranslatef(-1.0f, 2.0f, 0.0f);
            glRotatef(0.0,0.0,0.0,1.0f);
            glTranslatef(1.0f, -2.0f, 0.0f);
            glRotatef(90, 1, 0, 0);
            glRotatef(0.0, 1, 0, 0);
            glBegin(GL_POLYGON);
            GLUquadricObj *base1 = gluNewQuadric();
            gluCylinder(base1, 3.4, 3.4, 3.5, 30, 30);
        glPopMatrix();

        /* Base 2 */
        glPushMatrix();
            glTranslatef(-1.0f, 0.0f, 0.0f);
            glRotatef(0.0,0.0,0.0,1.0f);
            glTranslatef(1.0f, -3.5f, 0.0f);
            glRotatef(90, 1, 0, 0);
            glRotatef(0.0, 1, 0, 0);
            glBegin(GL_POLYGON);
            GLUquadricObj *base2 = gluNewQuadric();
            gluCylinder(base2, 3.4, 3.4, 3, 30, 30);
        glPopMatrix();

	glPopMatrix();

}




void head(float angle){


    glPushMatrix();

        /* Tete */
		glRotatef(180.0,0.0f,1.0f,0.0f);
		glTranslatef(0.0f, 1.0f, -1.0f);
		glRotatef(angle,0.0f,1.0f,0.0f);
		glutSolidSphere(2.5, 12.0, 12.0);



	glPopMatrix();
}

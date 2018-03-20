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









void arms(float epaule, float avant_bras, float coude, float xcoude, float ycoude){


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

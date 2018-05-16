#include<windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include<stdlib.h>
#include<stdio.h>
#include "Robot.h"

#define PI 3.14159265

Robot::Robot(float epaule, float avant_bras, float coude, float xcoude, float ycoude, float xpoigne, float ypoigne, float angle){
    this->epaule = epaule;
    this->avant_bras = avant_bras;
    this->coude = coude;
    this->xcoude = xcoude;
    this->ycoude = ycoude;
    this->xpoigne = xpoigne;
    this->ypoigne = ypoigne;
    this->angle = angle;
    this->trans_x = 0;
    this->trans_y = 0;
    this->trans_z = 0;


    for (int i = 0; i < MEMBERS_MAX; i++)
    {
        textures[i] = 0;
    }
}


void Robot::robotLeftLeg(){
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
                glScalef(0.5, 1.25, 0.35);
                glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();

        //PIED
        glPushMatrix();
            glTranslatef(4.0f, -8.5f, 0.0f);
            glTranslatef(-2.0f, -1.0f, 0.0f);
            glPushMatrix();
                glScalef(1.0, 0.2, 1.75);
                glutSolidCube(1.0);
            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
}


void Robot::robotRightLeg(){
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
                glScalef(0.5, 1.25, 0.35);
                glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();

        //PIED
        glPushMatrix();
            glTranslatef(-0.0f, -8.5f, 0.0f);
            glTranslatef(-2.0f, -1.0f, 0.0f);
            glPushMatrix();
                glScalef(1.0, 0.2, 1.75);
                glutSolidCube(1.0);
            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
}


void Robot::arms(){





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
            glRotatef(-avant_bras,0.0,0.0,1.0f);
            glTranslatef(xpoigne, ypoigne, 0.0f);
            glRotatef(avant_bras,0.0,0.0,1.0f);
            glutSolidSphere(0.5, 12.0, 12.0);
        glPopMatrix();

	glPopMatrix();



}


void Robot::hand(float xcoude, float ycoude, float rotation, float rotation2){

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


void Robot::finger(float zPosition){
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


void Robot::body(){

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


void Robot::head(){

    glEnable(GL_TEXTURE_2D);


    glBindTexture(GL_TEXTURE_2D,textures[HEAD1]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);


    glPushMatrix();
        /* Tete */
		glRotatef(180.0,0.0f,1.0f,0.0f);
		glTranslatef(0.0f, 1.0f, -1.0f);
		glRotatef(angle,0.0f,1.0f,0.0f);
		gluSphere(params,2.5, 12, 12);
	glPopMatrix();
}




void Robot::construct(){


    glEnable(GL_TEXTURE_2D);

    glPushMatrix();

		glTranslatef(0.0f, 1.0f, 0.0f);
		glScalef(0.2f,0.2f,0.2f);
        this->robotLeftLeg();
        this->robotRightLeg();

        this->arms();

        this->body();

        this->head();
    glPopMatrix();


}


void Robot::draw(){

    glPushMatrix();

		glTranslatef(0.0f, 1.0f, 0.0f);
		glTranslatef(trans_x,trans_y,trans_z);
		glScalef(0.2f,0.2f,0.2f);







		/* Tête */


            glBindTexture(GL_TEXTURE_2D,textures[HEAD1]);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);


            GLUquadric* params = gluNewQuadric();
            gluQuadricTexture(params,GL_TRUE);


            glPushMatrix();
                /* Tete */
                glRotatef(180.0,0.0f,1.0f,0.0f);
                glTranslatef(0.0f, 1.0f, -1.0f);
                glRotatef(angle,0.0f,1.0f,0.0f);
                gluSphere(params,2.5, 12, 12);
            glPopMatrix();

    /* Corps */



        glPushMatrix();


                glBindTexture(GL_TEXTURE_2D,textures[HEAD2]);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);


            GLUquadric* head2 = gluNewQuadric();
            gluQuadricTexture(head2,GL_TRUE);


            /* Tete */
            glRotatef(180.0,0.0f,1.0f,0.0f);
            glTranslatef(0.0f, 0.0f, 1.0f);
            glRotatef(90.0,0.0f,1.0f,0.0f);
            gluSphere(head2,3.4, 12.0, 12.0);




            /* Base 1 */
            glPushMatrix();


                glBindTexture(GL_TEXTURE_2D, textures[BASE1]);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);



                glTranslatef(-1.0f, 2.0f, 0.0f);
                glRotatef(0.0,0.0,0.0,1.0f);
                glTranslatef(1.0f, -2.0f, 0.0f);
                glRotatef(90, 1, 0, 0);
                glRotatef(0.0, 1, 0, 0);
                glBegin(GL_POLYGON);
                GLUquadricObj *base1 = gluNewQuadric();
                gluQuadricTexture(base1,GL_TRUE);
                gluCylinder(base1, 3.4, 3.4, 3.5, 30, 30);
            glPopMatrix();


            /* Base 2 */
            glPushMatrix();



                glBindTexture(GL_TEXTURE_2D, textures[BASE2]);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);



                glTranslatef(-1.0f, 0.0f, 0.0f);
                glRotatef(0.0,0.0,0.0,1.0f);
                glTranslatef(1.0f, -3.5f, 0.0f);
                glRotatef(90, 1, 0, 0);
                glRotatef(0.0, 1, 0, 0);
                glBegin(GL_POLYGON);
                GLUquadricObj *base2 = gluNewQuadric();
                gluQuadricTexture(base2,GL_TRUE);
                gluCylinder(base2, 3.4, 3.4, 3, 30, 30);
            glPopMatrix();

        glPopMatrix();







            //MAIN
/*
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



*/




            /* Epaule */

            glBindTexture(GL_TEXTURE_2D,textures[ARMS]);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);


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
                    glRotatef(-avant_bras,0.0,0.0,1.0f);
                    glTranslatef(xpoigne, ypoigne, 0.0f);
                    glRotatef(avant_bras,0.0,0.0,1.0f);
                    glutSolidSphere(0.5, 12.0, 12.0);
                glPopMatrix();

            glPopMatrix();








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
                        glScalef(0.5, 1.25, 0.35);
                        glutSolidCube(1.0);
                    glPopMatrix();
                glPopMatrix();

                //PIED
                glPushMatrix();
                    glTranslatef(-0.0f, -8.5f, 0.0f);
                    glTranslatef(-2.0f, -1.0f, 0.0f);
                    glPushMatrix();
                        glScalef(1.0, 0.2, 1.75);
                        glutSolidCube(1.0);
                    glPopMatrix();

                glPopMatrix();
            glPopMatrix();







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
                        glScalef(0.5, 1.25, 0.35);
                        glutSolidCube(1.0);
                    glPopMatrix();
                glPopMatrix();

                //PIED
                glPushMatrix();
                    glTranslatef(4.0f, -8.5f, 0.0f);
                    glTranslatef(-2.0f, -1.0f, 0.0f);
                    glPushMatrix();
                        glScalef(1.0, 0.2, 1.75);
                        glutSolidCube(1.0);
                    glPopMatrix();

                glPopMatrix();
            glPopMatrix();

    glPopMatrix();



}



void Robot::setTextures(int face, GLuint texture)
{
    textures[face] = texture;
}

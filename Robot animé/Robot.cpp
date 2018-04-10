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

Robot::Robot(float epauleLeft, float epauleRight, float avant_bras, float coude, float xcoude, float ycoude, float xpoigne, float ypoigne, float angle, float xRotationLegLeft, float xRotationLegRight){
    this->epauleLeft = epauleLeft;
    this->epauleRight = epauleRight;

    this->avant_bras = avant_bras;
    this->coude = coude;

    this->xcoude = xcoude;
    this->ycoude = ycoude;

    this->xpoigne = xpoigne;
    this->ypoigne = ypoigne;

    this->angle = angle;

    this->xRotationLegRight = xRotationLegRight;
    this->xRotationLegLeft = xRotationLegLeft;
}


void Robot::robotLeftLeg(){
//robotLeg devient LeftLeg
    //SPHERE PIVOT 1
    glPushMatrix();

        glTranslatef(4.0f, -5.0f, 0.0f);

        glTranslatef(-2.0f, -1.0f, -1.0f);

        glutSolidSphere(0.7, 20.0, 20.0);

        //JAMBE
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(xRotationLegLeft, 1.0, 0.0, 0.0);
            glTranslatef(0.0f, -1.5f, 0.0f);
            glScalef(1.0, 3.5, 0.7);
            glutSolidCube(1.0);
            //PIED
            glPushMatrix();
                glTranslatef(0.0f, -0.5f, 0.0f);
                glPushMatrix();
                    glScalef(2.8, 0.1, 7.0);

                    glutSolidCube(1.0);
                glPopMatrix();
            glPopMatrix(); //FIN MATRICE PIED
        glPopMatrix(); //FIN MATRICE JAMBE

    glPopMatrix(); //FIN MATRICE SPHERE
}


void Robot::robotRightLeg(){
//robotLeg devient LeftLeg
    //SPHERE PIVOT 2
    glPushMatrix();

        glTranslatef(-2.0f, -5.0f, 0.0f);
        glTranslatef(0.0f, -1.0f, -1.0f);
        glutSolidSphere(0.7, 20.0, 20.0);

        //JAMBE
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(xRotationLegRight, 1.0, 0.0, 0.0);
            glTranslatef(0.0f, -1.5f, 0.0f);
            glScalef(1.0, 3.5, 0.7);
            glutSolidCube(1.0);
            //PIED
            glPushMatrix();
                glTranslatef(0.0f, -0.5f, 0.0f);
                glPushMatrix();
                    glScalef(3.0, 0.1, 7.0);
                    glutSolidCube(1.0);
                glPopMatrix();
            glPopMatrix(); //FIN MATRICE PIED
        glPopMatrix(); //FIN MATRICE JAMBE

    glPopMatrix(); //FIN MATRICE SPHERE

}


void Robot::arms(){


    /* Epaule */
	glPushMatrix();
		glTranslatef(-4.0f, 0.0f, 0.0f);
		glRotatef(180.0,0.0f,1.0f,0.0f);
		glRotatef(90.0,0.0f,1.0f,0.0f);
		glutSolidSphere(0.8, 12.0, 12.0);

        /* Bras */
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(90, 0, 1, 0);
            glRotatef(coude, 1, 0, 0);
            glRotatef(epauleLeft, 1, 0, 0);
            glPushMatrix();
                glBegin(GL_POLYGON);
                GLUquadricObj *obj = gluNewQuadric();
                gluCylinder(obj, 0.8, 0.8, 3.4, 30, 30);
            glPopMatrix();
            //COUDE
            glPushMatrix();

                glTranslatef(0.0f, 0.0f, 3.4f);
                glutSolidSphere(0.8, 12.0, 12.0);

                //AVANT BRAS
                glPushMatrix();
                    //glRotatef(coude,0.0,0.0,1.0f);
                    glRotatef(avant_bras, 1, 0, 0);
                    glBegin(GL_POLYGON);
                    GLUquadricObj *obj2 = gluNewQuadric();
                    gluCylinder(obj2, 0.8, 0.5, 3.2, 30, 30);
                    //POIGNET
                    glPushMatrix();
                        glTranslatef(0.0f, 0.0f, 3.2f); //AVANCE DE 3.2 EN Z
                        glutSolidSphere(0.5, 12.0, 12.0);

                        //MAIN
                        glPushMatrix();

                            glPushMatrix();
                                //PAUME
                                glRotatef(90.0f, 0.0f, 1.0f, 0.0f); //REPOSITIONNEMENT DE LA PAUME
                                glScaled(0.7, 0.2, 0.5); //DIMENSIONNEMENT DE LA PAUME
                                glutSolidCube(2.0); //CREATION DE LA PAUME DE TYPE CUBE

                            glPopMatrix();
                            //PREMIER DOIGT
                            glPushMatrix();
                                //JOINT ENTRE LA PAUME ET LE DOIGT 1.1
                                glTranslatef(0.3f, 0.0f, 0.8f);
                                glutSolidSphere(0.2, 12.0, 12.0);
                                glPushMatrix();
                                    //DOIGT 1.1
                                    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); //ROTATION DE 90°
                                    glScaled(0.4, 0.2, 0.2);
                                    glutSolidCube(1.5);
                                glPopMatrix();

                                glPushMatrix();
                                    glTranslatef(0.0f, 0.0f, 0.6f);
                                    glutSolidSphere(0.2, 12.0, 12.0);
                                    glPushMatrix();
                                        //DOIGT 1.2
                                        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                                        glScaled(0.4, 0.2, 0.2);
                                        glutSolidCube(1.5);
                                    glPopMatrix();
                                glPopMatrix();

                            glPopMatrix(); //FIN MATRICE PREMIER DOIGT

                            //SECOND DOIGT
                            glPushMatrix();
                                glTranslatef(-0.3f, 0.0f, 0.8f);
                                glutSolidSphere(0.2, 12.0, 12.0);
                                glPushMatrix();
                                    //DOIGT 1.1
                                    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                                    glScaled(0.4, 0.2, 0.2);
                                    glutSolidCube(1.5);
                                glPopMatrix();

                                glPushMatrix();
                                    glTranslatef(0.0f, 0.0f, 0.6f);
                                    glutSolidSphere(0.2, 12.0, 12.0);
                                    glPushMatrix();
                                        //DOIGT 1.2
                                        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                                        glScaled(0.4, 0.2, 0.2);
                                        glutSolidCube(1.5);
                                    glPopMatrix();
                                glPopMatrix();
                            glPopMatrix(); //FIN MATRICE SECOND DOIGT


                        glPopMatrix(); //FIN MATRICE MAIN

                    glPopMatrix(); //FIN MATRICE POIGNET


                glPopMatrix(); //FIN MATRICE AVANT BRAS
            glPopMatrix(); //FIN MATRICE COUDE
         glPopMatrix(); //FIN DE LA MATRICE BRAS
	glPopMatrix(); //FIN MATRICE BRAS GAUCHE


	/* Bras Droit */
	glPushMatrix();
        /* Epaule */
        glTranslatef(4.0f, 0.0f, 0.0f);
		glRotatef(180.0,0.0f,1.0f,0.0f);
		glRotatef(90.0,0.0f,1.0f,0.0f);
		glutSolidSphere(0.8, 12.0, 12.0);

        /* Bras */
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(90, 0, 1, 0);
            glRotatef(coude, 1, 0, 0);
            glRotatef(epauleRight, 1, 0, 0);
            glBegin(GL_POLYGON);
            GLUquadricObj *obj3 = gluNewQuadric();
            gluCylinder(obj3, 0.8, 0.8, 3.4, 30, 30);
             /* Coude */
            glPushMatrix();
                glRotatef(coude,0.0,0.0,1.0f);
                glTranslatef(0.0f, 0.0f, 3.4f);
                glutSolidSphere(0.8, 12.0, 12.0);

                /* Avant bras */

                glPushMatrix();
                    glRotatef(coude,0.0,0.0,1.0f);
                    glRotatef(avant_bras, 1, 0, 0);
                    glBegin(GL_POLYGON);
                    GLUquadricObj *obj4 = gluNewQuadric();
                    gluCylinder(obj4, 0.8, 0.5, 3.2, 30, 30);
                    //POIGNET
                    glPushMatrix();
                        glTranslatef(0.0f, 0.0f, 3.2f); //AVANCE DE 3.2 EN Z
                        glutSolidSphere(0.5, 12.0, 12.0);

                        //MAIN
                        glPushMatrix();

                            glPushMatrix();
                                //PAUME
                                glRotatef(90.0f, 0.0f, 1.0f, 0.0f); //REPOSITIONNEMENT DE LA PAUME
                                glScaled(0.7, 0.2, 0.5); //DIMENSIONNEMENT DE LA PAUME
                                glutSolidCube(2.0); //CREATION DE LA PAUME DE TYPE CUBE

                            glPopMatrix();
                            //PREMIER DOIGT
                            glPushMatrix();
                                //JOINT ENTRE LA PAUME ET LE DOIGT 1.1
                                glTranslatef(0.3f, 0.0f, 0.8f);
                                glutSolidSphere(0.2, 12.0, 12.0);
                                glPushMatrix();
                                    //DOIGT 1.1
                                    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); //ROTATION DE 90°
                                    glScaled(0.4, 0.2, 0.2);
                                    glutSolidCube(1.5);
                                glPopMatrix();

                                glPushMatrix();
                                    glTranslatef(0.0f, 0.0f, 0.6f);
                                    glutSolidSphere(0.2, 12.0, 12.0);
                                    glPushMatrix();
                                        //DOIGT 1.2
                                        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                                        glScaled(0.4, 0.2, 0.2);
                                        glutSolidCube(1.5);
                                    glPopMatrix();
                                glPopMatrix();

                            glPopMatrix(); //FIN MATRICE PREMIER DOIGT

                            //SECOND DOIGT
                            glPushMatrix();
                                glTranslatef(-0.3f, 0.0f, 0.8f);
                                glutSolidSphere(0.2, 12.0, 12.0);
                                glPushMatrix();
                                    //DOIGT 1.1
                                    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                                    glScaled(0.4, 0.2, 0.2);
                                    glutSolidCube(1.5);
                                glPopMatrix();

                                glPushMatrix();
                                    glTranslatef(0.0f, 0.0f, 0.6f);
                                    glutSolidSphere(0.2, 12.0, 12.0);
                                    glPushMatrix();
                                        //DOIGT 1.2
                                        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                                        glScaled(0.4, 0.2, 0.2);
                                        glutSolidCube(1.5);
                                    glPopMatrix();
                                glPopMatrix();
                            glPopMatrix(); //FIN MATRICE SECOND DOIGT


                        glPopMatrix(); //FIN MATRICE MAIN

                    glPopMatrix(); //FIN MATRICE POIGNET
                glPopMatrix(); //FIN DE LA MATRICE AVANT BRAS
            glPopMatrix(); //FIN DE LA MATRICE COUDE
        glPopMatrix(); //FIN DE LA MATRICE BRAS
	glPopMatrix(); //FIN DE LA MATRICE EPAULE



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


    glPushMatrix();

        /* Tete */
		glRotatef(180.0,0.0f,1.0f,0.0f);
		glTranslatef(0.0f, 1.0f, -1.0f);
		glRotatef(angle,0.0f,1.0f,0.0f);
		glutSolidSphere(2.5, 12.0, 12.0);



	glPopMatrix();
}

#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED


#include <GL/gl.h>
#include <GL/glu.h>


class Robot{
    public:
        Robot(float epaule, float avant_bras, float coude, float xcoude, float ycoude, float xpoigne, float ypoigne, float angle);

        void robotLeftLeg();
        void robotRightLeg();
        void arms();
        void body();
        void head();
        void finger(float zPosition);
        void hand(float xcoude, float ycoude, float rotation, float rotation2);




        float epaule;
        float avant_bras;
        float coude;
        float xcoude;
        float ycoude;
        float xpoigne;
        float ypoigne;
        float angle;
    protected:
    private:

};

#endif // ROBOT_H_INCLUDED

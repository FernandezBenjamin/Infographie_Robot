#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED


#include <GL/gl.h>
#include <GL/glu.h>



#define BASE1 0
#define BASE2 1
#define ARMS 2
#define HEAD1 3
#define HEAD2 4
#define LEG_LEFT 5
#define LEG_RIGHT 6
#define MEMBERS_MAX 7


class Robot{
    public:
        Robot(float epaule, float avant_bras, float coude, float xcoude, float ycoude, float xpoigne, float ypoigne, float angle);


        void construct();
        void draw();
        void setTextures(int face, GLuint texture);





        float epaule;
        float avant_bras;
        float coude;
        float xcoude;
        float ycoude;
        float xpoigne;
        float ypoigne;
        float angle;
        float trans_x;
        float trans_y;
        float trans_z;
    protected:
    private:

        void robotLeftLeg();
        void robotRightLeg();
        void arms();
        void body();
        void head();
        void finger(float zPosition);
        void hand(float xcoude, float ycoude, float rotation, float rotation2);

        GLuint textures[MEMBERS_MAX];
};

#endif // ROBOT_H_INCLUDED

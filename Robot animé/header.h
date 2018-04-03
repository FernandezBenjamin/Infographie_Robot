/** PROTOTYPES DE FONCTIONS **/
void initRendering();
void drawAxes();
void display(void);
void reshape(int w,int h);
void keyboard(unsigned char key, int x, int y);
void mouseWheel(int , int, int, int);
//COMPOSANTS DU ROBOT
void robotLeg();
void arms();
void hand(float xcoude, float ycoude, float rotation, float rotation2, float rotation3);
void finger(float zPosition);
//CAMERA
void cameraPosition();
void cameraVisee();
void calcul();
void setRadian();



/** VARIABLES GLOBALES **/
//FONCTION GLULOOKAT
float eyeX = 0.0;
float eyeY = 0.0;
float eyeZ = 0.0;

float centerX = 0.0;
float centerY = 0.0;
float centerZ = 0.0;

float upX = 0.0;
float upY = 1.0;
float upZ = 0.0;


float t1 = 0.0;
float t2 = 0.0;
float t3 = 0.0;

float r = -20.0;
float coef = -2.0; //ZOOM DE LA CAMERA

//ANGLES DE LA CAMERA
float alpha = 0.0;
float beta = 0.0;

int optionCamera = 0;   //SI 0, CAMERA LIBRE PAR DEFAUT
                        //SI 1, CAMERA CENTREE

void mouseWheel(int button, int dir, int x, int y){

    if(button == 3){ //SCROLL UP
        printf("ok");
        coef = coef + 0.2;
    }
    if(button == 4){ //SCROLL DOWN
        printf("ok");
        coef = coef + 0.2;
    }
}






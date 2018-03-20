/** PROTOTYPES DE FONCTIONS **/
void initRendering();
void display(void);
void reshape(int w,int h);
void keyboard(unsigned char key, int x, int y);
void robotLeg();
void arms();

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

float r = 20.0;
float coef = 0.0; //SE DEPLACE DE 0.2: ZOOM

float alpha = 0.0;
float beta = 0.0;








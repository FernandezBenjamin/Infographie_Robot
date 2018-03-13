/** PROTOTYPES DE FONCTIONS **/
void initRendering();
void display(void);
void reshape(int w,int h);
void keyboard(unsigned char key, int x, int y);
void robotLeg();
void camera();
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

float r = 7.5;

float alpha = 0.0;
float beta = 0.0;




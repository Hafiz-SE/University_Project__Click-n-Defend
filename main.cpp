#include <iostream>
#include<GL/gl.h>
#include<math.h>
#include <GL/glut.h>
#include<cstring>
#include<sstream>
#include <string>
using namespace std;
int ballx=0;
int bally=0;
float mouseX=0.0;
float mouseY=0.0;
unsigned long iTimeElapsed;
float position1 = -0.99;
float position2 = -1.19;
float position3 = -1.39;
float positionNULL=-1.39;
float position = 0.0;    // triangle initial position
float positionT1=-0.95;
float positionT2=-1.15;
float positionT3=-1.35;

float position5 = 0.0;
float positionS1=-0.95;
float positionS2=-1.15;
float positionS3=-1.35;

float rotates = 30.0f;

int cFlag1=0;
int cFlag2=0;
int cFlag3=0;

int tFlag1=0;
int tFlag2=0;
int tFlag3=0;

int sFlag1=0;
int sFlag2=0;
int sFlag3=0;
int score=0;
int life = 5;

string IntToString ( int number )
{
  ostringstream oss;

  // Works just like cout
  oss<< number;

  // Return the underlying string
  return oss.str();
}


void sprint (float x , float y, char *text , float r , float g , float b){


int leng = strlen(text);
glColor3f(r,g,b);
glDisable(GL_LIGHTING);


glRasterPos2f(x,y);

 for(int i=0; i < leng; i++)
    {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
 }






void mouseMotion(int x, int y)
{
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    ballx = x;
    bally = windowHeight-y;
    //cout<<x<<", "<<windowHeight-y<<endl;
    float floatxconvert=(float)ballx;
    float floatyconvert=(float)bally;
    if (ballx<641){
    float xx=1-(floatxconvert/640.0f);
        mouseX=  -xx;

    }
    else
          mouseX= (floatxconvert/640.0f)-1.0f;

    if(bally<321){
        float yy= 1-(floatyconvert/320.0f);
        mouseY= -yy;
    }
          else
            mouseY = (floatyconvert/320.0f)-1.0f;


   // mouseX = ((float)ballx / 1280.0f)
     //mouseY = ((float)bally / 640.0f)

//cout<<mouseX<<","<<mouseY<<"\t";


}


void mouseClick(int button, int state, int x, int y){
    float xmax1=position1+0.10;
    float xmin1=position1-0.10;
    float xmax2=position2+0.10;
    float xmin2=position2-0.10;
    float xmax3=position3+0.10;
    float xmin3=position3-0.10;
    float xmax4=positionT1+0.10;
    float xmin4=positionT1-0.10;
    float xmax5=positionT2+0.10;
    float xmin5=positionT2-0.10;
    float xmax6=positionT3+0.10;
    float xmin6=positionT3-0.10;
    float xmax7=positionS1+0.05;
    float xmin7=positionS1-0.05;
    float xmax8=positionS2+0.05;
    float xmin8=positionS2-0.05;
    float xmax9=positionS3+0.05;
    float xmin9=positionS3-0.05;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
            if (xmin1<mouseX && mouseX<xmax1 && -0.05<mouseY && mouseY<0.05)
                {
                   cFlag1=1;
                   score++;
                }

            else if (xmin2<mouseX && mouseX<xmax2 && -0.05<mouseY && mouseY<0.05)
                {
                   cFlag2=1;
                   score++;
                }

            else if (xmin3<mouseX && mouseX<xmax3 && -0.05<mouseY && mouseY<0.05)
                {
                   score++;
                   cFlag3=1;
                }

            else if (xmin4<mouseX && mouseX<xmax4 && -0.45<mouseY && mouseY<-0.35)
                {
                    score++;
                   tFlag1=1;
                }

            else if (xmin5<mouseX && mouseX<xmax5 && -0.45<mouseY && mouseY<-0.35)
                {
                    score++;
                   tFlag2=1;
                }

            else if (xmin6<mouseX && mouseX<xmax6 && -0.45<mouseY && mouseY<-0.35)
                {
                    score++;
                   tFlag3=1;
                }

           else if (xmin7<mouseX && mouseX<xmax7 && -.85<mouseY && mouseY<-0.75)
            {
                   score++;
                   sFlag1=1;
                }

           else if (xmin8<mouseX && mouseX<xmax8 && -.85<mouseY && mouseY<-0.75)
            {
                    score++;
                   sFlag2=1;
                }

           else if (xmin9<mouseX && mouseX<xmax9 && -.85<mouseY && mouseY<-0.75)
            {
                    score++;
                   sFlag3=1;
                }
            else
                {
                    life--;
            }
    }
}

/*void gameOver()
{
    if(position1==2.0 || position2==2.0 || position3==2.0 || positionS1==2.5 || positionS2==2.5 || positionS3==2.5 || positionT1==2.5 || positionT2==2.5 || positionT3==2.5 || life==0)
        break;
}
*/


void initRendering() {
	glEnable(GL_DEPTH_TEST);
}
//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


void update(int value) {

    iTimeElapsed = glutGet(GLUT_ELAPSED_TIME);
if (iTimeElapsed>5000){      ///position for All TRIANGLE

        if(tFlag1==1){
        positionT1=positionT1-100.0;
        tFlag1=0;
        }
        if(tFlag2==1){
        positionT2=positionT2-100.0;
        tFlag2=0;
        }
        if(tFlag3==1){
        positionT3=positionT3-100.0;
        tFlag3=0;
        }

         positionT1=positionT1+0.01;
         positionT2=positionT2+0.01;
         positionT3=positionT3+0.01;
        position=position+0.01;
            if(position>=2.5)
            {
                position=0.0;
                positionT1=-0.95;
                positionT2=-1.15;
                positionT3=-1.35;

            }
}
if (iTimeElapsed>10000){    ///position5 for All Square

        if(sFlag1==1){
        positionS1=positionS1-100.0;
        sFlag1=0;
        }
        if(sFlag2==1){
        positionS2=positionS2-100.0;
        sFlag2=0;
        }

        if(sFlag3==1){
        positionS3=positionS3-100.0;
        sFlag3=0;
        }

        positionS1=positionS1+0.01;
         positionS2=positionS2+0.01;
         positionS3=positionS3+0.01;
        position5+=0.01;
        if(position5>=2.5)
        {
            position5=0.0;
            positionS1=-0.95;
            positionS2=-1.15;
            positionS3=-1.35;
        }

}
///for Circle
        if(cFlag1==1){
            position1=position1-100.0;
        cFlag1=0;
        }
        if(cFlag2==1){
            position2=position2-100.0;
        cFlag2=0;
        }
        if(cFlag3==1){
            position3=position3-100.0;
        cFlag3=0;
        }


          position1=position1+0.01;    /// for Circle1
          position2=position2+0.01;    /// for Circle2
          position3=position3+0.01;    /// for Circle3
          positionNULL=positionNULL+0.01;
          if(positionNULL>=2.0)
          {
                position1 = -0.99;
                position2 = -1.19;
                position3 = -1.39;
                positionNULL=-1.39;
          }


 //position1=position1+0.01;
 //rotates += 2;
	if (rotates > 360) {
		rotates -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}


void Display(){

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(0,0,0);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

	if(position1==2.0 || position2==2.0 || position3==2.0 || positionS1==2.5 || positionS2==2.5 || positionS3==2.5 || positionT1==2.5 || positionT2==2.5 || positionT3==2.5 || life==0)
        return;

   // glRotatef(_angle, 1.0f, 0.0f, 0.0f); //Rotate the camera
///////////////////// Earth ///////////////////////////
    //Save the current state of transformations
	 //Move to the center of the triangle
glPushMatrix();
	 glPointSize(1);
        glBegin(GL_POINTS);

		glVertex3f((float)ballx/200, (float)bally/200, 0.0);



	glEnd();
	 glPopMatrix();
string tmp = IntToString(score);
char tab2[1024];
strcpy(tab2, tmp.c_str());

string tmp12 = IntToString(life);
char tab12[1024];
strcpy(tab12, tmp12.c_str());

	 sprint(0.9,0.9,tab2,0.2,0.3,0.5);
	 sprint(0.9,0.85,tab12,0.2,0.3,0.5);

//LINE 1
glPushMatrix();
        glBegin(GL_QUADS);
        glColor3f(0.4,0.8,0.1);
        glVertex2f(0.99,-0.1);
        glVertex2f(0.99,0.1);
        glVertex2f(-0.99,0.1);
          glVertex2f(-0.99,-0.1);
glEnd();
glPopMatrix();


//cout<<iTimeElapsed<<"\t";
if (iTimeElapsed>5000){
   glPushMatrix();
 glTranslatef(positionT1, 0.0, 0.0);  ///TRIANGLE1
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_TRIANGLES);

        glVertex2f(0.05,-0.45);
        glVertex2f(0.00,-0.35);
        glVertex2f(-0.05,-0.45);
        glEnd();
        glPopMatrix();

    glPushMatrix();
 glTranslatef(positionT2, 0.0, 0.0);///TRIANGLE2
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_TRIANGLES);

        glVertex2f(0.05,-0.45);
        glVertex2f(0.00,-0.35);
        glVertex2f(-0.05,-0.45);
        glEnd();
        glPopMatrix();

    glPushMatrix();
 glTranslatef(positionT3, 0.0, 0.0);   ///TRIANGLE3
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_TRIANGLES);

         glVertex2f(0.05,-0.45);
        glVertex2f(0.00,-0.35);
        glVertex2f(-0.05,-0.45);
        glEnd();
        glPopMatrix();


}

//LINE 2
glPushMatrix();
        glBegin(GL_QUADS);
        glColor3f(0.4,0.5,0.9);
        glVertex2f(0.99,-0.5);
        glVertex2f(0.99,-0.3);
        glVertex2f(-0.99,-0.3);
          glVertex2f(-0.99,-0.5);
glEnd();
glPopMatrix();

if(iTimeElapsed>10000)
{
    glPushMatrix();
    glTranslatef(positionS1, 0.0, 0.0); ///Square 1
    glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0.05,-.85);
        glVertex2f(0.00,-.85);
        glVertex2f(0.00,-.75);
        glVertex2f(0.05,-.75);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(positionS2, 0.0, 0.0); ///Square 2
    glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0.05,-.85);
        glVertex2f(0.00,-.85);
        glVertex2f(0.00,-.75);
        glVertex2f(0.05,-.75);
        glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(positionS3, 0.0, 0.0); ///Square 3
    glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0.05,-.85);
        glVertex2f(0.00,-.85);
        glVertex2f(0.00,-.75);
        glVertex2f(0.05,-.75);
        glEnd();
    glPopMatrix();
}

//Line 3
glPushMatrix();
        glBegin(GL_QUADS);
        glColor3f(0.8,0.7,0.4);
        glVertex2f(0.99,-0.9);
        glVertex2f(0.99,-0.7);
        glVertex2f(-0.99,-0.7);
          glVertex2f(-0.99,-0.9);
glEnd();
glPopMatrix();

glEnd();

//Circle

        glPushMatrix();
        glTranslatef(position1, 0.0, 0.0);  ///Circle1
glColor3f(1.0,0.0,0.0); //red


        glutWireSphere(.05,20,10);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(position2, 0.0, 0.0);  ///Circle2
        glColor3f(1.0,0.0,0.0);
        glutWireSphere(.05,20,10);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(position3, 0.0, 0.0);  ///Circle3
        glColor3f(1.0,0.0,0.0);
        glutWireSphere(.05,20,10);
        glPopMatrix();

/*
glRotatef(rotates,0.0,0.0,1.0);
glTranslatef(position1, 0.0, 0.0);
glColor3f(1.0,1.0,1.0);
glPushMatrix();

glutSolidSphere(0.02,20,20);
glPopMatrix();
*/

glutSwapBuffers();
glutPostRedisplay();
}



int main(int argc, char** argv)
{
	//Initializing GLUT....
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1280, 640);


	//Creating Window..
	glutCreateWindow("Ultimate Defense Game Pro Final Pre-release");
	initRendering();

    //Set handler functions
	glutDisplayFunc(Display);
//	glutKeyboardFunc(Keyboard);


	//glutSpecialFunc(Special);
	glutIgnoreKeyRepeat(1);


	//glutReshapeFunc(handleResize);
    glutPassiveMotionFunc(mouseMotion);
    glutMouseFunc(mouseClick);
	glutTimerFunc(1000, update, 0); //Add a timer



	glutMainLoop();
	return 0;
}

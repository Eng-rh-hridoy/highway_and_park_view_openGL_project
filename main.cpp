#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
#include<stdio.h>

#define PI 3.1416
static GLfloat spin = 0.0;

static float	tx	=  0.0,bx=0.0,by=0.0,isbaby=0,dolnay=0,glUp=1,angle=0,step=0,stepx=0,stepy=0,countdolna=0;
static float	ty	=  5.0;

GLfloat truckPosition = 0.0f;
GLfloat truckSpeed = 0.05f;
GLfloat carPosition = 0.0f;
GLfloat carSpeed = 0.05f;
GLfloat boatPosition = 0.0f;
GLfloat boatSpeed = 0.005f;
GLfloat cloudPosition = 0.0f;
GLfloat cloudSpeed = 0.005f;
GLfloat cloud1Position = 0.0f;
GLfloat cloud1Speed = 0.007f;
GLfloat sunPosition = 0.0f;
GLfloat sunSpeed = 0.006f;

void baby();

void circle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}



void babySwing()
{
    glPushMatrix();

    glTranslated(6.2,1.8,0);
    glScaled(0.03,0.04,0);


    glPushMatrix();   //jama top
    glRotated(-20,0,1,0);
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(-6,-6);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-6,-11);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(6,-11);
    glVertex2d(9,-13);
    glVertex2d(11,-9);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //left hand
    glRotated(-20,0,1,0);
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-13,-20);
    glVertex2d(-16,-18);
    glEnd();

    glPopMatrix();

    glPushMatrix();//left hand palm
    glRotated(-20,0,1,0);
    glTranslated(-15,-20,0);
    glColor3f(0.87,0.72,0.53);
    circle(3,2.5);
    glPopMatrix();

    glPushMatrix();     //right hand
    glRotated(-20,0,1,0);
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(11,-9);
    glVertex2d(9,-13);
    glVertex2d(13,-20);
    glVertex2d(16,-18);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //right hand palm
    glRotated(-20,0,1,0);
    glTranslated(15,-20,0);

    glColor3f(0.87,0.72,0.53);
    circle(3,2.5);
    glPopMatrix();


    glPushMatrix();     //skirt
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(-1,-28);
    glVertex2d(-16,-28);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //left leg
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(-13,-28);
    glVertex2d(-8,-28);
    glVertex2d(-11,-32);
    glVertex2d(-17,-32);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //right leg
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(-2,-28);
    glVertex2d(-7,-28);
    glVertex2d(-10,-32);
    glVertex2d(-5,-32);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //right shoe
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(-5,-32);
    glVertex2d(-10,-32);
    glVertex2d(-13,-35);
    glVertex2d(-6,-35);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //left shoe
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(-17,-32);
    glVertex2d(-11,-32);
    glVertex2d(-12,-35);
    glVertex2d(-20,-35);
    glEnd();
    glPopMatrix();


    glPushMatrix(); //hair
    glRotated(-20,0,1,0);
    glColor3f(0,0,0);
    circle(9,10);
    glPopMatrix();


    glPushMatrix();         //head, neck, nose ,eye, lips
    glRotated(-20,0,1,0);
    glColor3f(0.87,0.72,0.53);
    circle(7,6);            //head
    glBegin(GL_QUADS);      //neck
    glVertex2d(-6,-6);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_LINES);      //right eye

    glVertex2d(4,3);
    glVertex2d(1,3);

    glEnd();
    glBegin(GL_LINES);      //lips

    glVertex2d(2,-3);
    glVertex2d(-2,-3);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_LINES);      //left eye

    glVertex2d(-4,3);
    glVertex2d(-1,3);

    glEnd();
    circle(0.5,2);      //nose
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}

void swing()
{
    glPushMatrix();
    glTranslated(3,-0.5,0);
    glScaled(0.6,0.4,0);

    glColor3f(1,0,0);

    glPushMatrix(); //Dolna left bar
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(0.4,10.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //dolna right bar
    glTranslated(10,0,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(0.4,10.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //dolna up bar
    glTranslated(0,9,1);
    glRotatef(-90,0,0,1);

    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.4);
    glVertex2d(0.4,10.4);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //dolna left line
    glTranslated(2.9,3,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,dolnay);
    glVertex2d(0.0,6.0);
    glVertex2d(0.1,6.0);
    glVertex2d(0.1,dolnay);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //dolna right side
    glTranslated(7.7,3,1);
    glBegin(GL_QUADS);
    glVertex2d(0,dolnay);
    glVertex2d(0,6.0);
    glVertex2d(0.1,6.0);
    glVertex2d(0.1,dolnay);
    glEnd();
    glPopMatrix();



    glPushMatrix(); //dolna sitting table

    glTranslated(1.8,3,1);
    glBegin(GL_QUADS);
    glVertex2d(1.0,dolnay+1);
    glVertex2d(6.0,dolnay+1);
    glVertex2d(7.0,dolnay);
    glVertex2d(0.0,dolnay);


    glEnd();
    glPopMatrix();

    glPushMatrix();  //dolna under extra line
    glTranslated(1.8,2.7,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,dolnay);
    glVertex2d(7,dolnay);
    glVertex2d(7,dolnay+0.1);
    glVertex2d(0,dolnay+0.1);
    glEnd();
    glPopMatrix();


    glPopMatrix();
    babySwing();



}


// baby 5 nagordola
void baby5(){
    glPushMatrix();
    glTranslated(-0.5,2,0);
    glScaled(0.07,0.2,0);
    glPushMatrix();   //jama top
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(-6,-6);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-6,-11);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(6,-11);
    glVertex2d(9,-13);
    glVertex2d(11,-9);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //left hand
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-13,-20);
    glVertex2d(-16,-18);
    glEnd();

    glPopMatrix();

    glPushMatrix();     //left hand palm
    glTranslated(-15,-20,0);
    glColor3f(0.87,0.72,0.53);
    circle(3,2.5);
    glPopMatrix();


    glPushMatrix();     //right hand
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(11,-9);
    glVertex2d(9,-13);
    glVertex2d(13,-20);
    glVertex2d(16,-18);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //right hand palm
    glTranslated(15,-20,0);
    glColor3f(0.87,0.72,0.53);
    circle(3,2.5);
    glPopMatrix();


    glPushMatrix();     //skirt
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(13,-32);
    glVertex2d(-13,-32);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //left leg
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(-6,-32);
    glVertex2d(-2,-32);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //right leg
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(6,-32);
    glVertex2d(2,-32);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //right shoe
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(10,-42);
    glVertex2d(2,-42);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //left shoe
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(-10,-42);
    glVertex2d(-2,-42);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();



    glPushMatrix(); //hair
    glColor3f(0,0,0);
    circle(9,10);
    glPopMatrix();



    glPushMatrix();         //head, neck, nose ,eye, lips
    glColor3f(0.87,0.72,0.53);
    circle(7,6);            //head
    glBegin(GL_QUADS);      //neck
    glVertex2d(-6,-6);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_LINES);      //right eye

    glVertex2d(4,3);
    glVertex2d(1,3);

    glEnd();
    glBegin(GL_LINES);      //lips

    glVertex2d(2,-3);
    glVertex2d(-2,-3);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_LINES);      //left eye

    glVertex2d(-4,3);
    glVertex2d(-1,3);

    glEnd();
    circle(0.5,2);      //nose
    glPopMatrix();

    glPopMatrix();


    glPopMatrix();
}



void wheerligig()
{
    glPushMatrix();
    //glTranslated(-70,20,0);
    //glScaled(2,2,0);

    glPushMatrix();  //stand
    glTranslated(15,1,2);
    glScaled(0.4,0.15,0);
    glColor3f(0.184,0.31,0.31);
    glBegin(GL_QUADS);
    glVertex2d(0,-10);
    glVertex2d(1,-10);
    glVertex2d(1,30);
    glVertex2d(0,30);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslated(15.25,4.5,1);
    glScaled(-0.35,0.2,0);
    glRotated(angle,0,0,1);
    glPushMatrix();
    glTranslatef(10,13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(10,-13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();
    //glScaled(1.5,1.5,0);
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,-13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();

   // if(isbaby==5)
    //{
        baby5();
    //}

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();


    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(55.5,-20,0);
    //glRotated(45,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);

    glVertex2d(0,0);
    glVertex2d(10,13);
    // glVertex2d(xx.yy);
    glVertex2d(0,0);
    glVertex2d(10,-13);
    glVertex2d(0,0);       //4 cross lines
    glVertex2d(-10,-13);
    glVertex2d(0,0);
    glVertex2d(-10,13);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,0);
    glColor3f(0.545,0,0);
    circle(1,1);
    glPopMatrix();


    glPopMatrix();
    glPopMatrix();
    //printf("angle:%f\n",angle);
    // glPopMatrix();

}



void baby()
{
    glPushMatrix();
    glTranslated(8.85+bx,-4.8+by,0);
    glScalef(0.05,0.06,0);

    glPushMatrix();   //jama top
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(-6,-6);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-6,-11);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(6,-11);
    glVertex2d(9,-13);
    glVertex2d(11,-9);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //left hand
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-13,-20);
    glVertex2d(-16,-18);
    glEnd();

    glPopMatrix();

    glPushMatrix();     //left hand palm
    glTranslated(-15,-20,0);
    glColor3f(0.87,0.72,0.53);
    circle(3,2.5);
    glPopMatrix();


    glPushMatrix();     //right hand
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(11,-9);
    glVertex2d(9,-13);
    glVertex2d(13,-20);
    glVertex2d(16,-18);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //right hand palm
    glTranslated(15,-20,0);
    glColor3f(0.87,0.72,0.53);
    circle(3,2.5);
    glPopMatrix();


    glPushMatrix();     //skirt
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(13,-32);
    glVertex2d(-13,-32);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //left leg
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(-6,-32);
    glVertex2d(-2,-32);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //right leg
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(6,-32);
    glVertex2d(2,-32);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //right shoe
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(10,-42);
    glVertex2d(2,-42);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //left shoe
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(-10,-42);
    glVertex2d(-2,-42);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();



    glPushMatrix(); //hair
    glColor3f(0,0,0);
    circle(9,10);
    glPopMatrix();



    glPushMatrix();         //head, neck, nose ,eye, lips
    glColor3f(0.87,0.72,0.53);
    circle(7,6);            //head
    glBegin(GL_QUADS);      //neck
    glVertex2d(-6,-6);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_LINES);      //right eye

    glVertex2d(4,3);
    glVertex2d(1,3);

    glEnd();
    glBegin(GL_LINES);      //lips

    glVertex2d(2,-3);
    glVertex2d(-2,-3);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_LINES);      //left eye

    glVertex2d(-4,3);
    glVertex2d(-1,3);

    glEnd();
    circle(0.5,2);      //nose
    glPopMatrix();

    glPopMatrix();


    glPopMatrix();
}



void glidder()
{
    glPushMatrix();
    glTranslated(7.5,-4,0);
    glColor3f(0,0,0.54);
    glScalef(0.8,0.5,0);

    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2f(0,3.0);
    glVertex2f(0,3.3);
    glVertex2f(13,0.3);
    glVertex2f(13,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2d(3.0,2.4);
    glVertex2d(3.0,3.0);
    glVertex2d(3.3,3.0);
    glVertex2d(3.3,2.4);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2d(10.0,0.9);
    glVertex2d(10.0,1.5);
    glVertex2d(9.7,1.5);
    glVertex2d(9.7,0.9);
    glEnd();
    glPopMatrix();
    glPushMatrix();  //glidder bottom
    glTranslated(6.2,1.0,1);
    //glRotatef(glAngle,0,0,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.6);
    glVertex2d(0.0,-2.0);
    glVertex2d(0.5,-2.0);
    glVertex2d(0.5,0.5);
    glEnd();
    glPopMatrix();


    glPopMatrix();
    glPushMatrix();

    glRotatef(-20,1,1,1);
    glTranslated(9.8,0.5,0);
    glScaled(0.05,0.05,0);


    glPushMatrix();   //jama top
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(-6,-6);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-6,-11);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(6,-11);
    glVertex2d(9,-13);
    glVertex2d(11,-9);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //left hand
    glColor3f(0.87,0.72,0.53);
    glRotated(-15,0,1,0);
    glBegin(GL_QUADS);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-18,-11);
    glVertex2d(-16,-7);
    glEnd();

    glPopMatrix();

    glPushMatrix();     //left hand palm
    glTranslated(-18.5,-9,0);
    glColor3f(0.87,0.72,0.53);
    circle(3.3,2.7);
    glPopMatrix();


    glPushMatrix();     //right hand
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(11,-9);
    glVertex2d(9,-13);
    glVertex2d(13,-20);
    glVertex2d(16,-18);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //right hand palm
    glTranslated(15,-20,0);
    glColor3f(0.87,0.72,0.53);
    circle(3,2.5);
    glPopMatrix();

    glPushMatrix();     //skirt
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(4,-32);
    glVertex2d(-16,-30);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //left leg
    glTranslated(-6,1.5,0);
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(-6,-32);
    glVertex2d(-2,-32);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //right leg
    glTranslated(-5,0.8,0);
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(6,-32);
    glVertex2d(2,-32);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //right shoe
    glTranslated(-5,0.8,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(6,-42);
    glVertex2d(-2,-42);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //left shoe
    glTranslated(-6,1.5,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(-10,-42);
    glVertex2d(-2,-42);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();



    glPushMatrix(); //hair
    glColor3f(0,0,0);
    circle(9,10);
    glPopMatrix();


    glPushMatrix();         //head, neck, nose ,eye, lips
    glColor3f(0.87,0.72,0.53);
    circle(7,6);            //head
    glBegin(GL_QUADS);      //neck
    glVertex2d(-6,-6);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_LINES);      //right eye

    glVertex2d(4,3);
    glVertex2d(1,3);
    glEnd();
    glBegin(GL_LINES);      //lips

    glVertex2d(2,-3);
    glVertex2d(-2,-3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_LINES);      //left eye

    glVertex2d(-4,3);
    glVertex2d(-1,3);

    glEnd();
    circle(0.5,2);      //nose
    glPopMatrix();

    glPopMatrix();


    glPopMatrix();
    glPushMatrix();


//baby2


    glRotatef(-20,1,1,1);
    glTranslated(17.5,0.6,0);


    glScalef(0.05,0.05,0);
    //glRotated(20,1,1,0);
    glPushMatrix();   //jama top
    glColor3f(1,0.27,0);
    glBegin(GL_POLYGON);
    glVertex2d(-6,-6);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-6,-11);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(6,-11);
    glVertex2d(9,-13);
    glVertex2d(11,-9);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //left hand
    glColor3f(1,0.94,0.83);
    glBegin(GL_QUADS);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-13,-20);
    glVertex2d(-16,-18);
    glEnd();

    glPopMatrix();

    glPushMatrix();     //left hand palm
    glTranslated(-15,-20,0);
    glColor3f(1,0.94,0.83);
    circle(3,2.5);
    glPopMatrix();


    glPushMatrix();     //right hand
    glColor3f(1,0.94,0.83);
    glBegin(GL_QUADS);
    glVertex2d(11,-9);
    glVertex2d(9,-13);
    glVertex2d(13,-20);
    glVertex2d(16,-18);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //right hand palm
    glTranslated(15,-20,0);
    glColor3f(1,0.94,0.83);
    circle(3,2.5);
    glPopMatrix();


    glPushMatrix();     //skirt
    glColor3f(0.6,0.196,0.8);
    glBegin(GL_QUADS);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(4,-32);
    glVertex2d(-16,-30);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //left leg
    glTranslated(-6,1.5,0);
    glColor3f(1,0.94,0.83);
    glBegin(GL_QUADS);
    glVertex2d(-6,-32);
    glVertex2d(-2,-32);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //right leg
    glTranslated(-5,0.8,0);
    glColor3f(1,0.94,0.83);
    glBegin(GL_QUADS);
    glVertex2d(6,-32);
    glVertex2d(2,-32);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //right shoe
    glTranslated(-5,0.8,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(6,-42);
    glVertex2d(-2,-42);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //left shoe
    glTranslated(-6,1.5,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(-10,-42);
    glVertex2d(-2,-42);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();



    glPushMatrix(); //hair
    glColor3f(0,0,0);
    circle(9,10);
    glPopMatrix();



    glPushMatrix();         //head, neck, nose ,eye, lips
    glColor3f(1,0.94,0.83);
    circle(7,6);            //head
    glBegin(GL_QUADS);      //neck
    glVertex2d(-6,-6);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_LINES);      //right eye

    glVertex2d(4,3);
    glVertex2d(1,3);

    glEnd();
    glBegin(GL_LINES);      //lips

    glVertex2d(2,-3);
    glVertex2d(-2,-3);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_LINES);      //left eye

    glVertex2d(-4,3);
    glVertex2d(-1,3);

    glEnd();
    circle(0.5,2);      //nose
    glPopMatrix();

    glPopMatrix();

    //glPopMatrix();
    glPopMatrix();
}








void circleSolid(float x, float y, float radius)
{
	int triangleAmount = 100;

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
		}
    glEnd();
}








void sky(int value)
{
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.5f, 1.0f);
    glVertex2f(-20,10);
    glVertex2f(20, 10);
    glColor3f(7, 7, 10);
    glVertex2f(20.5, 1);
    glVertex2f(-23, 1);
    glEnd();

    glutPostRedisplay();
    glutTimerFunc(5, sky, 0);
}



void sun()
{
    glPushMatrix();
    glTranslatef(0.0f,sunPosition, 0.0f);

    float x1,y1,x2,y2;
    float a;
    double radius=2;

    x1=-10.8, y1= 5.7;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,0);
    for (a = 0.0f ; a < 360.0f ; a+=0.2)
        {
            x2 = x1+sin(a)*radius;
            y2 = y1+cos(a)*radius;
            glVertex2f(x2,y2);
        }

       glEnd();

    glPopMatrix();
}




void clouds1()
{
    glPushMatrix();
    glTranslatef(cloud1Position,5.0f, 0.0f);
    float x1,y1,x2,y2;
    float x3,y3,x4,y4;
    float x5,y5,x6,y6;
    float x7,y7,x8,y8;
    float x9,y9,x0,y0;
    float x11,y11,x12,y12;
    float x13,y13,x14,y14;
    float a;
    double radius=1.3;

    x1=-2.7, y1= 0.65;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x2 = x1+sin(a)*radius;
            y2 = y1+cos(a)*radius;
            glVertex2f(x2,y2);
        }
        glEnd();

    x3=-0.35, y3= 2.56;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x4 = x3+sin(a)*radius;
            y4 = y3+cos(a)*radius;
            glVertex2f(x4,y4);
        }
        glEnd();

    x5=-2.35, y5= 2.7;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x6 = x5+sin(a)*radius;
            y6 = y5+cos(a)*radius;
            glVertex2f(x6,y6);
        }
        glEnd();

    x7=-4.26, y7= 1.56;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x8 = x7+sin(a)*radius;
            y8 = y7+cos(a)*radius;
            glVertex2f(x8,y8);
        }
        glEnd();

    x9=1.26, y9= 1.7;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x0 = x9+sin(a)*radius;
            y0 = y9+cos(a)*radius;
            glVertex2f(x0,y0);
        }
        glEnd();

    x11=-1.18, y11= 0.63;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x12 = x11+sin(a)*radius;
            y12 = y11+cos(a)*radius;
            glVertex2f(x12,y12);
        }
        glEnd();

    x13=-0.3, y13= 0.63;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x14 = x13+sin(a)*radius;
            y14 = y13+cos(a)*radius;
            glVertex2f(x14,y14);
        }
        glEnd();

    glPopMatrix();
}





void clouds2()
{
    glPushMatrix();
    glTranslatef(12.0f,5.0f, 0.0f);
    float x1,y1,x2,y2;
    float x3,y3,x4,y4;
    float x5,y5,x6,y6;
    float x7,y7,x8,y8;
    float x9,y9,x0,y0;
    float x11,y11,x12,y12;
    float x13,y13,x14,y14;
    float a;
    double radius=1.3;

    x1=-2.7, y1= 0.65;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x2 = x1+sin(a)*radius;
            y2 = y1+cos(a)*radius;
            glVertex2f(x2,y2);
        }
        glEnd();

    x3=-0.35, y3= 2.56;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x4 = x3+sin(a)*radius;
            y4 = y3+cos(a)*radius;
            glVertex2f(x4,y4);
        }
        glEnd();

    x5=-2.35, y5= 2.7;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x6 = x5+sin(a)*radius;
            y6 = y5+cos(a)*radius;
            glVertex2f(x6,y6);
        }
        glEnd();

    x7=-4.26, y7= 1.56;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x8 = x7+sin(a)*radius;
            y8 = y7+cos(a)*radius;
            glVertex2f(x8,y8);
        }
        glEnd();

    x9=1.26, y9= 1.7;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x0 = x9+sin(a)*radius;
            y0 = y9+cos(a)*radius;
            glVertex2f(x0,y0);
        }
        glEnd();

    x11=-1.18, y11= 0.63;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x12 = x11+sin(a)*radius;
            y12 = y11+cos(a)*radius;
            glVertex2f(x12,y12);
        }
        glEnd();

    x13=-0.3, y13= 0.63;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x14 = x13+sin(a)*radius;
            y14 = y13+cos(a)*radius;
            glVertex2f(x14,y14);
        }
        glEnd();

    glPopMatrix();
}




void grass1()
{
    glColor3ub(28,230,0);
    glBegin(GL_POLYGON);
    glVertex2f(-40.69f, -10.55f);
    glVertex2f(20.0f, -10.55f);
    glVertex2f(40.0,1.0);
    glVertex2f(10.57,1.0);
    glVertex2f(30.57,1.92);
    glVertex2f(30.55,0.69);
    glVertex2f(40.53,0.67);
    glVertex2f(40.51,0.95);
    glVertex2f(-40.55,1.93);
    glVertex2f(100.59,-10.6);
    glEnd();
}


//tree 1
void tree1(){
    glPushMatrix();
    glTranslatef(-5.0f,1.0f, 0.0f);
    glScalef(10.05,10.06,0);

    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    glPopMatrix();
}



void tree2(){
    glPushMatrix();
    glTranslatef(-3.0f,1.0f, 0.0f);
    glScalef(10.05,10.06,0);

    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    glPopMatrix();
}





void tree3(){
    glPushMatrix();
    glTranslatef(-1.0f,1.0f, 0.0f);
    glScalef(10.05,10.06,0);

    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    glPopMatrix();
}




void tree4(){
    glPushMatrix();
    glTranslatef(1.0f,1.0f, 0.0f);
    glScalef(10.05,10.06,0);

    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    glPopMatrix();
}




void tree5(){
    glPushMatrix();
    glTranslatef(3.0f,1.0f, 0.0f);
    glScalef(10.05,10.06,0);

    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    glPopMatrix();
}




void tree6(){
    glPushMatrix();
    glTranslatef(5.0f,1.0f, 0.0f);
    glScalef(10.05,10.06,0);

    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    glPopMatrix();
}




void tree7(){
    glPushMatrix();
    glTranslatef(7.0f,1.0f, 0.0f);
    glScalef(10.05,10.06,0);

    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    glPopMatrix();
}



void tree8(){
    glPushMatrix();
    glTranslatef(9.0f,1.0f, 0.0f);
    glScalef(10.05,10.06,0);

    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    glPopMatrix();
}



void tree9(){
    glPushMatrix();
    glTranslatef(11.0f,1.0f, 0.0f);
    glScalef(10.05,10.06,0);

    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    glPopMatrix();
}




void tree10(){
    glPushMatrix();
    glTranslatef(13.0f,1.0f, 0.0f);
    glScalef(10.05,10.06,0);

    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    glPopMatrix();
}



void tree11(){
    glPushMatrix();
    glTranslatef(15.0f,1.0f, 0.0f);
    glScalef(10.05,10.06,0);

    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    glPopMatrix();
}




// 0 = 1 = 3 , 1 = 3 = 5
void river ()
{
    glColor3ub(62,103,185);
    glBegin(GL_POLYGON);
    glVertex2f(-20.0f, -0.3f);
    glVertex2f(-1.1f, 25.1f);    // no
    glVertex2f(-15.3f, -7.13f);   //no
    glVertex2f(7.3f, -7.13f);
    glVertex2f(3.4f, -3.32f); // 3.4 , -3.32
    glVertex2f(-3.19f, -3.49f);
    glVertex2f(-3.25f, -3.67f);
    glVertex2f(7.04f, 5.79f);
    glVertex2f(-5.016f, 3.86f);
    glVertex2f(3.019f, -3.90f);
    glVertex2f(3.021f, -3.905f);
    glVertex2f(3.02f, -3.91f);
    glVertex2f(3.025f, -3.915f);
    glVertex2f(3.023f, -3.920f);
    glVertex2f(-3.025f, -3.925f);
    glVertex2f(3.027f, -5.0f);
    glVertex2f(-18.0, -5.0f);
    glEnd();
}



void ship()
{
    //base
    glPushMatrix();
    glTranslatef(5.0f,0.5f, 0.0f);
    glScalef(22.05,12.06,0);
    glColor3ub(255,110,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.69f, -0.30f);
    glVertex2f(-0.62f, -0.30f);
    glVertex2f(-0.58f, -0.24f);
    glVertex2f(-0.73f, -0.24f);
    glEnd();

    //stick
    glColor3ub(160,82,35);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(-0.65,-0.24);
    glVertex2f(-0.65,-0.1);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.655,-0.13);
    glVertex2f(-0.655,-0.24);
    glVertex2f(-0.71,-0.24);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-0.648,-0.08);
    glVertex2f(-0.648,-0.24);
    glVertex2f(-0.59,-0.24);
    glVertex2f(-0.59,-0.18);
    glVertex2f(-0.6,-0.19);
    glVertex2f(-0.61,-0.16);
    glVertex2f(-0.63,-0.12);
    glEnd();

    glPopMatrix();

}




void road1()
{
    glColor3ub(32,32,32);
    glBegin(GL_POLYGON);
    glVertex2f(-30.0f, -7.0f);
    glVertex2f(30.57f, -7.0f);
    glVertex2f(30.57f,-9.5);
    glVertex2f(-30.0f,-9.5);
    glEnd();

    glColor3ub(255,255,255);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(.2,-7.91);
    glVertex2f(1.79,-7.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,-8.5);
    glVertex2f(1.79,-8.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,-9);
    glVertex2f(1.79,-9);
    glEnd();
}




void vehicle()
{
    glPushMatrix();
    glTranslatef(-3.0f,3.0f, 0.0f);
    glScalef(15.8,12.5,0);

   //body
    glColor3ub(0,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9f,-0.86f);
    glVertex2f(-0.68f, -0.86f);
    glVertex2f(-0.68f,-0.67f);
    glVertex2f(-0.9f,-0.67f);
    glEnd();

    //base of the truck
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9f,-0.86f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.58f,-0.9f);
    glVertex2f(-0.9f,-0.9f);
    glEnd();

    //front
    glColor3ub(240,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.67f,-0.86f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.58f,-0.79f);
    glVertex2f(-0.61f,-0.735f);
    glVertex2f(-0.67f,-0.735f);
    glEnd();

    //wheels
    glColor3ub(20,20,120);
    circleSolid(-0.84f,-0.88f,0.034);
    circleSolid(-0.64f,-0.88f,0.034);
    glColor3ub(130,130,130);
    circleSolid(-0.84f,-0.88f,0.02);
    circleSolid(-0.64f,-0.88f,0.02);

    //door
    glColor3ub(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-.59619,-0.815);
    glVertex2f(-0.61,-0.815);
    glEnd();

    //window
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(-0.66,-0.797);
    glVertex2f(-0.596,-0.797);
    glVertex2f(-0.596,-0.781);
    glColor3ub(100,149,237);
    glVertex2f(-0.615,-0.747);
    glVertex2f(-0.66,-0.747);
    glEnd();
    glPopMatrix();

}




void vehicle2()//This is the car
{
    glPushMatrix();
    glTranslatef(carPosition,0.0f, 0.0f);
    //body
    glColor3ub(255,255,0);
    glBegin(GL_POLYGON);
    glVertex2f(1.5f,-8.94f);
    glVertex2f(7.275f, -8.94f);
    glVertex2f(7.275f,-7.859f);
    glVertex2f(6.22f,-7.842f);
    glVertex2f(5.18f,-7.0f);
    glVertex2f(3.6f, -7.0f);
//    glVertex2f(0.08f,-0.842f);
    glVertex2f(1.5f,-7.856f);
    glEnd();

    //wheels
    glColor3ub(233,0,0);
    circleSolid(5.07,-8.938,0.4);
    circleSolid(3.2,-8.938,0.4);
//    //
//    glColor3ub(0,0,0);
//    glLineWidth(1.1);
//    glBegin(GL_LINES);
//    glVertex2f(0.141f,-0.758f);
//    glVertex2f(0.141f,-0.842f);
//    glEnd();

    //window
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(3.071,-7.842);
    glVertex2f(4.132,-7.842);

    glColor3ub(100,149,237);
    glVertex2f(4.132,-6.97);
    glVertex2f(3.506,-6.97);

    glEnd();
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(4.148,-7.842);
    glVertex2f(5.206,-7.842);

    glColor3ub(100,149,237);
    glVertex2f(5.173,-6.97);
    glVertex2f(4.148,-6.97);
    glEnd();

    //door
    glColor3ub(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(3.11,-8.1);
    glVertex2f(5.13,-8.1);
    glVertex2f(0.186,-0.863);
    glVertex2f(0.206,-0.863);
    glColor3ub(255,255,255);
    glEnd();
    glPopMatrix();
}






void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    grass1();
    river ();
    road1();
  //  vehicle2();

    ship();
    sky(1);
    sun();
    clouds1();
    clouds2();

    tree1();
    tree2();
    tree3();
    tree4();
    tree5();
    tree6();
    tree7();
    tree8();
    tree9();
    tree10();
    tree11();


    glidder();
    wheerligig();
    swing();
    baby();
    wheerligig();
    swing();


    vehicle();
    vehicle2();
    glutPostRedisplay();
    glFlush();
}

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(-20.0, 20.0, -10.0, 10.0, -15.0, 15.0);
}



int main()
{

    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 680);
    glutInitWindowPosition (50, 10);
    glutCreateWindow ("Translating Circle");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

#include<windows.h>

#include<GL/glut.h>


float x1=-2.0,x2=2.0,x3=-4,x4=4;;
static int flag=1;
void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w,int h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(45,w/h,1,300);

}



void drawBall1()
{
    glColor3f(1.0,1.0,0.0);

    glPushMatrix();

    glTranslatef(x1,0.0,-5.0);

    glutSolidSphere(0.4,20,20);

    glPopMatrix();
}

void drawBall2()
{
    glColor3f(1.0,0.0,0.0);

    glPushMatrix();

    glTranslatef(x2,0.0,-5.0);

    glutSolidSphere(0.4,20,20);

    glPopMatrix();

}

void update()
{
    if(flag)
        {
            x1+=0.002;
            x2-=0.002;
            if(x1>-0.35)
                flag=0;
        }
    if(!flag)
    {
        x1-=0.002;
        x2+=0.002;
        if(x1<-2.0)
            flag=1;
    }
}
void drawBall3()
{
    glColor3ub(255.0,159.0,155.0);

    glPushMatrix();

    glTranslatef(x3,2.0,-7.0);

    glutSolidSphere(0.3,20,20);

    glPopMatrix();
}

void drawBall4()
{
    glColor3ub(140.0,165.0,255.0);

    glPushMatrix();

    glTranslatef(x4,2.0,-7.0);

    glutSolidSphere(0.3,20,20);

    glPopMatrix();

}

void update1()
{
    if(flag)
        {
            x3+=0.005;
            x4-=0.005;
            if(x3>-0.25)
                flag=0;
        }
    if(!flag)
    {
        x3-=0.005;
        x4+=0.005;
        if(x3<-3.0)
            flag=1;
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    //glShadeModel(GL_SMOOTH);
    drawBall1();

    drawBall2();

    drawBall3();

    drawBall4();

    update();

    update1();

    glutSwapBuffers();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(300,300);

    glutCreateWindow("Collision Window");

    initRendering();

    glutDisplayFunc(display);

    glutIdleFunc(display);

    glutReshapeFunc(reshape);



    glutMainLoop();

    return(0);
}

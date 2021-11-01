#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

float angle = 0.0; /* rotation angle */
float size = 6.0; /* α = 6 */
float a; /* size changing rate */
float z=110.0; /* β = 110 */
int mode=0; /* rotation or orbit mode */

void myinit(void){

    /* attributes */
    glEnable(GL_BLEND);
    glClearColor(0.0, 0.0, 0.0, 1.0); /* background */

    /* set up viewing */
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, -200.0,200.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);  
}

void makeCube(){   

    /* creat a square */
    glNewList(1,GL_COMPILE);
        glBegin(GL_QUADS);
            glVertex3f(size/2,size/2,size/2);
            glVertex3f(-size/2,size/2,size/2);
            glVertex3f(-size/2,-size/2,size/2);
            glVertex3f(size/2,-size/2,size/2);
        glEnd();
    glEndList();  

    /* create each side and rotate to the right place and change color */
    glColor3f(1.0,0.0,1.0);    
    glRotatef(0.0,0.0,0.0,0.0);    
    glCallList(1);
    
    glColor3f(1.0,0.0,0.0);    
    glRotatef(90.0,0.0,1.0,0.0);    
    glCallList(1);

    glColor3f(0.0,1.0,0.0);    
    glRotatef(90.0,0.0,1.0,0.0);    
    glCallList(1);

    glColor3f(0.0,0.0,1.0);    
    glRotatef(90.0,0.0,1.0,0.0);    
    glCallList(1);

    glColor3f(1.0,1.0,0.0);    
    glRotatef(90.0,1.0,0.0,0.0);    
    glCallList(1);

    glColor3f(0.0,1.0,1.0);    
    glRotatef(180.0,1.0,0.0,0.0);    
    glCallList(1);
}

void display( void ){

    /* clear the window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
    glLoadIdentity();

    /* rotate and place the cube to the right place for each option*/
    if(mode==0){
        glPushMatrix();
            glTranslatef(0.0,0.0,-z);
            glRotatef(angle,1.0,1.0,1.0);        
            makeCube();
        glPopMatrix();
    }
    if(mode==1){
        glPushMatrix();
            glRotatef(angle,1.0,1.0,1.0);        
            glTranslatef(0.0,0.0,-z);
            makeCube();
        glPopMatrix();
    }
    
    glutSwapBuffers();
}

void idle(){
    
    /* constant angle of ratation */
    angle += 5.0;
    /* change of size to x3 and back to original*/        
    size += a;    
    if(size >= 18.0){
        a = -0.1;    
    }
    else if(size <= 6.0){
        a = 0.1;    
    }
    glutPostRedisplay();
}

void demo_menu(int id){
    if(id==1){
        glutSetWindowTitle("Rotation");
        mode=0;
        z=110.0;
    }
    if(id==2){
        glutSetWindowTitle("Orbit");
        mode=1;
        z=8*110.0/10;
    }
    if(id==3) {exit(0);}
}


void main(int argc, char** argv){

    /* Standard GLUT initialization */

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,800); /* 800 x 800 pixel window */
    glutInitWindowPosition(300,100); /* place window on display */
    glutCreateWindow("Cube"); /* window title */
    glutDisplayFunc(display); /* display callback invoked when window opened */
    glutIdleFunc(idle);

    myinit(); /* set attributes */

    glutCreateMenu(demo_menu);
    glutAddMenuEntry("Rotation",1);
    glutAddMenuEntry("Orbit",2);
    glutAddMenuEntry("Quit",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop(); /* enter event loop */
}


/* Οικονόμου Κωνσταντίνος 3279 */
/* Καρυοφυλλιά Πριάκου 3175 */

#include <stdlib.h>
#include <stdio.h>
#include <GL\glut.h>
#include <math.h>

float angle = 0.0; /* Camera Rotation Angle */
float ang = 0.0;   /* Sun Orbit Angle */
float size = 10.0; /* Size of the Smallest Side of the House */
float light = 0.004; /* Light Intesity Change Rate*/
float R = 0.3,G = 0.3,B = 0.3; /* Light Intesity Values in RGB Color Spectrum */

int spotlight = 0; /* Spotlight Menu Option */
int polygons = 0; /* Polygons Menu Option */
int shadows = 0; /* Shadow Menu Option */

typedef double point[3];

/* initial tetrahedron */

point v[]={{0.0, 0.0, 1.0}, {0.0, 0.942809, -0.33333},
          {-0.816497, -0.471405, -0.333333}, {0.816497, -0.471405, -0.333333}};

static GLfloat theta[] = {0.0,0.0,0.0};

void myinit(){
	/* attributes */
    glEnable(GL_BLEND);
    glClearColor(0.0, 0.0, 0.0, 1.0); /* background */

    /* set up viewing */
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-60.0, 60.0, -60.0, 60.0, -9000.0,9000.0);
    glMatrixMode(GL_MODELVIEW);

	glEnable(GL_LIGHTING); /* enable lighting */
	glEnable(GL_LIGHT0); /* enable light 0 */
	glEnable(GL_LIGHT1); /* enable light 1*/
	glEnable(GL_SMOOTH); /*enable smooth shading */
	glEnable(GL_NORMALIZE);
    glEnable (GL_DEPTH_TEST); /* enable z buffer */
}

void SpotLight(){
	GLfloat qaAmbient[] = {0.2,0.2,0.2,1.0}; /* ambient light intensity/color */
	GLfloat qaDiffuse[] = {0.8,0.8,0.8,1.0}; /* diffuse light intensity/color */
	GLfloat qaSpecular[] = {1.0,1.0,1.0,1.0}; /* specular light intensity/color */

	GLfloat Light1Pos[] = {0.0,0.0,0.0,1.0}; /* initial spotlight position (axis center)*/
	GLfloat Light1Dir[] = {0.0,-1.0,0.5};    /* light direction (down and forward) */

	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.1); 
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

	glLightfv(GL_LIGHT1,GL_AMBIENT, qaSpecular);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, qaSpecular);
    glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecular);

	glLightfv(GL_LIGHT1,GL_POSITION,Light1Pos);
	glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,Light1Dir);
	glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,30.0);
}

void Sun(){
	GLfloat qaLightAmbient[] = {0.2*R,0.2*G,0.2*B}; /* ambient light intensity/color (RGB values are constanlty changing the lights intensity) */
	GLfloat qaLightDiffuse[] = {0.8*R,0.8*G,0.8*B}; /* diffuse light intensity/color (RGB values are constanlty changing the lights intensity) */
	GLfloat qaLightSpecular[] = {1.0*R,1.0*G,1.0*B}; /* specular light intensity/color (RGB values are constanlty changing the lights intensity) */

	GLfloat lightPos[] = {0.0,0.0,0.0,1.0}; /* initial sun position (axis center)*/

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);
	
	glLightfv(GL_LIGHT0,GL_AMBIENT,qaLightAmbient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,qaLightDiffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,qaLightSpecular);

	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
}

void triangle (point a, point b, point c){
/* display one triangle using a line loop for wire frame, a single
normal for constant shading, or three normals for interpolative shading */

	GLfloat qaColor[] = {1.0,1.0,0.0,1.0}; /* RGB values for the material color (Yellow) */

	glMaterialfv(GL_FRONT,GL_AMBIENT,qaColor);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,qaColor);
	glMaterialfv(GL_FRONT,GL_SPECULAR,qaColor);
	glMaterialf(GL_FRONT,GL_SHININESS,0.0);

    glBegin(GL_POLYGON);
		glNormal3dv(a);
		glVertex3dv(a);
		glNormal3dv(b);
		glVertex3dv(b);
		glNormal3dv(c);
		glVertex3dv(c);
    glEnd();
}

void normal (point p){
/* normalize a vector */
    double d =0.0;
    int i;
    for(i=0; i<3; i++) d+=p[i]*p[i];
    d=sqrt(d);
    if(d>0.0) for(i=0; i<3; i++) p[i]/=d;
}

void divide_triangle (point a, point b, point c, int m){
/* triangle subdivision using vertex numbers
righthand rule applied to create outward pointing faces */
	point v1, v2, v3;
    int j;
    if(m>0)
    {
        for(j=0; j<3; j++) v1[j]=a[j]+b[j];
        normal(v1);
        for(j=0; j<3; j++) v2[j]=a[j]+c[j];
        normal(v2);
        for(j=0; j<3; j++) v3[j]=b[j]+c[j];
        normal(v3);
        divide_triangle  (a, v1, v2, m-1);
        divide_triangle (c, v2, v3, m-1);
        divide_triangle (b, v3, v1, m-1);
        divide_triangle (v1, v3, v2, m-1);
    }
    else
		triangle (a,b,c); /* draw triangle at end of recursion */
}

void tetrahedron (int m){
/* Apply triangle subdivision to faces of tetrahedron */
    divide_triangle (v[0], v[1], v[2], m);
    divide_triangle (v[3], v[2], v[1], m);
    divide_triangle (v[0], v[3], v[1], m);
    divide_triangle (v[0], v[2], v[3], m);
}
void makeHouse(){
	GLfloat qaBlack[] = {0.0,0.0,0.0,1.0}; /* RGB values for black color*/
	GLfloat qaColor[] = {0.2,0.1,0.0,1.0}; /* RGB values for material color (Brown) */
	GLfloat qaWhite[] = {1.0,1.0,1.0,1.0}; /* RGB values for white color */

	glMaterialfv(GL_FRONT,GL_AMBIENT,qaColor);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,qaColor);
	glMaterialfv(GL_FRONT,GL_SPECULAR,qaBlack);
	glMaterialf(GL_FRONT,GL_SHININESS,0.0);

    /* creat the sides of the house*/
	 glNewList(1,GL_COMPILE);
        glBegin(GL_QUADS);
			glNormal3f(0.0,0.0,1.0);
            glVertex3f(size/2,size/2,size);
            glVertex3f(-size/2,size/2,size);
            glVertex3f(-size/2,-size/2,size);
            glVertex3f(size/2,-size/2,size);
        glEnd();
    glEndList();

    glNewList(2,GL_COMPILE);
        glBegin(GL_QUADS);
			glNormal3f(0.0,0.0,1.0);
            glVertex3f(size,size/2,size/2);
            glVertex3f(-size,size/2,size/2);
            glVertex3f(-size,-size/2,size/2);
            glVertex3f(size,-size/2,size/2);
        glEnd();
    glEndList();

    /* create each side and rotate to the right place */
    glRotatef(0.0,0.0,0.0,0.0);
    glCallList(1);

    glRotatef(180.0,0.0,1.0,0.0);
    glCallList(1);

    glRotatef(90.0,0.0,1.0,0.0);
    glCallList(2);

    glRotatef(90.0,1.0,0.0,0.0);
    glCallList(2);

    glRotatef(180.0,1.0,0.0,0.0);
    glCallList(2);

    glRotatef(90.0,-1.0,0.0,0.0);
    glCallList(2);
}

void makeRoof(){
	//set material
	GLfloat qaBlack[] = {0.0,0.0,0.0,1.0}; /* RGB values for black color */
	GLfloat qaColor[] = {0.5,0.5,0.5,1.0}; /* RGB values for material color (Grey) */
	GLfloat qaWhite[] = {1.0,1.0,1.0,1.0}; /* RGB values for white color */

	glMaterialfv(GL_FRONT,GL_AMBIENT,qaColor);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,qaColor);
	glMaterialfv(GL_FRONT,GL_SPECULAR,qaWhite);
	glMaterialf(GL_FRONT,GL_SHININESS,100.0);

    /* creat the roof sides*/
	glNewList(1,GL_COMPILE);
        glBegin(GL_QUADS);
			glNormal3f(0.0,0.0,1.0);
            glVertex3f(size,size/2.8,size/2.8);
            glVertex3f(-size,size/2.8,size/2.8);
            glVertex3f(-size,-size/2.8,size/2.8);
            glVertex3f(size,-size/2.8,size/2.8);
        glEnd();
    glEndList();

	/* create the roof front/back */
	glNewList(2,GL_COMPILE);
        glBegin(GL_TRIANGLES);
			glNormal3f(0.0,0.0,1.0);
            glVertex3f(size/2.8,size/2.8,size);
            glVertex3f(-size/2.8,size/2.8,size);
            glVertex3f(-size/2.8,-size/2.8,size);
        glEnd();
    glEndList();

    /* create each side and rotate to the right place */
	glRotatef(45,0.0,0.0,-1.0);
	glCallList(2);

	glRotatef(180,-1.0,1.0,0.0);
	glCallList(2);

    glRotatef(90.0,0.0,1.0,0.0);
	glRotatef(180,1.0,0.0,0.0);
    glCallList(1);

    glRotatef(90.0,1.0,0.0,0.0);
    glCallList(1);
}

void makeGround(){
	int i,j;

	GLfloat qaBlack[] = {0.0,0.0,0.0,1.0}; /* RGB values for black color */
	GLfloat qaColor[] = {0.0,1.0,0.0,1.0}; /* RGB values for material color (Green) */
	GLfloat qaWhite[] = {1.0,1.0,1.0,1.0}; /* RGB values for white color */

	glMaterialfv(GL_FRONT,GL_AMBIENT,qaColor);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,qaColor);
	glMaterialfv(GL_FRONT,GL_SPECULAR,qaWhite);
	glMaterialf(GL_FRONT,GL_SHININESS,128.0);

    /* create a square (size = 50) */
	 glNewList(1,GL_COMPILE);
        glBegin(GL_QUADS);
			glNormal3f(0.0,0.0,1.0);
            glVertex3f(5*size,5*size,5*size);
            glVertex3f(-5*size,5*size,5*size);
            glVertex3f(-5*size,-5*size,5*size);
            glVertex3f(5*size,-5*size,5*size);
        glEnd();
    glEndList();

	/* create a square (size = 5) */
	glNewList(2,GL_COMPILE);
		glBegin(GL_QUADS);
			glNormal3f(0.0,0.0,1.0);
			glVertex3f(size/2,size/2,size/2);
            glVertex3f(-size/2,size/2,size/2);
            glVertex3f(-size/2,-size/2,size/2);
            glVertex3f(size/2,-size/2,size/2);
		glEnd();
	glEndList();

	if(polygons == 0){
		/* single polygon ground */
		glCallList(1);
	}
	else if(polygons == 1){
		/* multi-polygon ground (100 polygons) */
		glTranslatef(-45.0,45.0,45.0);

		for(i = 0; i < 10; i++){
			for(j = 0; j < 10; j++){
				glCallList(2);
				glTranslatef(size,0.0,0.0);
			}
			glTranslatef(-j*size,-size,0.0);
		}
	}

}

void display( ){
    /* clear the window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(0, 40, 0, /* Camer Position */
			  0, 0, -100,	/* Look Direction */
			  0, 1, 0);		/* Up Vector */
	glRotatef(angle,0,1,0);

    /* rotate and place components in the right place */
    glPushMatrix();
		makeHouse();
		glTranslatef(0.0,-5.0,0.0);
		glRotatef(90,0.0,1.0,0.0);
		glRotatef(180,0.0,0.0,1.0);
		makeRoof();
		glTranslatef(0.0,28.2,28.2);
		glRotatef(90,0.0,1.0,1.0);
		glRotatef(135,1.0,0.0,0.0);
		makeGround();
    glPopMatrix();


	/* rotate and place the sun in the right place */
	glPushMatrix();
		glRotatef(ang,0.0,0.0,-1.0);
		glTranslatef(-50.0,0.0,0.0);
		glRotatef(ang,0.0,0.0,1.0);
		Sun();
		tetrahedron (4);
	glPopMatrix();

	/* place the spotlight in the right place */
	glTranslatef(0.0,10.0,10.0);
	SpotLight();

	/* enable/disable spotlight */
	glPushMatrix();
		if(spotlight == 1){
			glEnable(GL_LIGHT1);
		}
		if(spotlight == 0){
			glDisable(GL_LIGHT1);
		}
	glPopMatrix();

	/* change shadow model */
	if (shadows == 0){
		glShadeModel(GL_SMOOTH);
	}
	else if(shadows == 1){
		glShadeModel(GL_FLAT);
	}

	glutSwapBuffers();
}

void keyboard(int key, int x , int y){
/* keyboard function for perspective rotation */
	if(key == GLUT_KEY_RIGHT){ 
		angle -= 1;
	}
	if(key == GLUT_KEY_LEFT){ 
		angle += 1;
	}
	glutPostRedisplay();
}

void idle(){
/* idle function for constant value change */
	ang += 0.5;
	R += light;
	G += light;
	B += light;
	if(ang == 90){
		R = 1.0;
		G = 1.0;
		B = 1.0;
		light = -light;
	}
	if(ang == 180){
		ang = 0;
		R = 0.3;
		G = 0.3;
		B = 0.3;
		light = -light;
	}
    glutPostRedisplay();
}

void polygons_menu(int id){
    if(id==1){
		polygons = 0;
    }
    if(id==2){
		polygons = 1;
    }
}

void spot_menu(int id){
    if(id==1){
		spotlight = 1;
    }
    if(id==2){
		spotlight = 0;
    }
}

void shadows_menu(int id){
    if(id==1){
		shadows = 0;
    }
    if(id==2){
		shadows = 1;
    }
}

void demo_menu(int id){
    if(id==1){
		spotlight = 1;
    }
    if(id==2){
		spotlight = 0;
    }
    if(id==3) {exit(0);}
}


int main(int argc, char** argv){
	/* menu ids */
	int spot;
	int poly;
	int shad;

	/* Standard GLUT initialization */
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,800); /* 800 x 800 pixel window */
    glutInitWindowPosition(300,100); /* place window on display */
    glutCreateWindow("House"); /* window title */
    glutIdleFunc(idle);

    myinit(); /* set attributes */

	glutDisplayFunc(display);

	/* Move With Arrow Keys */
	glutSpecialFunc(keyboard);

	/* create spotlight sub menu */
	spot = glutCreateMenu(spot_menu);
	glutAddMenuEntry("On",1);
	glutAddMenuEntry("Broken",2);

	/* create polygons sub menu */
	poly = glutCreateMenu(polygons_menu);
	glutAddMenuEntry("Potato",1);
	glutAddMenuEntry("Nasa PC",2);

	/* create shadows sub menu */
	shad = glutCreateMenu(shadows_menu);
	glutAddMenuEntry("Smooth",1);
	glutAddMenuEntry("Flat(No Budget)",2);

	/* create main menu */
    glutCreateMenu(demo_menu);
	glutAddSubMenu("Spotlight",spot);
	glutAddSubMenu("Polygons",poly);
	glutAddSubMenu("Shadows",shad);
    glutAddMenuEntry("Quit",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop(); /* enter event loop */
	return 0;
}


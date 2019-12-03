//
//  main.cpp
//  ProyectoFinal
//
//  Created by José María Aguíñiga Díaz on 01/12/19.
//  Copyright © 2019 José María Aguíñiga Díaz. All rights reserved.
//

/*
Jose Maria Aguiniga Diaz
A01376669
Jose Rodrigo Narvaez Berlanga
*/

#include <iostream>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "imageloader.h"
#include <math.h>
#include <ctime>
#include <algorithm>
#include <vector>
#include <fstream>

#include <string>
#include <stdarg.h>
#include <iostream>



#ifdef __APPLE__

#include <GLUT/glut.h>

#else

#include <GL/glut.h>

#endif

using namespace std;






double x_axis = -20;

double x_animation_axis = -20;

double y_animation_axis, height, z_axis, x_deep_axis = 0;
double zi, col = 0;

double deep_z = 0.65;

double y_axis = 35.0;

char s[30];

bool has_light = false;


bool hasAmbiental = false;

int light_position = 0;
int light_color = 5;

int colorPersp = light_color;



float Noemit[4] = { 0.0, 0.0, 0.0, 1.0 };

float shininess = 75;


float posiciones[2][4] = { { -0.5, -1.0, 1.0, 1 } , { -0.5, -1.0, -0.3, 1 } };
float luz[2][4] = { { 0.5, 1.0, -1.0, 1 } , { -0.9, -0.2, -0.8, 1 } };


float AmbientDifferent[5][4] = {
   {1.0, 1.0, 1.0, 1.0},
   {0.5, 0.5, 0.0, 1.0},
   {0.0, 1.0, 0.0, 1.0},
   {0.0, 0.5, 0.5, 1.0},
   {1.0, 0.0, 1.0, 1.0}
};


float ambientLight[4] = { 0.2, 0.2, 0.2, 1.0 };
float Lt0amb[4] = { 0.3, 0.3, 0.3, 1.0 };
float Lt0diff[4] = { 1.0, 1.0, 1.0, 1.0 };
float Lt0spec[4] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat directedLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
float dirI[4] = { 1, 0, 0, 0 };
float dirII[4] = { 0, 0, 0, 1 };



void init(void) {
    //Initializes the window with the background, matrix mode and coordenates.
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0f);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0f, 1200, 600, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void ambientalOn() {
    glLightfv(GL_LIGHT0, GL_POSITION, dirI);
}

void ambientalOff() {
    glLightfv(GL_LIGHT0, GL_POSITION, posiciones[light_position]); // Position is transformed by ModelView matrix
    glLightfv(GL_LIGHT0, GL_POSITION, luz[light_position]);
}


void lightningOn() {

    // Posicionamiento de la iluminacion

    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Lt0spec);

    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Noemit);
    hasAmbiental ? ambientalOn() : ambientalOff();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, Lt0amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, Lt0diff);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, directedLight);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, dirII);
    glLightfv(GL_LIGHT0, GL_SPECULAR, Lt0spec);
}

void lightningOptions() {
//    printf("\n Menu para modificar la fuente de luz");
    //printf("\n\n1. Elija el tipo de iluminacion que desea \n\n\t(1) Ambiental \n\t[2] Fuente Directa");
    printf("\n\n1. Elija el tipo de iluminacion que desea");
    printf("\n\n1. (1) Ingrese 1 si quiere la opción: Iluminacion Ambiente");
    printf("\n\n1. (2) Ingrese 2 si quiere la opción: Iluminacion Fuente Directa");
    char light_type[10];
    cout << "\n\nIngresa la opcion: ";
    cin >> light_type;
    printf("\n\n1. (1) Ingrese 1 si quiere color: Blanco");
    printf("\n\n1. (2) Ingrese 2 si quiere color: Amarillo");
    printf("\n\n1. (3) Ingrese 3 si quiere color: Verde");
    printf("\n\n1. (4) Ingrese 4 si quiere color: Cyan");
    printf("\n\n1. (5) Ingrese 5 si quiere color: Magenta");
    char color[10];
    cout << "\n\nIngresa la opcion: ";
    cin >> color;



    printf("\n\n1. (1) Ingrese 1 si quiere color: Blanco");
    printf("\n\n1. (2) Ingrese 2 si quiere color: Amarillo");
    char posicion[10];
    cout << "\n\nIngresa la opcion: ";
    cin >> posicion;






    if ((atoi(light_type) == 1 || atoi(light_type) == 2) && (atoi(posicion) == 1 || atoi(posicion) == 2) && (atoi(color) == 1 || atoi(color) == 2 || atoi(color) == 3 || atoi(color) == 4 || atoi(color) == 5)) {

        light_color = atoi(color) - 1;

        if (atoi(light_type) == 1) {

            hasAmbiental = true;
        } else {
            hasAmbiental = false;
        }
        if (atoi(posicion) == 1) {
            light_position = 0;
        } else {
            light_position = 1;
        }

        glEnable(GL_LIGHTING);

        lightningOn();



        printf("\n\nTeclee espacio dentro del proyecto para activar la iluminacion\n\n");

    }

    else {

        printf("\n\nOPCIONES INVALIDAS! INTENTA NUEVAMENTE\n");

        lightningOptions();

    }

}





void constantAnimation(int value) {
    y_animation_axis += 0.05;
    
    
    
    glutTimerFunc(20000000, constantAnimation, 0);
    glutPostRedisplay();

}


void testSquare(void) {
    glColorMaterial(GL_FRONT, GL_SHININESS);
    glEnable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AmbientDifferent[light_color]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, AmbientDifferent[colorPersp]);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    
    //first squares
    glColor3f(255.0, 140.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.2f,0.2f,0);
        glVertex3f(0.8f,0.2f,0);
        glVertex3f(0.8f,-0.8f,0);
        glVertex3f(-0.2f,-0.8f,0);
    glEnd();
    
    glColor3f(255.0, 165.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.5f,0.5f,-0.5);
        glVertex3f(0.5f,0.5f,-0.5);
        glVertex3f(0.5f,-0.5f,-0.5);
        glVertex3f(-0.5f,-0.5f,-0.5);
    glEnd();

    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.6f,0.6f,-0.7);
        glVertex3f(0.4f,0.6f,-0.7);
        glVertex3f(0.4f,-0.4f,-0.7);
        glVertex3f(-0.6f,-0.4f,-0.7);
    glEnd();

    glColor3f(0.0, 0.0, 205.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.8f,0.8f,-0.9);
        glVertex3f(0.2f,0.8f,-0.9);
        glVertex3f(0.2f,-0.2f,-0.9);
        glVertex3f(-0.8f,-0.2f,-0.9);
    glEnd();
//
//    //second squares
    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(1.0f,0.2f,0);
        glVertex3f(2.0f,0.2f,0);
        glVertex3f(2.0f,-0.8f,0);
        glVertex3f(1.0f,-0.8f,0);
    glEnd();

    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.7f,0.5f,-0.5);
        glVertex3f(1.7f,0.5f,-0.5);
        glVertex3f(1.7f,-0.5f,-0.5);
        glVertex3f(0.7f,-0.5f,-0.5);
    glEnd();

    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.6f,0.6f,-0.7);
        glVertex3f(1.6f,0.6f,-0.7);
        glVertex3f(1.6f,-0.4f,-0.7);
        glVertex3f(0.6f,-0.4f,-0.7);
    glEnd();
//////
    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.4f,0.8f,-0.9);
        glVertex3f(1.4f,0.8f,-0.9);
        glVertex3f(1.4f,-0.2f,-0.9);
        glVertex3f(0.4f,-0.2f,-0.9);
    glEnd();
//
//    //Left rectangles

    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.4f,0.2f,0);
        glVertex3f(-1.4f,0.2f,0);
        glVertex3f(-1.4f,-0.8f,0);
        glVertex3f(-0.4f,-0.8f,0);
    glEnd();

    glColor3f(255.0, 0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.7f,0.5f,-0.5);
        glVertex3f(-1.7f,0.5f,-0.5);
        glVertex3f(-1.7f,-0.5f,-0.5);
        glVertex3f(-0.7f,-0.5f,-0.5);
    glEnd();

    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.8f,0.6f,-0.7);
        glVertex3f(-1.8f,0.6f,-0.7);
        glVertex3f(-1.8f,-0.4f,-0.7);
        glVertex3f(-0.8f,-0.4f,-0.7);
    glEnd();

    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-1.0f,0.8f,-0.9);
        glVertex3f(-2.0f,0.8f,-0.9);
        glVertex3f(-2.0f,-0.2f,-0.9);
        glVertex3f(-1.0f,-0.2f,-0.9);
    glEnd();
//
//
    
    glColorMaterial(GL_FRONT, GL_EMISSION);

    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.3,0.3,0.3);
    glBegin(GL_QUADS);
        glVertex3f(-2.0f,-1.0f,-1.0);
        glVertex3f(2.0f,-1.0f,-1.0);
        glVertex3f(2.0f,-1.0f,1.0);
        glVertex3f(-2.0f,-1.0f,1.0);
    glEnd();
    
}

void forLines(void) {
    
    
    GLfloat t = -0.6f;
    GLfloat t1 = 1.0f;
    GLfloat k = -0.8f;
    GLfloat j = -0.5f;
    GLfloat u = -0.2f;
    GLfloat q = 0.7f;
    GLfloat q1 = 0.6f;
    GLfloat q2 = 0.4f;
    GLfloat h = -1.4f;
    GLfloat h1 = -1.7f;
    GLfloat h2 = -1.8f;
    GLfloat h3 = -2.0f;
//
    for (int i = 0; i < 33; i++)
    {
        t = t + 0.03;
        t1 = t1 + 0.03;

        k = k + 0.03;
        glColor3f(0.0, 0.0, 205.0);
        glBegin(GL_LINES);
            glVertex3f(k,0.8f,-0.9);
            glVertex3f(k,-0.2f,-0.9);
        glEnd();

        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(t,0.6f,-0.7);
            glVertex3f(t,-0.4f,-0.7);
        glEnd();

        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(t1,0.2f,0);
            glVertex3f(t1,-0.8f,0);
        glEnd();

        j = j + 0.03;
        glColor3f(255.0, 165.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(j,0.5f,-0.5);
            glVertex3f(j,-0.5f,-0.5);
        glEnd();

        //Second squares
        u = u + 0.03;
        glColor3f(255.0, 165.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(u,0.2f,0);
            glVertex3f(u,-0.8f,0);
        glEnd();

        q = q + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(q,0.5f,-0.5);
            glVertex3f(q,-0.5f,-0.5);
        glEnd();

        q1 = q1 + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(q1,0.6f,-0.7);
            glVertex3f(q1,-0.4f,-0.7);
        glEnd();

        q2 = q2 + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(q2,0.8f,-0.9);
            glVertex3f(q2,-0.2f,-0.9);
        glEnd();
//
        h = h + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(h,0.2f,0);
            glVertex3f(h,-0.8f,0);
        glEnd();

        h1 = h1 + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(h1,0.5f,-0.5);
            glVertex3f(h1,-0.5f,-0.5);
        glEnd();

        h2 = h2 + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(h2,0.6f,-0.7);
            glVertex3f(h2,-0.4f,-0.7);
        glEnd();

        h3 = h3 + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(h3,0.8f,-0.9);
            glVertex3f(h3,-0.2f,-0.9);
        glEnd();
    }
    
}

void lightningOnMethod(void) {
    glEnable(GL_LIGHTING);
    lightningOn();
}

void render(void) {
    //glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Vision camara
    gluLookAt(0, 0, 0, col, zi, 0, 0, 0, 0);
    
    glLoadIdentity();
    glViewport(0, 300, 1200, 500);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glRotatef(x_axis, 1.0, 0.0, 0.0);

    glRotatef(y_axis, 0.0, 1.0, 0.0);

    glScalef(deep_z, deep_z, deep_z);

    glTranslatef(0, height, z_axis);

    glTranslatef(x_deep_axis, height, 0);

    testSquare();
    forLines();

    glPopMatrix();
    


    glViewport(0, -50, 600, 400);



    glMatrixMode(GL_MATRIX_MODE);

    glPushMatrix();

    glLoadIdentity();

    glRotatef(x_animation_axis, 1.0, 0.0, 0.0);

    glRotatef(y_animation_axis, 0.0, 1.0, 0.0);
    

    testSquare();
    forLines();
    
    glPopMatrix();
    
    constantAnimation(0);
    
    !has_light ? glDisable(GL_LIGHTING) : lightningOnMethod() ;

    
    glFlush();
    glutSwapBuffers();
}

void positioningKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        y_axis += 5;
    } else if (key == GLUT_KEY_LEFT) {
        y_axis -= 5;
    } else if (key == GLUT_KEY_UP) {
        x_axis += 5;
    } else if (key == GLUT_KEY_DOWN) {
        x_axis -=5;
    }
    
    glutPostRedisplay();
}


void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset

}

void keyboard(unsigned char key, int x, int y) {
    //Inside the switch by the key recieved by the params we execute the function the user wants to be executed.
    switch(key) {
        //In the case of R, the tile gets rotated 10 degrees to the wrong way of the clock's hands.
        case '+':
            deep_z += 0.05;
            glutPostRedisplay();
            break;
        case '-':
            deep_z -= 0.05;
            glutPostRedisplay();
            break;
        case 'u':
            height += 0.05;
            glutPostRedisplay();
            break;
        case 'd':
            height -= 0.05;
            glutPostRedisplay();
            break;
        case 'i':
            lightningOptions();
            glutPostRedisplay();
            break;
        case ' ':
            has_light = !has_light;
            glutPostRedisplay();
            break;
   }
}



//We define our main method that will handle all the previous methods bellow.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(1200, 750);
    glutCreateWindow("Proyecto Final");
    glutDisplayFunc(render);       // Register callback handler for window re-paint
    glutSpecialFunc(positioningKeys);
    glutReshapeFunc(reshape);
    init();
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

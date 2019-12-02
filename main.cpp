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
*/

#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>

float angle = 45.0;
int timeElapsed = 0;
GLfloat y = 0.5f;
GLfloat x = 0.3f;
float t = 0.1;
GLfloat xMov = 0.1f;
GLfloat xMovDos = 0.1f;
GLfloat yMovDos = 0.1f;
GLfloat yMov = 0.1f;

void init(void) {
    //Initializes the window with the background, matrix mode and coordenates.
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0.0,0.0,0.0,0.0);
}

//void greySquare(void) {
//    //Paints the grey big square that goes at the bottom of the tile
//    glColor3f(0.3,0.3,0.3);
//    glBegin(GL_QUADS);
//        glVertex3f(-0.5f,y,0);
//        glVertex3f(0.5f,0.5f,0);
//        glVertex3f(0.5f,-0.5f,0);
//        glVertex3f(-0.5f,-0.5f,0);
//    glEnd();
//}

//void middleLines(void) {
//    //Paints the lines that goes through the x axis and the y axis.
//    glColor3f(0.0,0.0,0.0);
//    glBegin(GL_LINES);
//        glVertex3f(0,0.5f,0);
//        glVertex3f(0,-0.5f,0);
//    glEnd();
//    glColor3f(0.0,0.0,0.0);
//    glBegin(GL_LINES);
//        glVertex3f(-0.5f,0,0);
//        glVertex3f(0.5f,0,0);
//    glEnd();
//
//}

//void bats(void) {
//    //Paints the black triangles that goes on each quadrant of the tile.
//    glColor3f(0.0,0.0,0.0);
//    glBegin(GL_TRIANGLES);
//        glVertex3f(-0.4f,0.4f,0);
//        glVertex3f(-0.2f,0.4f,0);
//        glVertex3f(-0.4f,0.2f,0);
//    glEnd();
//
//    glColor3f(0.0,0.0,0.0);
//    glBegin(GL_TRIANGLES);
//        glVertex3f(0.4f,0.4f,0);
//        glVertex3f(0.2f,0.4f,0);
//        glVertex3f(0.4f,0.2f,0);
//    glEnd();
//
//    glColor3f(0.0,0.0,0.0);
//    glBegin(GL_TRIANGLES);
//        glVertex3f(0.4f,-0.4f,0);
//        glVertex3f(0.2f,-0.4f,0);
//        glVertex3f(0.4f,-0.2f,0);
//    glEnd();
//
//    glColor3f(0.0,0.0,0.0);
//    glBegin(GL_TRIANGLES);
//        glVertex3f(-0.4f,-0.4f,0);
//        glVertex3f(-0.2f,-0.4f,0);
//        glVertex3f(-0.4f,-0.2f,0);
//    glEnd();
//}
//
//void redPolygons(void) {
//    //Paints the two red polygons of the center of the tile, one above the other.
//    glColor3f(1.0,0.0,0.0);
//    glBegin(GL_QUADS);
//        glVertex3f(0,0.3f,0);
//        glVertex3f(x,0,0);
//        glVertex3f(0,-0.3f,0);
//        glVertex3f(-0.3f,0,0);
//    glEnd();
//
//    glColor3f(0.3,0.0,0.0);
//    glBegin(GL_QUADS);
//        glVertex3f(0,0.2f,0);
//        glVertex3f(0.2f,0,0);
//        glVertex3f(0,-0.2f,0);
//        glVertex3f(-0.2f,0,0);
//    glEnd();
//}
//
//void circleCenter(void) {
//    //Paints the middle circle of the tile
//    float theta; //Declare a floating variable for the cos function
//    glColor3f(1.0, 0.0, 0.0); //Color of the circle, in this case red.
//    glBegin(GL_POLYGON); //Declaring a polygon
//    for (int i = 0; i < 360; i++)
//    {
//        theta = i * 3.142/180;
//        glVertex2f(t*cos(theta), t*sin(theta));
//    }
//    glEnd();
//}

void testSquare(void) {
    
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
        glVertex3f(-0.5f,0.5f,0);
        glVertex3f(0.5f,0.5f,0);
        glVertex3f(0.5f,-0.5f,0);
        glVertex3f(-0.5f,-0.5f,0);
    glEnd();
    
    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.6f,0.6f,0);
        glVertex3f(0.4f,0.6f,0);
        glVertex3f(0.4f,-0.4f,0);
        glVertex3f(-0.6f,-0.4f,0);
    glEnd();
    
    glColor3f(0.0, 0.0, 205.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.8f,0.8f,0);
        glVertex3f(0.2f,0.8f,0);
        glVertex3f(0.2f,-0.2f,0);
        glVertex3f(-0.8f,-0.2f,0);
    glEnd();
    
    //second squares
    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(1.0f,0.2f,0);
        glVertex3f(2.0f,0.2f,0);
        glVertex3f(2.0f,-0.8f,0);
        glVertex3f(1.0f,-0.8f,0);
    glEnd();
    
    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.7f,0.5f,0);
        glVertex3f(1.7f,0.5f,0);
        glVertex3f(1.7f,-0.5f,0);
        glVertex3f(0.7f,-0.5f,0);
    glEnd();
////
    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.6f,0.6f,0);
        glVertex3f(1.6f,0.6f,0);
        glVertex3f(1.6f,-0.4f,0);
        glVertex3f(0.6f,-0.4f,0);
    glEnd();
////
    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.4f,0.8f,0);
        glVertex3f(1.4f,0.8f,0);
        glVertex3f(1.4f,-0.2f,0);
        glVertex3f(0.4f,-0.2f,0);
    glEnd();
    
    //Left rectangles
    
    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.4f,0.2f,0);
        glVertex3f(-1.4f,0.2f,0);
        glVertex3f(-1.4f,-0.8f,0);
        glVertex3f(-0.4f,-0.8f,0);
    glEnd();
    
    glColor3f(255.0, 0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.7f,0.5f,0);
        glVertex3f(-1.7f,0.5f,0);
        glVertex3f(-1.7f,-0.5f,0);
        glVertex3f(-0.7f,-0.5f,0);
    glEnd();
    
    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.8f,0.6f,0);
        glVertex3f(-1.8f,0.6f,0);
        glVertex3f(-1.8f,-0.4f,0);
        glVertex3f(-0.8f,-0.4f,0);
    glEnd();
    
    glColor3f(255.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-1.0f,0.8f,0);
        glVertex3f(-2.0f,0.8f,0);
        glVertex3f(-2.0f,-0.2f,0);
        glVertex3f(-1.0f,-0.2f,0);
    glEnd();
    
    
    
}

void forLines(void) {
    
//    GLfloat k = -0.8f;
//    for (int i = 0; i < 33; i++)
//    {
//        k = k + 0.03;
//        glColor3f(0.0, 0.0, 205.0);
//        glBegin(GL_LINES);
//            glVertex3f(k,0.8f,0);
//            glVertex3f(k,-0.2f,0);
//        glEnd();
//    }
    
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
    
    for (int i = 0; i < 33; i++)
    {
        t = t + 0.03;
        t1 = t1 + 0.03;
        
        k = k + 0.03;
        glColor3f(0.0, 0.0, 205.0);
        glBegin(GL_LINES);
            glVertex3f(k,0.8f,0);
            glVertex3f(k,-0.2f,0);
        glEnd();
        
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(t,0.6f,0);
            glVertex3f(t,-0.4f,0);
        glEnd();
        
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(t1,0.2f,0);
            glVertex3f(t1,-0.8f,0);
        glEnd();
        
        j = j + 0.03;
        glColor3f(255.0, 165.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(j,0.5f,0);
            glVertex3f(j,-0.5f,0);
        glEnd();
        
        //Second squares
        u = u + 0.03;
        glColor3f(255.0, 165.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(u,0.2f,0);
            glVertex3f(u,-0.8f,0);
        glEnd();
//
        q = q + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(q,0.5f,0);
            glVertex3f(q,-0.5f,0);
        glEnd();
        
        q1 = q1 + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(q1,0.6f,0);
            glVertex3f(q1,-0.4f,0);
        glEnd();
        
        q2 = q2 + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(q2,0.8f,0);
            glVertex3f(q2,-0.2f,0);
        glEnd();
        
        h = h + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(h,0.2f,0);
            glVertex3f(h,-0.8f,0);
        glEnd();
        
        h1 = h1 + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(h1,0.5f,0);
            glVertex3f(h1,-0.5f,0);
        glEnd();
        
        h2 = h2 + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(h2,0.6f,0);
            glVertex3f(h2,-0.4f,0);
        glEnd();
        
        h3 = h3 + 0.03;
        glColor3f(255.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(h3,0.8f,0);
            glVertex3f(h3,-0.2f,0);
        glEnd();
    }
    
//    GLfloat j = -0.5f;
//    for (int i = 0; i < 33; i++)
//    {
//        j = j + 0.03;
//        glColor3f(255.0, 165.0, 0.0);
//        glBegin(GL_LINES);
//            glVertex3f(j,0.5f,0);
//            glVertex3f(j,-0.5f,0);
//        glEnd();
//    }
    
//    GLfloat u = -0.2f;
//    for (int i = 0; i < 33; i++)
//    {
//        u = u + 0.03;
//        glColor3f(255.0, 165.0, 0.0);
//        glBegin(GL_LINES);
//            glVertex3f(u,0.2f,0);
//            glVertex3f(u,-0.8f,0);
//        glEnd();
//    }
    
    
}

//void testLines(void) {
//
//    //    for (int i = -0.5f; i < 0.5f; i += 0.05f)
//    //    {
//    //        glVertex3f(i,0.5f,0);
//    //        glVertex3f(i,-0.5f,0);
//    //    }
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.47,0.5f,0);
//        glVertex3f(-0.47,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.44,0.5f,0);
//        glVertex3f(-0.44,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.41,0.5f,0);
//        glVertex3f(-0.41,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.38,0.5f,0);
//        glVertex3f(-0.38,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.35,0.5f,0);
//        glVertex3f(-0.35,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.32,0.5f,0);
//        glVertex3f(-0.32,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.29,0.5f,0);
//        glVertex3f(-0.29,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.26,0.5f,0);
//        glVertex3f(-0.26,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.23,0.5f,0);
//        glVertex3f(-0.23,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.20,0.5f,0);
//        glVertex3f(-0.20,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.17,0.5f,0);
//        glVertex3f(-0.17,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.14,0.5f,0);
//        glVertex3f(-0.14,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.11,0.5f,0);
//        glVertex3f(-0.11,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.08,0.5f,0);
//        glVertex3f(-0.08,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.05,0.5f,0);
//        glVertex3f(-0.05,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(-0.02,0.5f,0);
//        glVertex3f(-0.02,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.01,0.5f,0);
//        glVertex3f(0.01,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.04,0.5f,0);
//        glVertex3f(0.04,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.07,0.5f,0);
//        glVertex3f(0.07,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.10,0.5f,0);
//        glVertex3f(0.10,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.13,0.5f,0);
//        glVertex3f(0.13,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.15,0.5f,0);
//        glVertex3f(0.15,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.18,0.5f,0);
//        glVertex3f(0.18,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.21,0.5f,0);
//        glVertex3f(0.21,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.24,0.5f,0);
//        glVertex3f(0.24,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.27,0.5f,0);
//        glVertex3f(0.27,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.30,0.5f,0);
//        glVertex3f(0.30,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.33,0.5f,0);
//        glVertex3f(0.33,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.36,0.5f,0);
//        glVertex3f(0.36,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.39,0.5f,0);
//        glVertex3f(0.39,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.42,0.5f,0);
//        glVertex3f(0.42,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.45,0.5f,0);
//        glVertex3f(0.45,-0.5f,0);
//
//
//    glEnd();
//
//    glColor3f(255.0, 165.0, 0.0);
//    glBegin(GL_LINES);
//
//        glVertex3f(0.48,0.5f,0);
//        glVertex3f(0.48,-0.5f,0);
//
//
//    glEnd();
//
//}

void render(void) {
    glClear(GL_COLOR_BUFFER_BIT);
//    glPushMatrix();
//
//    //We paint every component of the tile.
//
    testSquare();
    forLines();
    //testLines();
//    greySquare();
//    bats();
//    middleLines();
//    redPolygons();
//    circleCenter();
//
//    glPopMatrix();
    glFlush();
}

//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//    glPushMatrix();
//    if(timeElapsed <= 47500) {
//
//        if(timeElapsed <= 40000) {
//            angle += 0.5;
//            glRotatef(angle, 0.0, 1.0, 1.0);
//        } else if(timeElapsed <= 41000) {
//            y += 0.01;
//        } else if(timeElapsed <= 42000) {
//            x += 0.01;
//        } else if(timeElapsed <= 45000){
//            t += 0.01;
//        } else if(timeElapsed <= 47000){
//            t = 0.1;
//            x = 0.3f;
//            y = 0.5f;
//            glScalef(0.01f,0.01f,0);
//        }
//        render();
//    } else if (timeElapsed <= 96000){
//
//        glColor3f(0.3,0.3,0.3);
//        glTranslatef(0.0f, yMovDos, 0.0);
//        glBegin(GL_QUADS);
//            glVertex3f(-0.5f,0.5f,0);
//            glVertex3f(0.5f,0.5f,0);
//            glVertex3f(0.5f,-0.5f,0);
//            glVertex3f(-0.5f,-0.5f,0);
//        glEnd();
//
//        glColor3f(1.0,0.0,0.0);
//        glTranslatef(xMov, 0.1f, 0.0);
//        glBegin(GL_QUADS);
//            glVertex3f(0,0.3f,0);
//            glVertex3f(x,0,0);
//            glVertex3f(0,-0.3f,0);
//            glVertex3f(-0.3f,0,0);
//        glEnd();
//
//        glColor3f(0.0,0.0,0.0);
//        glTranslatef(0.1f, yMov, 0.0);
//        glBegin(GL_TRIANGLES);
//            glVertex3f(-0.4f,0.4f,0);
//            glVertex3f(-0.2f,0.4f,0);
//            glVertex3f(-0.4f,0.2f,0);
//        glEnd();
//
//        glColor3f(0.0,0.0,0.0);
//        glTranslatef(0.1f, yMov, 0.0);
//        glBegin(GL_TRIANGLES);
//            glVertex3f(0.4f,0.4f,0);
//            glVertex3f(0.2f,0.4f,0);
//            glVertex3f(0.4f,0.2f,0);
//        glEnd();
//
//        glColor3f(0.0,0.0,0.0);
//        glTranslatef(xMovDos, yMov, 0.0);
//        glBegin(GL_TRIANGLES);
//            glVertex3f(0.4f,-0.4f,0);
//            glVertex3f(0.2f,-0.4f,0);
//            glVertex3f(0.4f,-0.2f,0);
//        glEnd();
//
//        glColor3f(0.0,0.0,0.0);
//        glTranslatef(xMovDos, yMovDos, 0.0);
//        glBegin(GL_TRIANGLES);
//            glVertex3f(-0.4f,-0.4f,0);
//            glVertex3f(-0.2f,-0.4f,0);
//            glVertex3f(-0.4f,-0.2f,0);
//        glEnd();
//
//        glColor3f(0.3,0.0,0.0);
//        glTranslatef(xMovDos, 0.0, 0.0);
//        glBegin(GL_QUADS);
//            glVertex3f(0,0.2f,0);
//            glVertex3f(0.2f,0,0);
//            glVertex3f(0,-0.2f,0);
//            glVertex3f(-0.2f,0,0);
//        glEnd();
//
//        // float theta; //Declare a floating variable for the cos function
//        // glColor3f(1.0, 0.0, 0.0); //Color of the circle, in this case red.
//        // glTranslatef(xMovDos, 0.0, 0.0);
//        // glBegin(GL_POLYGON); //Declaring a polygon
//        // for (int i = 0; i < 360; i++)
//        // {
//        //     theta = i * 3.142/180;
//        //     glVertex2f(t*cos(theta), t*sin(theta));
//        // }
//
//        // if (timeElapsed >= 50000 && timeElapsed < 52000) {
//        //     yMov -= 0.00001;
//        //     xMov -= 0.00001;
//        // } else if (timeElapsed >= 52000 && timeElapsed < 55000) {
//        //   xMov += 0.00001;
//        //   yMov += 0.00001;
//        // } else if (timeElapsed >= 55000 && timeElapsed < 57000) {
//        //     yMov -= 0.00001;
//        //     xMov -= 0.00001;
//        // } else if (timeElapsed >= 57000 && timeElapsed < 59000) {
//        //     xMov += 0.00001;
//        //     yMov += 0.00001;
//        // }
//        xMov += 0.001;
//        yMov += 0.001;
//        xMovDos -= 0.001;
//        yMovDos -= 0.001;
//
//
//
//    } else if(timeElapsed <= 52000) {
//
//    }
//    glPopMatrix();
//    glutSwapBuffers();
//
//    timeElapsed += 30;
//
//}
//
//void timer(int value) {
//
//    glutPostRedisplay();
//    glutTimerFunc(30, timer, 0);
//}


//We define our main method that will handle all the previous methods bellow.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Miniproyecto");
    init();
    glutDisplayFunc(render);
    //glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}

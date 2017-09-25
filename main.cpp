#include <windows.h>
#include <gl/glut.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include "teardrop.h"

using namespace std;

int size_x = 640;
int size_y = 480;

float toRGBf(int x);
void draw();
void init();
void drawTeardrop(int x, int y);
void drawTeardrop(int x, int y, int quant);
void myMouse(int button, int state, int x, int y);

float toRGBf(int x){
    return (float)x/255;
}

void draw(){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}

void drawTeardrop(int x, int y){

    Teardrop *t1;
    t1 = new Teardrop(x, (y-size_y)*-1, 90);
    t1->printaPontos();

    glBegin(GL_LINE_STRIP);
        for(int i = 0; i<t1->retornaPontos().at(0).at(0); i++)
            glVertex2i(t1->retornaPontos().at(i+1).at(0) , t1->retornaPontos().at(i+1).at(1) );
    glEnd();
    glFlush();

}

void drawTeardrop(int x, int y, int quant){

    Teardrop *t1;
    for(int j = 0; j < 360 ; j+=360/quant){
        t1 = new Teardrop(x, (y-size_y)*-1, quant+j);
        t1->printaPontos();

        glBegin(GL_LINE_STRIP);
           for(int i = 0; i<t1->retornaPontos().at(0).at(0); i++)
                glVertex2i(t1->retornaPontos().at(i+1).at(0) , t1->retornaPontos().at(i+1).at(1) );
        glEnd();
        glFlush();
    }
}

void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0 , size_x, 0, size_y);
    glClearColor(toRGBf(85), toRGBf(125), toRGBf(145), 1.0f);
}

void myMouse(int button, int state, int x, int y){

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        drawTeardrop(x, y);

    }else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        drawTeardrop(x, y, 10);
    }

}

int main(void){

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(size_x,size_y);
    glutInitWindowPosition(400,200);

    glutCreateWindow("Teardrop");
    init();
    glutDisplayFunc(draw);
    glutMouseFunc(myMouse);

    glutMainLoop();
}


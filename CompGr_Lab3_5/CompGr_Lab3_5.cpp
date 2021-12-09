// CompGr_Lab3_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Triangle.h"
#include <vector>

GLfloat** GLfl_array_generator(GLfloat dim1, GLfloat dim2) {
    GLfloat** ptrary = new GLfloat * [dim1];
    for (int i = 0; i < dim1; i++) {
        ptrary[i] = new GLfloat[dim2];
    }
    return ptrary;
}
void GLfl_array_destroyer(GLfloat** ary, GLfloat dim1) {
    for (int i = 0; i < dim1; i++) {
        delete[] ary[i];
    }
    delete[] ary;
}

GLubyte** GLuby_array_generator(GLubyte dim1, GLubyte dim2) {
    GLubyte** ptrary = new GLubyte * [dim1];
    for (int i = 0; i < dim1; i++) {
        ptrary[i] = new GLubyte[dim2];
    }
    return ptrary;
}
void GLuby_array_destroyer(GLubyte** ary, GLubyte dim1) {
    for (int i = 0; i < dim1; i++) {
        delete[] ary[i];
    }
    delete[] ary;
}

void initializeGL()
{
    glClearColor(0.5,0.5,0.5,1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
}
void resizeGL(int sWidth, int sHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // borders
    glOrtho(-10, 10, -10, 10, -10, 10);
    glViewport(0, 0, (GLint)sWidth, (GLint)sHeight);
}

void paintGLSimple()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.25, 0.87, 0.87);
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0., 0.);
        glVertex2f(0.4, 0.2);
        glVertex2f(0.6, 0.2);
        glVertex2f(0.8, 0);
        glVertex2f(0., 0.);
    glEnd();
}

void paintGL2D()
{
    glDisable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.25, 0.87, 0.87);
    glLineWidth(4);
    
    GLfloat triangleVertexArray[5][3] = { {0, 0, 0}, {0.5, 0.5, 0}, {1, 0, 0},
                                            {0, 1, 0}, {1, 1, 0} };
    GLfloat triangleColorArray[5][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1},
                                            {0, 0., 0.5}, {0.5, 0, 0} };
    GLubyte triangleIndexArray[4][3] = { {1, 2, 0}, {0, 1, 3}, {1, 2, 4}, {1, 3, 4} };
    
    glVertexPointer(3, GL_FLOAT, 0, triangleVertexArray);
    glColorPointer(3, GL_FLOAT, 0, triangleColorArray);

    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, triangleIndexArray);
}
void paintGL3D()
{
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.25, 0.87, 0.87);

    GLfloat cubeVertexArray[8][3] = {
        {0., 0., 1.},
        {0., 1., 1.},
        {1., 1., 1.},
        {1., 0., 1.},
        {0., 0., 0.},
        {0., 1., 0.},
        {1., 1., 0.},
        {1., 0., 0.}
    };
    GLfloat cubeColorArray[8][3] = {
        {0., 0., 0.},
        {0., 0., 1.},
        {0., 1., 0.},
        {0., 1., 1.},
        {1., 0., 0.},
        {1., 0., 1.},
        {1., 1., 0.},
        {1., 1., 1.}
    };
    GLubyte cubeIndexArray[6][4] = {
        {0, 3, 2, 1},
        {0, 1, 5, 4},
        {7, 4, 5, 6},
        {3, 7, 6, 2},
        {1, 2, 6, 5},
        {0, 4, 7, 3}
    };

    glVertexPointer(3, GL_FLOAT, 0, cubeVertexArray);
    glColorPointer(3, GL_FLOAT, 0, cubeColorArray);

    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndexArray);
}

void paintGL2D_Fig1()
{
    glDisable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.25, 0.87, 0.87);

    //glLineWidth(4);

    GLfloat lambdaVertexArray[14][3] = {
        {-2.5, -3, 0},
        {-1.5, -3, 0},
        {0, 0, 0},
        {1.5, -3, 0},
        {2.5, -3, 0},
        {3.5, -3, 0},
        {3.5, -2, 0},
        {2, -2, 0},
        {-0.5, 3, 0},
        {-1.5, 3, 0},
        {-2.5, 3, 0},
        {-2.5, 2, 0},
        {-1, 2, 0},
        {-0.5, 1, 0} };
    GLfloat lambdaColorArray[14][3] = {
        {1, 1, 0},
        {1, 1, 0},
        {1, 0.5, 0},
        {1, 1, 0},
        {1, 1, 0},
        {1, 1, 0},
        {1, 1, 0},
        {1, 0.9, 0},
        {1, 0, 0},
        {1, 0, 0},
        {1, 0.1, 0.1},
        {1, 0.1, 0},
        {1, 0.1, 0},
        {1, 0.6, 0} };
    GLubyte lambdaIndexArray[4][4] = {
        {0, 1, 2, 13},
        {4, 5, 6, 7},
        {3, 4, 8, 9},
        {9, 10, 11, 12} };

    glVertexPointer(3, GL_FLOAT, 0, lambdaVertexArray);
    glColorPointer(3, GL_FLOAT, 0, lambdaColorArray);

    glDrawElements(GL_QUADS, 16, GL_UNSIGNED_BYTE, lambdaIndexArray);
}
void paintGL2D_Fig2()
{
    glDisable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    glLineWidth(4);

    GLfloat lambdaVertexArray[12][3] = {
        {-3.5, -0.5, 0},
        {1 - 3.5, 1 - 0.5, 0},
        {3.3 - 3.5, 1 - 0.5, 0},
        {3.3 - 3.5, -0.5, 0},
        {2 - 3.5, -0.5, 0},
        {2 - 3.5, 1 - 0.5, 0},
        {5 - 3.5, 1 - 0.5, 0},
        {5 - 3.5, -0.5, 0},
        {3.7 - 3.5, -0.5, 0},
        {3.7 - 3.5, 1 - 0.5, 0},
        {6 - 3.5, 1 - 0.5, 0},
        {7 - 3.5, -0.5, 0}};
    GLfloat lambdaColorArray[12][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0.1, 0.1, 0.1},
        {0.9, 0.9, 0.9},
        {0.9, 0.9, 0.9},
        {0.1, 0.1, 0.1},
        {0.1, 0.1, 0.1},
        {0.9, 0.9, 0.9},
        {0.9, 0.9, 0.9},
        {0.1, 0.1, 0.1},
        {0, 0, 0},
        {0, 0, 0} };
    GLubyte lambdaIndexArray[1][12] = { {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11} };

    glVertexPointer(3, GL_FLOAT, 0, lambdaVertexArray);
    glColorPointer(3, GL_FLOAT, 0, lambdaColorArray);

    glDrawElements(GL_LINE_STRIP, 12, GL_UNSIGNED_BYTE, lambdaIndexArray);
}

void paintGL3D_HL() {
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.25, 0.87, 0.87);

    GLfloat lambdaVertexArray[28][3] = {
        {-2.5, -3, 0.5},
        {-1.5, -3, 0.5},
        {0, 0, 0.5},
        {1.5, -3, 0.5},
        {2.5, -3, 0.5},
        {3.5, -3, 0.5},
        {3.5, -2, 0.5},
        {2, -2, 0.5},
        {-0.5, 3, 0.5},
        {-1.5, 3, 0.5},
        {-2.5, 3, 0.5},
        {-2.5, 2, 0.5},
        {-1, 2, 0.5},
        {-0.5, 1, 0.5},
        //
        {-2.5, -3, -0.5},
        {-1.5, -3, -0.5},
        {0, 0, -0.5},
        {1.5, -3, -0.5},
        {2.5, -3, -0.5},
        {3.5, -3, -0.5},
        {3.5, -2, -0.5},
        {2, -2, -0.5},
        {-0.5, 3, -0.5},
        {-1.5, 3, -0.5},
        {-2.5, 3, -0.5},
        {-2.5, 2, -0.5},
        {-1, 2, -0.5},
        {-0.5, 1, -0.5}
    };
    GLfloat lambdaColorArray[28][3] = {
        {1, 1, 0},
        {1, 1, 0},
        {1, 0.5, 0},
        {1, 1, 0},
        {1, 1, 0},
        {1, 1, 0},
        {1, 1, 0},
        {1, 0.9, 0},
        {1, 0, 0},
        {1, 0, 0},
        {1, 0.1, 0.1},
        {1, 0.1, 0},
        {1, 0.1, 0},
        {1, 0.6, 0},
        //
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 0.6, 0.1},
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 0.1, 0.1},
        {1, 0.1, 0.1},
        {1, 0.2, 0.2},
        {1, 0.2, 0.1},
        {1, 0.2, 0.1},
        {1, 0.7, 0.1},
    };
    GLubyte lambdaIndexArray[22][4] = {
        {0, 1, 2, 13},
        {4, 5, 6, 7},
        {3, 4, 8, 9},
        {9, 10, 11, 12},

        {27, 16, 15, 14},
        {21, 20, 19, 18},
        {23, 22, 18, 17},
        {26, 25, 24, 23},

        {14, 15, 1, 0},
        {15, 16, 2, 1},
        {16, 17, 3, 2},
        {17, 18, 4, 3},
        {18, 19, 5, 4},
        {19, 20, 6, 5},
        {20, 21, 7, 6},
        {21, 22, 8, 7},
        {22, 23, 9, 8},
        {23, 24, 10, 9},
        {24, 25, 11, 10},
        {25, 26, 12, 11},
        {26, 27, 13, 12},
        {27, 14, 0, 13}
    };

    glVertexPointer(3, GL_FLOAT, 0, lambdaVertexArray);
    glColorPointer(3, GL_FLOAT, 0, lambdaColorArray);

    glDrawElements(GL_QUADS, 88, GL_UNSIGNED_BYTE, lambdaIndexArray);

    GLfloat ringVertexArray[64][3] = {
        {1, 0, 0.5},
        {0.92, 0.38, 0.5},
        {0.71, 0.71, 0.5},
        {0.38, 0.92, 0.5},
        {0, 1, 0.5},
        {-0.38, 0.92, 0.5},
        {-0.71, 0.71, 0.5},
        {-0.92, 0.38, 0.5},
        {-1, 0, 0.5},
        {-0.92, -0.38, 0.5},
        {-0.71, -0.71, 0.5},
        {-0.38, -0.92, 0.5},
        {0, -1, 0.5},
        {0.38, -0.92, 0.5},
        {0.71, -0.71, 0.5},
        {0.92, -0.38, 0.5},
        //
        { 1, 0, 0.5 },
        {0.92, 0.38, 0.5},
        {0.71, 0.71, 0.5},
        {0.38, 0.92, 0.5},
        {0, 1, 0.5},
        {-0.38, 0.92, 0.5},
        {-0.71, 0.71, 0.5},
        {-0.92, 0.38, 0.5},
        {-1, 0, 0.5},
        {-0.92, -0.38, 0.5},
        {-0.71, -0.71, 0.5},
        {-0.38, -0.92, 0.5},
        {0, -1, 0.5},
        {0.38, -0.92, 0.5},
        {0.71, -0.71, 0.5},
        {0.92, -0.38, 0.5},
        //
        { 1, 0, -0.5 },
        {0.92, 0.38, -0.5},
        {0.71, 0.71, -0.5},
        {0.38, 0.92, -0.5},
        {0, 1, -0.5},
        {-0.38, 0.92, -0.5},
        {-0.71, 0.71, -0.5},
        {-0.92, 0.38, -0.5},
        {-1, 0, -0.5},
        {-0.92, -0.38, -0.5},
        {-0.71, -0.71, -0.5},
        {-0.38, -0.92, -0.5},
        {0, -1, -0.5},
        {0.38, -0.92, -0.5},
        {0.71, -0.71, -0.5},
        {0.92, -0.38, -0.5},
        //
        { 1, 0, -0.5 },
        {0.92, 0.38, -0.5},
        {0.71, 0.71, -0.5},
        {0.38, 0.92, -0.5},
        {0, 1, -0.5},
        {-0.38, 0.92, -0.5},
        {-0.71, 0.71, -0.5},
        {-0.92, 0.38, -0.5},
        {-1, 0, -0.5},
        {-0.92, -0.38, -0.5},
        {-0.71, -0.71, -0.5},
        {-0.38, -0.92, -0.5},
        {0, -1, -0.5},
        {0.38, -0.92, -0.5},
        {0.71, -0.71, -0.5},
        {0.92, -0.38, -0.5},
    };
    for (int i = 0; i < 16; i++) {
        ringVertexArray[i][0] *= 4.5;
        ringVertexArray[i][1] *= 4.5;
        ringVertexArray[i + 16][0] *= 5.5;
        ringVertexArray[i + 16][1] *= 5.5;
        ringVertexArray[i + 32][0] *= 4.5;
        ringVertexArray[i + 32][1] *= 4.5;
        ringVertexArray[i + 48][0] *= 5.5;
        ringVertexArray[i + 48][1] *= 5.5;
    }
    GLfloat ringColorArray[64][3] = {
        {1, 0.5, 0},
        {1., 0.31, 0},
        {1., 0.15, 0},
        {1., 0.04, 0},
        {1., 0., 0},
        {1., 0.04, 0},
        {1., 0.15, 0},
        {1., 0.31, 0},
        {1, 0.5, 0},
        {1, 0.69, 0},
        {1, 0.85, 0},
        {1, 0.96, 0},
        {1, 1, 0},
        {1, 0.96, 0},
        {1, 0.85, 0},
        {1, 0.69, 0},
        //
        {1, 0.5, 0},
        {1., 0.31, 0},
        {1., 0.15, 0},
        {1., 0.04, 0},
        {1., 0., 0},
        {1., 0.04, 0},
        {1., 0.15, 0},
        {1., 0.31, 0},
        {1, 0.5, 0},
        {1, 0.69, 0},
        {1, 0.85, 0},
        {1, 0.96, 0},
        {1, 1, 0},
        {1, 0.96, 0},
        {1, 0.85, 0},
        {1, 0.69, 0},
        //
        {1, 0.6, 0.2},
        {1., 0.41, 0.2},
        {1., 0.25, 0.2},
        {1., 0.14, 0.2},
        {1., 0.1, 0.2},
        {1., 0.14, 0.2},
        {1., 0.25, 0.2},
        {1., 0.41, 0.2},
        {1, 0.6, 0.2},
        {1, 0.79, 0.2},
        {1, 0.95, 0.2},
        {1, 1, 0.2},
        {1, 1, 0.2},
        {1, 1, 0.2},
        {1, 0.95, 0.2},
        {1, 0.79, 0.2},
        //
        {1, 0.6, 0.2},
        {1., 0.41, 0.2},
        {1., 0.25, 0.2},
        {1., 0.14, 0.2},
        {1., 0.1, 0.2},
        {1., 0.14, 0.2},
        {1., 0.25, 0.2},
        {1., 0.41, 0.2},
        {1, 0.6, 0.2},
        {1, 0.79, 0.2},
        {1, 0.95, 0.2},
        {1, 1, 0.2},
        {1, 1, 0.2},
        {1, 1, 0.2},
        {1, 0.95, 0.2},
        {1, 0.79, 0.2}
    };
    GLubyte ringIndexArray[64][4] = {
        {0, 16, 17, 1},
        {1, 17, 18, 2},
        {2, 18, 19, 3},
        {3, 19, 20, 4},
        {4, 20, 21, 5},
        {5, 21, 22, 6},
        {6, 22, 23, 7},
        {7, 23, 24, 8},
        {8, 24, 25, 9},
        {9, 25, 26, 10},
        {10, 26, 27, 11},
        {11, 27, 28, 12},
        {12, 28, 29, 13},
        {13, 29, 30, 14},
        {14, 30, 31, 15},
        {15, 31, 16, 0},

        {33, 49, 48, 32},
        {34, 50, 49, 33},
        {35, 51, 50, 34},
        {36, 52, 51, 35},
        {37, 53, 52, 36},
        {38, 54, 53, 37},
        {39, 55, 54, 38},
        {40, 56, 55, 39},
        {41, 57, 56, 40},
        {42, 58, 57, 41},
        {43, 59, 58, 42},
        {44, 60, 59, 43},
        {45, 61, 60, 44},
        {46, 62, 61, 45},
        {47, 63, 62, 46},
        {32, 48, 63, 47},

        {0, 1, 33, 32},
        {1, 2, 34, 33},
        {2, 3, 35, 34},
        {3, 4, 36, 35},
        {4, 5, 37, 36},
        {5, 6, 38, 37},
        {6, 7, 39, 38},
        {7, 8, 40, 39},
        {8, 9, 41, 40},
        {9, 10, 42, 41},
        {10, 11, 43, 42},
        {11, 12, 44, 43},
        {12, 13, 45, 44},
        {13, 14, 46, 45},
        {14, 15, 47, 46},
        {15, 0, 32, 47},

        {48, 49, 17, 16},
        {49, 50, 18, 17},
        {50, 51, 19, 18},
        {51, 52, 20, 19},
        {52, 53, 21, 20},
        {53, 54, 22, 21},
        {54, 55, 23, 22},
        {55, 56, 24, 23},
        {56, 57, 25, 24},
        {57, 58, 26, 25},
        {58, 59, 27, 26},
        {59, 60, 28, 27},
        {60, 61, 29, 28},
        {61, 62, 30, 29},
        {62, 63, 31, 30},
        {63, 48, 16, 31}
    };

    glVertexPointer(3, GL_FLOAT, 0, ringVertexArray);
    glColorPointer(3, GL_FLOAT, 0, ringColorArray);

    glDrawElements(GL_QUADS, 256, GL_UNSIGNED_BYTE, ringIndexArray);

}
/*
void paintGL3D_Fig1()
{
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.25, 0.87, 0.87);

    GLfloat lambdaVertexArray[28][3] = {
        {-2.5, -3, 0.5},
        {-1.5, -3, 0.5},
        {0, 0, 0.5},
        {1.5, -3, 0.5},
        {2.5, -3, 0.5},
        {3.5, -3, 0.5},
        {3.5, -2, 0.5},
        {2, -2, 0.5},
        {-0.5, 3, 0.5},
        {-1.5, 3, 0.5},
        {-2.5, 3, 0.5},
        {-2.5, 2, 0.5},
        {-1, 2, 0.5},
        {-0.5, 1, 0.5},
        //
        {-2.5, -3, -0.5},
        {-1.5, -3, -0.5},
        {0, 0, -0.5},
        {1.5, -3, -0.5},
        {2.5, -3, -0.5},
        {3.5, -3, -0.5},
        {3.5, -2, -0.5},
        {2, -2, -0.5},
        {-0.5, 3, -0.5},
        {-1.5, 3, -0.5},
        {-2.5, 3, -0.5},
        {-2.5, 2, -0.5},
        {-1, 2, -0.5},
        {-0.5, 1, -0.5}
    };
    GLfloat lambdaColorArray[28][3] = {
        {1, 1, 0},
        {1, 1, 0},
        {1, 0.5, 0},
        {1, 1, 0},
        {1, 1, 0},
        {1, 1, 0},
        {1, 1, 0},
        {1, 0.9, 0},
        {1, 0, 0},
        {1, 0, 0},
        {1, 0.1, 0.1},
        {1, 0.1, 0},
        {1, 0.1, 0},
        {1, 0.6, 0},
        //
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 0.6, 0.1},
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 0.1, 0.1},
        {1, 0.1, 0.1},
        {1, 0.2, 0.2},
        {1, 0.2, 0.1},
        {1, 0.2, 0.1},
        {1, 0.7, 0.1},
    };
    GLubyte lambdaIndexArray[22][4] = {
        {0, 1, 2, 13},
        {4, 5, 6, 7},
        {3, 4, 8, 9},
        {9, 10, 11, 12},

        {27, 16, 15, 14},
        {21, 20, 19, 18},
        {23, 22, 18, 17},
        {26, 25, 24, 23},

        {14, 15, 1, 0},
        {15, 16, 2, 1},
        {16, 17, 3, 2},
        {17, 18, 4, 3},
        {18, 19, 5, 4},
        {19, 20, 6, 5},
        {20, 21, 7, 6},
        {21, 22, 8, 7},
        {22, 23, 9, 8},
        {23, 24, 10, 9},
        {24, 25, 11, 10},
        {25, 26, 12, 11},
        {26, 27, 13, 12},
        {27, 14, 0, 13}
    };

    glVertexPointer(3, GL_FLOAT, 0, lambdaVertexArray);
    glColorPointer(3, GL_FLOAT, 0, lambdaColorArray);

    glDrawElements(GL_QUADS, 88, GL_UNSIGNED_BYTE, lambdaIndexArray);
}
void paintGL3D_Fig2()
{
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.25, 0.87, 0.87);

    GLfloat ringVertexArray[64][3] = {
        {1, 0, 0.5},
        {0.92, 0.38, 0.5},
        {0.71, 0.71, 0.5},
        {0.38, 0.92, 0.5},
        {0, 1, 0.5},
        {-0.38, 0.92, 0.5},
        {-0.71, 0.71, 0.5},
        {-0.92, 0.38, 0.5},
        {-1, 0, 0.5},
        {-0.92, -0.38, 0.5},
        {-0.71, -0.71, 0.5},
        {-0.38, -0.92, 0.5},
        {0, -1, 0.5},
        {0.38, -0.92, 0.5},
        {0.71, -0.71, 0.5},
        {0.92, -0.38, 0.5},
        //
        { 1, 0, 0.5 },
        {0.92, 0.38, 0.5},
        {0.71, 0.71, 0.5},
        {0.38, 0.92, 0.5},
        {0, 1, 0.5},
        {-0.38, 0.92, 0.5},
        {-0.71, 0.71, 0.5},
        {-0.92, 0.38, 0.5},
        {-1, 0, 0.5},
        {-0.92, -0.38, 0.5},
        {-0.71, -0.71, 0.5},
        {-0.38, -0.92, 0.5},
        {0, -1, 0.5},
        {0.38, -0.92, 0.5},
        {0.71, -0.71, 0.5},
        {0.92, -0.38, 0.5},
        //
        { 1, 0, -0.5 },
        {0.92, 0.38, -0.5},
        {0.71, 0.71, -0.5},
        {0.38, 0.92, -0.5},
        {0, 1, -0.5},
        {-0.38, 0.92, -0.5},
        {-0.71, 0.71, -0.5},
        {-0.92, 0.38, -0.5},
        {-1, 0, -0.5},
        {-0.92, -0.38, -0.5},
        {-0.71, -0.71, -0.5},
        {-0.38, -0.92, -0.5},
        {0, -1, -0.5},
        {0.38, -0.92, -0.5},
        {0.71, -0.71, -0.5},
        {0.92, -0.38, -0.5},
        //
        { 1, 0, -0.5 },
        {0.92, 0.38, -0.5},
        {0.71, 0.71, -0.5},
        {0.38, 0.92, -0.5},
        {0, 1, -0.5},
        {-0.38, 0.92, -0.5},
        {-0.71, 0.71, -0.5},
        {-0.92, 0.38, -0.5},
        {-1, 0, -0.5},
        {-0.92, -0.38, -0.5},
        {-0.71, -0.71, -0.5},
        {-0.38, -0.92, -0.5},
        {0, -1, -0.5},
        {0.38, -0.92, -0.5},
        {0.71, -0.71, -0.5},
        {0.92, -0.38, -0.5},
    };
    for (int i = 0; i < 16; i++) {
        ringVertexArray[i][0] *= 4.5;
        ringVertexArray[i][1] *= 4.5;
        ringVertexArray[i+16][0] *= 5.5;
        ringVertexArray[i+16][1] *= 5.5;
        ringVertexArray[i+32][0] *= 4.5;
        ringVertexArray[i+32][1] *= 4.5;
        ringVertexArray[i+48][0] *= 5.5;
        ringVertexArray[i+48][1] *= 5.5;
    }
    GLfloat ringColorArray[64][3] = {
        {1, 0.5, 0},
        {1., 0.31, 0},
        {1., 0.15, 0},
        {1., 0.04, 0},
        {1., 0., 0},
        {1., 0.04, 0},
        {1., 0.15, 0},
        {1., 0.31, 0},
        {1, 0.5, 0},
        {1, 0.69, 0},
        {1, 0.85, 0},
        {1, 0.96, 0},
        {1, 1, 0},
        {1, 0.96, 0},
        {1, 0.85, 0},
        {1, 0.69, 0},
        //
        {1, 0.5, 0},
        {1., 0.31, 0},
        {1., 0.15, 0},
        {1., 0.04, 0},
        {1., 0., 0},
        {1., 0.04, 0},
        {1., 0.15, 0},
        {1., 0.31, 0},
        {1, 0.5, 0},
        {1, 0.69, 0},
        {1, 0.85, 0},
        {1, 0.96, 0},
        {1, 1, 0},
        {1, 0.96, 0},
        {1, 0.85, 0},
        {1, 0.69, 0},
        //
        {1, 0.6, 0.1},
        {1., 0.41, 0.1},
        {1., 0.25, 0.1},
        {1., 0.14, 0.1},
        {1., 0.1, 0.1},
        {1., 0.14, 0.1},
        {1., 0.25, 0.1},
        {1., 0.41, 0.1},
        {1, 0.6, 0.1},
        {1, 0.79, 0.1},
        {1, 0.95, 0.1},
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 0.95, 0.1},
        {1, 0.79, 0.1},
        //
        {1, 0.6, 0.1},
        {1., 0.41, 0.1},
        {1., 0.25, 0.1},
        {1., 0.14, 0.1},
        {1., 0.1, 0.1},
        {1., 0.14, 0.1},
        {1., 0.25, 0.1},
        {1., 0.41, 0.1},
        {1, 0.6, 0.1},
        {1, 0.79, 0.1},
        {1, 0.95, 0.1},
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 1, 0.1},
        {1, 0.95, 0.1},
        {1, 0.79, 0.1}
    };
    GLubyte ringIndexArray[64][4] = {
        {0, 16, 17, 1},
        {1, 17, 18, 2},
        {2, 18, 19, 3},
        {3, 19, 20, 4},
        {4, 20, 21, 5},
        {5, 21, 22, 6},
        {6, 22, 23, 7},
        {7, 23, 24, 8},
        {8, 24, 25, 9},
        {9, 25, 26, 10},
        {10, 26, 27, 11},
        {11, 27, 28, 12},
        {12, 28, 29, 13},
        {13, 29, 30, 14},
        {14, 30, 31, 15},
        {15, 31, 16, 0},

        {33, 49, 48, 32},
        {34, 50, 49, 33},
        {35, 51, 50, 34},
        {36, 52, 51, 35},
        {37, 53, 52, 36},
        {38, 54, 53, 37},
        {39, 55, 54, 38},
        {40, 56, 55, 39},
        {41, 57, 56, 40},
        {42, 58, 57, 41},
        {43, 59, 58, 42},
        {44, 60, 59, 43},
        {45, 61, 60, 44},
        {46, 62, 61, 45},
        {47, 63, 62, 46},
        {32, 48, 63, 47},

        {0, 1, 33, 32},
        {1, 2, 34, 33},
        {2, 3, 35, 34},
        {3, 4, 36, 35},
        {4, 5, 37, 36},
        {5, 6, 38, 37},
        {6, 7, 39, 38},
        {7, 8, 40, 39},
        {8, 9, 41, 40},
        {9, 10, 42, 41},
        {10, 11, 43, 42},
        {11, 12, 44, 43},
        {12, 13, 45, 44},
        {13, 14, 46, 45},
        {14, 15, 47, 46},
        {15, 0, 32, 47},

        {48, 49, 17, 16},
        {49, 50, 18, 17},
        {50, 51, 19, 18},
        {51, 52, 20, 19},
        {52, 53, 21, 20},
        {53, 54, 22, 21},
        {54, 55, 23, 22},
        {55, 56, 24, 23},
        {56, 57, 25, 24},
        {57, 58, 26, 25},
        {58, 59, 27, 26},
        {59, 60, 28, 27},
        {60, 61, 29, 28},
        {61, 62, 30, 29},
        {62, 63, 31, 30},
        {63, 48, 16, 31}
    };

    glVertexPointer(3, GL_FLOAT, 0, ringVertexArray);
    glColorPointer(3, GL_FLOAT, 0, ringColorArray);

    glDrawElements(GL_QUADS, 256, GL_UNSIGNED_BYTE, ringIndexArray);
}
*/
int main()
{
    int sWidth = 400, sHeight = 400;
    sf::RenderWindow window(sf::VideoMode(sWidth, sHeight), "SFML works!",
        sf::Style::Default,
        sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);
    initializeGL();
    resizeGL(sWidth, sHeight);

    int fig = 1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                    initializeGL();
                    resizeGL(sWidth, sHeight);
                    fig = 1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                    initializeGL();
                    resizeGL(sWidth, sHeight);
                    fig = 2;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                    initializeGL();
                    resizeGL(sWidth, sHeight);
                    fig = 3;
                }
                if (fig < 3) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        glTranslatef(0,0.05,0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        glTranslatef(0, -0.05, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        glTranslatef(-0.05, 0, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        glTranslatef(0.05, 0, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                        glScalef(1.01, 1.01, 1.01);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
                        glScalef(0.99, 0.99, 0.99);
                    }
                }
                if (fig == 3) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        glScalef(1.01, 1.01, 1.01);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        glScalef(0.99, 0.99, 0.99);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        glTranslatef(-0.05, 0, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        glTranslatef(0.05, 0, 0);
                    }
                }
            }
            else if (event.type == sf::Event::Resized) {
                glViewport(0, 0, event.size.width, event.size.height);
            }
            if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) {
                    if (event.mouseWheelScroll.delta > 0) {
                        glRotatef(4, 1, 0, 0);
                    }
                    else {
                        glRotatef(-4, 1, 0, 0);
                    }
                }
                else {
                    if (event.mouseWheelScroll.delta > 0) {
                        glRotatef(4, 0, 1, 0);
                    }
                    else {
                        glRotatef(-4, 0, 1, 0);
                    }
                }
            }
        }


        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);
        
        if (fig == 1) {
            paintGL2D_Fig1();
        }
        else if (fig == 2) {
            paintGL2D_Fig2();
        }
        else if (fig == 3) {
            paintGL3D_HL();
        }

        window.display();
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


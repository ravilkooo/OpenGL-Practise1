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
    glClearColor(1,1,1,1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
}
void resizeGL(int sWidth, int sHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // borders
    glOrtho(-2, 8, -2, 8, -3, 3);
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

void paintGLTriangle(Triangle tr) {
    glDisable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.25, 0.87, 0.87);

    glVertexPointer(3, GL_FLOAT, 0, tr.triangleVertexArray);
    glColorPointer(3, GL_FLOAT, 0, tr.triangleColorArray);

    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, tr.triangleIndexArray);
}

void paintGL2D_Fig1()
{
    glDisable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.25, 0.87, 0.87);

    //glLineWidth(4);

    GLfloat lambdaVertexArray[14][3] = {
        {0, 0, 0},
        {1, 0, 0},
        {2.5, 3, 0},
        {4, 0, 0},
        {5, 0, 0},
        {6, 0, 0},
        {6, 1, 0},
        {4.5, 1, 0},
        {2, 6, 0},
        {1, 6, 0},
        {0, 6, 0},
        {0, 5, 0},
        {1.5, 5, 0},
        {2, 4, 0} };
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
        {0, 0, 0},
        {1, 1, 0},
        {3.3, 1, 0},
        {3.3, 0, 0},
        {2, 0, 0},
        {2, 1, 0},
        {5, 1, 0},
        {5, 0, 0},
        {3.7, 0, 0},
        {3.7, 1, 0},
        {6, 1, 0},
        {7, 0, 0}};
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

int main()
{
    int sWidth = 400, sHeight = 400;
    sf::RenderWindow window(sf::VideoMode(sWidth, sHeight), "SFML works!",
        sf::Style::Default,
        sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    initializeGL();
    resizeGL(sWidth, sHeight);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::Resized) {
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);
        
        paintGL2D_Fig2();
        glRotatef(15, 0, 1, 0);
        system("pause");

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

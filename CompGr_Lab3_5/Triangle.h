#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

class Triangle {
public:
    GLfloat triangleVertexArray[3][3];
    GLfloat triangleColorArray[3][3];
    GLubyte triangleIndexArray[1][3];

    Triangle();
};


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>




int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;



    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1200, 1200, "House Outline", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    /*Always call glewInit functions after this line of code*/



    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1, 1, 1, 1);
        

        glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0); // Middle circle
        double radius1 = 0.15;
        double ori_x1 = 0.6;                         // the origin or center of circle
        double ori_y1 = 0.7;
        for (int i = 0; i <= 500; i++) {
            double angle = 2 * 3.412 * i / 400;
            double x1 = cos(angle) * radius1;
            double y1 = sin(angle) * radius1;
            glVertex2d(ori_x1 + x1, ori_y1 + y1);
        }
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1); // Middle circle
        double radius2 = 0.15;
        double ori_x2 = 0.65;                         // the origin or center of circle
        double ori_y2 = 0.7;
        for (int i = 0; i <= 300; i++) {
            double angle = 2 * 3.412 * i / 400;
            double x2 = cos(angle) * radius2;
            double y2 = sin(angle) * radius2;
            glVertex2d(ori_x2 + x2, ori_y2 + y2);
        }
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0); // Middle circle
        double radius3 = 0.4;
        double ori_x3 = -0.07;                         // the origin or center of circle
        double ori_y3 = 0.2;
        for (int i = 0; i <= 300; i++) {
            double angle = 2 * 3.412 * i / 650;
            double x3 = cos(angle) * radius3;
            double y3 = sin(angle) * radius3;
            glVertex2d(ori_x3 + x3, ori_y3 + y3);
        }
        glEnd();

       
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2f(-0.8f, 0.2f);
        glVertex2f(-0.8f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.7f, -0.9f);
        glVertex2f(0.6f, -0.9f);
        glVertex2f(0.6f, -0.0f);
        glVertex2f(0.7f, 0.0f);
        glVertex2f(0.7f, 0.2f);
        glEnd();

        glBegin(GL_POINTS); // render with points
        glVertex2i(50, 40); //display a point
        glEnd();
        glPointSize(10.0);
        
         glLineWidth(3);
        glBegin(GL_LINE_LOOP);
        glClearColor(1, 1, 1, 1);
        glVertex2f(-0.25f, -0.2f);
        glVertex2f(0.1f, -0.2f);
        glVertex2f(0.1f, -0.8f);
        glVertex2f(-0.25f, -0.8f);
        glEnd();
        
        glBegin(GL_POLYGON);
        glColor3f( 0, 0, 1 ); // Middle circle
        double radius = 0.02;
        double ori_x = 0.05;                         // the origin or center of circle
        double ori_y = -0.5;
        for (int i = 0; i <= 300; i++) {
            double angle = 2 * 3.412 * i / 300;
            double x = cos(angle) * radius;
            double y = sin(angle) * radius;
            glVertex2d(ori_x + x, ori_y + y);
        }
        glEnd();




        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    // Initialize GLFW
    if (!glfwInit()) {
        printf("Could not initialize GLFW.\n");
        return -1;
    }

    // Set window hints for OpenGL version and profile
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); // Use compatibility profile

    // Create a GLFW window
    GLFWwindow* window;
    window = glfwCreateWindow(640, 480, "OpenGL TP 1", NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to open GLFW window\n");
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD\n");
        return -1;
    }

    // Change background color
    glClearColor(1.0f, 0.5f, 0.5f, 1.0f);

    // Set the viewport and the framebuffer size callback
    glViewport(0, 0, 640, 480);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the larger triangle
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
        glVertex2f(0, 1);   // Top vertex (centered at the top)
        glVertex2f(-1, 0);  // Bottom left vertex (centered on the left)
        glVertex2f(1, 0);   // Bottom right vertex (centered on the right)
        glEnd();

        // Draw the smaller triangle inside the larger one
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
        glVertex2f(0, 0.5f);     // Top vertex (centered at the top, smaller)
        glVertex2f(-0.5f, 0);    // Bottom left vertex (scaled down)
        glVertex2f(0.5f, 0);     // Bottom right vertex (scaled down)
        glEnd();

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
    return 0;
}


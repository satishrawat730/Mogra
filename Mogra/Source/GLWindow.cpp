#include "GLWindow.h"
#include "ShaderLibrary.h"

namespace Mogra {

  GLWindow::GLWindow()
  {
    /* Initialize the library */
    if (!glfwInit())
    {
      fprintf(stderr, "Error: GLFW Window couldn't be initialized\n");
     // return false;
    }
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGTH, WINDOW_TITLE, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        fprintf(stderr, "Error: GLFW Window couldn't be initialized\n");
    }
     /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // call glewInit after context is created
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
      /* Problem: glewInit failed, something is seriously wrong. */
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }

    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    /* Checking for Extensions

    Starting from GLEW 1.1.0, you can find out if a particular extension is available on your platform by querying globally defined variables of the form
        GLEW_{ extension_name }:
    */
    if (GLEW_ARB_vertex_program)
    {
      /* It is safe to use the ARB_vertex_program extension here. */
      //glGenProgramsARB(...);
    }

    std::cout<< "GL Version : " << glGetString(GL_VERSION);
  }

  GLWindow::~GLWindow(){
     glfwTerminate();
  }

  void GLWindow::Render() {
    GLfloat g_vertex_buffer_data[] = {
                -1.0f, -1.0f, 0.0f,
                1.0f, -1.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
    };

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0 * sizeof(float)));
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //glBindVertexArray(0);

    unsigned int shader = ShaderLibrary::Get()->GetShader("Basic")->GetShaderProgramID();
    glUseProgram(shader);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);
  }

}

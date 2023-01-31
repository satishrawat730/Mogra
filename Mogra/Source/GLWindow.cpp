#include "GLWindow.h"
#include "ShaderLibrary.h"
#include "Primitives.h"

namespace Mogra {

  GLWindow::GLWindow(){
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
  }

  GLWindow::~GLWindow(){
     glfwTerminate();
  }

  bool GLWindow::Init() {

    std::cout << "GL Version : " << glGetString(GL_VERSION);
    
    auto shader = ShaderLibrary::Get()->GetShader("Basic");

    objTriangle = MeshRenderer::Create(Primitives::CreateTriangle(), *shader.get());

    return true;
  }

  void GLWindow::Render() {/*
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        if(objTriangle)
          objTriangle->Render();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);
  }

}

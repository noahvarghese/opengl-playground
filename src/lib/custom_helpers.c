#include "custom_helpers.h"

void process_input(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    else if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void error(const char *message)
{
    fprintf(stderr, "[ ERROR ]: %s\n", message);
    exit(1);
}

const char *str_concat(const char *str1, const char *str2)
{
    size_t size = strlen(str1) + strlen(str2);
    char *new_str = malloc(size);

    if (new_str == NULL)
    {
        fprintf(stderr, "[ ERROR ]: failed to allocate %zu bytes.\n", size);
        exit(1);
    }

    for (int i = 0; i < strlen(str1); i++)
    {
        new_str[i] = str1[i];
    }

    for (int i = 0; i < strlen(str2); i++)
    {
        new_str[strlen(str1) + i] = str2[i];
    }

    new_str[size] = '\0';

    return new_str;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void check_shader_compilation(unsigned int shader)
{
    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        const char *message = str_concat("Shader compilation failed\n", infoLog);
        error(message);
    }
}

unsigned int compile_shader(const char *shaderSource, GLenum shaderType)
{
    unsigned int shader;
    shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);
    check_shader_compilation(shader);
    return shader;
}

GLFWwindow *open_window(void)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "Noah Learns OpenGL", NULL, NULL);

    return window;
}

GLFWwindow *init_window()
{

    if (!glfwInit())
    {
        error("Unable to init glfw");
    }

    GLFWwindow *window = open_window();

    if (window == NULL)
    {
        error("Failed to create GLFW window\nPlease reboot and try again.");
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        error("Failed to initialize GLAD");
    }

    framebuffer_size_callback(window, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}
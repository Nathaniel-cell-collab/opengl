#include "bonus.h"

void init_context(sim_t *sim)
{
    GLFWmonitor *monitor = NULL;
    const GLFWvidmode *mode = NULL;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    monitor = glfwGetPrimaryMonitor();
    mode = glfwGetVideoMode(monitor);
    sim->screen.height = mode->height;
    sim->screen.width = mode->width;
    sim->window = glfwCreateWindow(mode->width, mode->height, "Mon Bonus", monitor, NULL);
    if (sim->window == NULL) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        exit(84);
    }
    glfwMakeContextCurrent(sim->window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        exit(84);
    }
    sim->shaderProgam = createShaderProgram();
}

sim_t *init_sim(sim_t *sim, labyrinth_t *labyrinth)
{
    sim->map = calloc(1, sizeof(map_t));
    if (!(sim->map))
        return NULL;
    sim->map->nb_room = labyrinth->nb_rooms;
    sim->map->nb_robot = labyrinth->nb_rbts;
    create_rooms_map(sim, labyrinth);
    if (!(sim->map->rooms))
        return NULL;
    return sim;
}

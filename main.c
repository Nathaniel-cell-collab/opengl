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
        my_printf("Failed to create GLFW window\n");
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

static float conver_to_NDC(float pos, float div) {
    return (pos / div) * 2.0f - 1.0f;
}

void init_room(sim_t *sim, elements_t *room)
{
    float x = room->x; 
    float y = room->y;
    float w = sim->screen.width;
    float h = sim->screen.height;
    float vertices[] = {
        conver_to_NDC(x, w),     conver_to_NDC(y, h),
        conver_to_NDC(x + 100, w), conver_to_NDC(y, h),
        conver_to_NDC(x + 100, w), conver_to_NDC(y + 100, h),
        conver_to_NDC(x, w),     conver_to_NDC(y + 100, h),
    };

    setupSquare(&(room->VAO), vertices, 32);
}

sim_t *init_sim(sim_t *sim)
{
    float x = 0;
    float y = 0;
    int i = 0;

    sim->map = calloc(1, sizeof(map_t));
    if (!(sim->map))
        return NULL;
    sim->map->nb_room = 25;
    sim->map->rooms = calloc(sim->map->nb_room, sizeof(elements_t *));
    if (!(sim->map->rooms))
        return NULL;
    for (i = 0; i < sim->map->nb_room; i++){
        sim->map->rooms[i] = calloc(1, sizeof(elements_t));
        x = (float)(rand() % 1820);
        y = (float)(rand() % 980);
        printf("x: %f y: %f\n", x, y);
        sim->map->rooms[i]->x = x;
        sim->map->rooms[i]->y = y;
        init_room(sim, sim->map->rooms[i]);
    }
    return sim;
}

int main(void)
{
    sim_t *sim = calloc(1, sizeof(sim_t));
    
    if (!sim)
        return 84;
    init_context(sim);
    sim = init_sim(sim);
    if (!sim)
        return 84;
    main_loop(sim);
    glfwTerminate();
    return 0;
}

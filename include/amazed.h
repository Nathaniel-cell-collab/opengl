/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** Header containing all necessary structs
** and prototypes for amazed.
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct robot_s {
    int id;
    int pos;
    int prev_pos;
    int room_value;
    int tick;
} robots_t;

typedef struct room_s {
    char **links;
    char *name;
    struct room_s *next;
    int x;
    int y;
    int index;
} room_t;

typedef struct labyrinth_s {
    room_t *start_room;
    room_t *end_room;
    room_t *rooms;
    robots_t *robots;
    int nb_rbts;
    int nb_rooms;
} labyrinth_t;

//lib
int is_num(char *line);
int my_getnbr(char const *str);
int is_in_array(char *str, char **array);
char **my_str_to_word_array(char const *str, char separa[]);
char **my_push_tab(char **src, char *to_push);
char **my_listdup(char **src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
int my_array_len(char **array);
int is_in_str(char c, char *str);
void my_free(void *pointer);
void my_free_array(char **array);
int my_strlen(char const *str);
int my_strcmp(char *src, char *cmp);
int count_occur(char *str, char c);
int count_words(char const *str, char *separators);
void my_free_int_array(int **array);
int my_putstr(char *str, int out);
void my_put_nbr(int nb);
//project functions
int add_link(labyrinth_t *labyrinth, char *line);
int add_room(labyrinth_t *labyrinth, char *line,
    int *trigger_start, int *trigger_end);
int fill_struct(labyrinth_t *labyrinth);
int **gener_matrix(labyrinth_t *labyrinth);
int pattern_matching(char *line, labyrinth_t *labyrinth);
void free_labyrinth(labyrinth_t *labyrinth);
void print_rooms(room_t *current);
int find_room_index(labyrinth_t *labyrinth, char *room_name);
char *find_room_name(labyrinth_t *labyrinth, int wanted);
robots_t *init_robots(int index_start, int nb_rbts, int value_start);
int update_robot(int **matrix, int i, robots_t *robot, labyrinth_t *labyrinth);
void modif_matrix(int **matrix, int nb_rooms, int index, int prev);
void init_diag(int **matrix, int nb_rooms);
int check_valid_matrix(int **matrix, labyrinth_t *labyrinth);
char tunel_unused(labyrinth_t *labyrinth, int index, int i);
int change_room(int **matrix, int index, labyrinth_t *labyrinth, int moved);
char is_over(labyrinth_t *labyrinth, int index_end);
#endif

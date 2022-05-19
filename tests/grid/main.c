#include <stdio.h>

#include "main_grid.h"

#define HEIGHT 20
#define WIDTH 100

#define START_X 10
#define START_Y 10

int main() {
    char main_grid[HEIGHT][WIDTH];
    char* main_grid_p = &main_grid[0][0];       // See main_grid.h
    clear_array(main_grid_p, HEIGHT, WIDTH, '.');

    set_coord(main_grid_p, WIDTH, START_X, START_Y, '@');

    show_array(main_grid_p, HEIGHT, WIDTH);

    return 0;
}

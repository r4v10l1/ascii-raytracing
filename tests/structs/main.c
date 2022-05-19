#include <stdio.h>

#include "main_grid.h"

#define HEIGHT 20
#define WIDTH 100

#define START_X 10
#define START_Y 10

int main() {
    char main_grid[HEIGHT][WIDTH];
    array_info grid_info;
    grid_info.arr = &main_grid[0][0];       // See main_grid.h
    grid_info.w = WIDTH;
    grid_info.h = HEIGHT;

    clear_array(grid_info, '.');

    set_coord(grid_info, START_X, START_Y, '@');

    show_array(grid_info);

    return 0;
}

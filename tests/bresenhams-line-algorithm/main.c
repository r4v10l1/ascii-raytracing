#include <stdio.h>

#include "structs.h"
#include "grid.h"
#include "bresenhams_line_algorithm.h"

#define HEIGHT 20
#define WIDTH 100

#define START_X 30
#define START_Y 10

int main() {
    char main_grid[WIDTH][HEIGHT];

    // Set array info (pointer and dimensions)
    array_info grid_info;
    grid_info.arr = &main_grid[0][0];       // See main_grid.h
    grid_info.w = WIDTH;
    grid_info.h = HEIGHT;
    
    // Set start pos point
    arr_point start_pos = {START_X, START_Y};
    arr_point end_pos;

    /* ----------------------------------------------------------- */

    clear_array(grid_info, 176);

    end_pos.x = 40; end_pos.y = 15;
    trace_line(grid_info, start_pos, end_pos, '.');

    end_pos.x = 10; end_pos.y = 1;
    trace_line(grid_info, start_pos, end_pos, '.');

    set_coord(grid_info, start_pos, '@');    // Same as main_grid[x][y] = '@'

    show_array(grid_info);

    return 0;
}

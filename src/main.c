#include <stdio.h>

#include "structs.h"
#include "bresenhams_line_algorithm.h"
#include "grid.h"

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
    grid_info.back_char = ' ';
    grid_info.user_char = '@';
    grid_info.wall_char = 219;
    
    // Set start pos point
    arr_point start_pos = {START_X, START_Y};
    arr_point end_pos;

    /* ----------------------------------------------------------- */

    clear_array(grid_info);

    end_pos.x = 40; end_pos.y = 15;
    trace_line(grid_info, start_pos, end_pos, '.');

    end_pos.x = 10; end_pos.y = 1;
    trace_line(grid_info, start_pos, end_pos, '.');

    end_pos.x = 30; end_pos.y = 1;
    trace_line(grid_info, start_pos, end_pos, '.');

    end_pos.x = 40; end_pos.y = 10;
    trace_line(grid_info, start_pos, end_pos, '.');

    end_pos.x = 20; end_pos.y = 5;
    trace_line(grid_info, start_pos, end_pos, '.');

    set_user(grid_info, start_pos);

    show_array(grid_info);

    return 0;
}

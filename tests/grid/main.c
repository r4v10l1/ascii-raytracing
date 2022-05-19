#include <stdio.h>

#include "main_grid.h"

#define X_SIZE 100
#define Y_SIZE 100
#define START_X 10
#define START_Y 10

int main() {
    char main_grid[X_SIZE][Y_SIZE];
    char* main_grid_p = &main_grid[0][0];       // See main_grid.h

    clear_array(main_grid_p, X_SIZE, Y_SIZE, '\0');
}

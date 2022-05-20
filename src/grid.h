
// https://github.com/r4v10l1/langtons-ant-c/blob/main/src/ant.h#L107-L111
// https://github.com/r4v10l1/langtons-ant-c/blob/main/src/main.c#L112
void clear_array(array_info arr_info) {
    for (int y = 0; y < arr_info.h; y++) {                  // y is the height because is conained in x (width)
        for (int x = 0; x < arr_info.w; x++) {              // x is the width because with x we render every column
            arr_info.arr[x * arr_info.h + y] = arr_info.back_char;   // Current column * items per column + current y item of the current column 
        }
    }
}

/* show_array: shows the array state in the console using putchar() */
void show_array(const array_info arr_info) {
    for (int y = 0; y < arr_info.h; y++) {
        for (int x = 0; x < arr_info.w; x++) {
            putchar(arr_info.arr[x * arr_info.h + y]);
        }
        putchar('\n');
    }
}

/* set_coord: set the value of arr[x][y] to character */
void set_coord(array_info arr_info, arr_point coords, char character) {
    arr_info.arr[coords.x * arr_info.h + coords.y] = character;
}

void set_user(array_info arr_info, arr_point coords) {
    set_coord(arr_info, coords, arr_info.user_char);
}

void create_wall(array_info arr_info, arr_point start, arr_point end) {
    trace_line(arr_info, start, end, arr_info.wall_char);
}

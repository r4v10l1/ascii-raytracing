
typedef struct ArrayInfo {
    char* arr;      // Pointer to arr[0][0]
    int w;    // Width of the array
    int h;    // Height of the array
} array_info;

// https://github.com/r4v10l1/langtons-ant-c/blob/main/src/ant.h#L107-L111
// https://github.com/r4v10l1/langtons-ant-c/blob/main/src/main.c#L112
void clear_array(array_info arr_info, char character) {
    for (int x = 0; x < arr_info.h; x++) {                  // x is the height because with x we render every column
        for (int y = 0; y < arr_info.w; y++) {              // y is the width because is conained in x
            arr_info.arr[x * arr_info.w + y] = character;   // Current column * items per column + current y item of the current column 
        }
    }
}

/* show_array: shows the array state in the console using putchar() */
void show_array(const array_info arr_info) {
    for (int x = 0; x < arr_info.h; x++) {
        for (int y = 0; y < arr_info.w; y++) {
            putchar(arr_info.arr[x * arr_info.w + y]);
        }
        putchar('\n');
    }
}

/* set_coord: set the value of arr[x][y] to character */
void set_coord(array_info arr_info, int x, int y, char character) {
    arr_info.arr[x * arr_info.w + y] = character;
}

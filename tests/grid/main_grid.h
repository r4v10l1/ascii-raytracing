
/*
 * https://github.com/r4v10l1/langtons-ant-c/blob/main/src/ant.h#L107-L111
 * https://github.com/r4v10l1/langtons-ant-c/blob/main/src/main.c#L112
 *
 * We will need to pass the address of the first element of our 2d array:
 *   &arr[0][0]
 */
void clear_array(char* arr, int height, int width, char character) {
    for (int x = 0; x < height; x++) {          // x is the height because with x we render every column
        for (int y = 0; y < width; y++) {       // y is the width because is conained in x
            arr[x * width + y] = character;     // Current column * items per column + current y item of the current column 
        }
    }
}

/* show_array: shows the array state in the console using putchar() */
void show_array(const char* arr, int height, int width) {
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            putchar(arr[x * width + y]);
        }
        putchar('\n');
    }
}

/* set_coord: set the value of arr[x][y] to character */
void set_coord(char* arr, int arr_width, int x, int y, char character) {
    arr[x * arr_width + y] = character;
}

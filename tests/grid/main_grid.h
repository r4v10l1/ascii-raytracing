
/*
 * https://github.com/r4v10l1/langtons-ant-c/blob/main/src/ant.h#L107-L111
 * https://github.com/r4v10l1/langtons-ant-c/blob/main/src/main.c#L112
 *
 * We will need to pass the address of the first element of our 2d array:
 *   &arr[0][0]
 */
void clear_array(char* arr, int xsize, int ysize, char character) {
    for (int x = 0; x < xsize; x++) {
        for (int y = 0; y < ysize; y++) {
            arr[x + y * ysize] = character;
        }
    }
}

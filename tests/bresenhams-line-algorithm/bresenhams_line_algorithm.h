
void trace_line(array_info arr_info, arr_point start, arr_point end, char character) {
    arr_point real_start = start, real_end = end;
    if (start.x > end.x) {     // Get always the left point
        real_start = end;
        real_end = start;
    }

    /* const int x_diff = real_end.x - real_start.x; */
    int slope = 2 * (real_end.y - real_start.y);
    int slope_error = slope - (real_end.x - real_start.x);

    for (int cur_x = real_start.x, cur_y = real_start.y; cur_x <= real_end.x; cur_x++) {
        // https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
        // https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm
        arr_info.arr[cur_x * arr_info.h + cur_y] = character;
        slope_error += slope;

        if (slope_error >= 0) {
            cur_y++;
            slope_error -= 2 * (real_end.x - real_start.x);
        }
    }
}


void trace_line(array_info arr_info, arr_point start, arr_point end, char character) {
    arr_point real_start = start, real_end = end;
    if (start.x > end.x) {     // Get always the left point
        real_start = end;
        real_end = start;
    }

    const int x_diff = real_end.x - real_start.x;

    const int slope = (real_end.y - real_start.y) / (real_end.x - real_start.x);
    for (int cur_x = real_start.x; cur_x <= real_end.x; cur_x++) {          // Loop every column from start to end
        // https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
        // https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm
        int cur_y = slope * (cur_x - real_start.x) + real_start.y;
        arr_info.arr[(real_start.x + cur_x) * arr_info.h + cur_y] = character;
    }
}

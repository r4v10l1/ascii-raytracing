
void trace_line(array_info arr_info, arr_point start, arr_point end, char character) {
    arr_point real_end;
    real_end.x = end.x - start.x;
    real_end.y = end.y - start.y;
    int slope = 2 * (real_end.y - real_end.x);

    int cur_x = start.x;
    int cur_y = start.y;

    // https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
    // https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm
    while (cur_x < end.x) {
        arr_info.arr[cur_x * arr_info.h + cur_y] = character;
        if (slope >= 0) {
            cur_y++;
            slope += 2*real_end.y - 2*real_end.x;
        } else {
            slope += 2*real_end.y;
        }
        cur_x++;
    }
}


void trace_line_alt(array_info arr_info, arr_point start, arr_point end, char character) {
    int x1 = cord1.x, y1 = cord1.y,
        x2 = cord2.x, y2 = cord2.y,
        steep = fabs(y2 - y1) > fabs(x2 - x1),
        inc = -1;

    if (steep) {
        swap(&x1, &y1);
        swap(&x2, &y2);
    }

    if (x1 > x2) {
        swap(&x1, &x2);
        swap(&y1, &y2);
    }

    if (y1 < y2) inc = 1;

    int dx = fabs(x2 - x1),
        dy = fabs(y2 - y1),
        y = y1, x = x1,
        e = 0;

    for (x; x <= x2; x++) {
        if (steep) arr_info.arr[x * arr_info.h + y] = character;
        else arr_info.arr[x * arr_info.h + y] = character;

        if ((e + dy) << 1 < dx) e = e + dy;
        else {
            y += inc;
            e = e + dy - dx;
        }
    }
}



/* trace_line_col: Trace a line with collisions */
void trace_line_col(array_info arr_info, arr_point start, arr_point end, char character) {
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

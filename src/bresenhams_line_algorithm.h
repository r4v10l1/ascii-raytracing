/* trace_line: Trace an ascii line of characters usin bresenham's line algorithm */
void trace_line(array_info arr_info, arr_point start, arr_point end, char character) {
    arr_point real_start = start, real_end = end;
    if (start.x > end.x) {     // Get always the left point as start
        real_start = end;
        real_end = start;
    }

    int x_diff = real_end.x - real_start.x;
    int y_diff = real_end.y - real_start.y;
    
    int direction = 1;          // Start downwards
    if (y_diff < 0) {
        direction = -1;
        y_diff = -y_diff;
    }

    int slope = (2 * y_diff) - x_diff;
    int cur_y = real_start.y;

    for (int cur_x = real_start.x; cur_x < real_end.x; cur_x++) {
        arr_info.arr[cur_x * arr_info.h + cur_y] = character;
        if (slope > 0) {
            cur_y += direction;
            slope += 2 * (y_diff - x_diff);
        } else {
            slope += 2 * y_diff;
        }
    }
}

/* trace_line_downwards: Trace an ascii line of characters usin bresenham's line algorithm. Only downwards */
void trace_line_downwards(array_info arr_info, arr_point start, arr_point end, char character) {
    arr_point real_start = start, real_end = end;
    if (start.x > end.x) {     // Get always the left point as start
        real_start = end;
        real_end = start;
    }

    if (real_start.y < real_end.y) {    // Check if we go downwards (0,0 is top left)
        int slope = 2 * (real_end.y - real_start.y);                // Height difference * 2
        int slope_error = slope - (real_end.x - real_start.x);      // Slope - width difference

        // https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
        // https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm
        for (int cur_x = real_start.x, cur_y = real_start.y; cur_x <= real_end.x; cur_x++) {
            arr_info.arr[cur_x * arr_info.h + cur_y] = character;   // Set the character
            slope_error += slope;                                   // Add initial slope

            if (slope_error >= 0) {                                 // More than one y per x
                cur_y++;                                            // We can move to the next y
                slope_error -= 2 * (real_end.x - real_start.x);
            }
        }
    } else {
        printf("Skipping upwards...\n");
    }
}

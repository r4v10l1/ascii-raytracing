typedef struct ArrayInfo {
    char* arr;          // Pointer to arr[0][0]
    int w;              // Width of the array
    int h;              // Height of the array
    char back_char;     // Character used to represent background
    char user_char;     // Character used to represent the user (light source)
    char wall_char;     // Character used to represent walls that the light can't traverse
} array_info;

typedef struct Point {
    int x;
    int y;
} arr_point;


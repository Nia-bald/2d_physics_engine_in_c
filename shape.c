#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Enum to represent shape types
typedef enum {
    SHAPE_TRIANGLE,
    SHAPE_SQUARE,
    SHAPE_CIRCLE
} ShapeType;

// Structure to hold position
typedef struct {
    float x;
    float y;
} Position;

// Structure that simulates a "Shape class"
typedef struct {
    ShapeType type;
    float dimensions[3]; // triangle: [base, height], square: [side], circle: [radius]
    Position position;
    float rotation;
    bool is_physics_on;
} Shape;

// Function to print shape info
void print_shape(const Shape* s) {
    const char* type_str[] = {"Triangle", "Square", "Circle"};
    printf("enum value is %d\n", s->type);
    printf("Shape: %s\n", type_str[s->type]);
    printf("Position: (%.2f, %.2f)\n", s->position.x, s->position.y);
    printf("Rotation: %.2f degrees\n", s->rotation);
    printf("Physics: %s\n", s->is_physics_on ? "On" : "Off");

    switch (s->type) {
        case SHAPE_TRIANGLE:
            printf("Dimensions (Base x Height): %.2f x %.2f\n", s->dimensions[0], s->dimensions[1]);
            break;
        case SHAPE_SQUARE:
            printf("Dimensions (Side): %.2f\n", s->dimensions[0]);
            break;
        case SHAPE_CIRCLE:
            printf("Dimensions (Radius): %.2f\n", s->dimensions[0]);
            break;
    }
}

int main() {
    // Create and initialize a square shape
    Shape square;
    square.type = SHAPE_SQUARE;
    square.dimensions[0] = 5.0f;  // side length
    square.position.x = 10.0f;
    square.position.y = 20.0f;
    square.rotation = 45.0f;
    square.is_physics_on = true;

    // Print the shape's information
    print_shape(&square);

    return 0;
}

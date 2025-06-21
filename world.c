#include <stdio.h>
#include "shape.c"

typedef struct {
    int shape_count;
    Shape shape_objects[1000];
    float universal_gravitational_constant;
    float universal_gravitational_contant_exp;
} World;

void add_shape_to_world(World* world, const Shape* shape) {
    world->shape_objects[world->shape_count] = *shape;
    world->shape_count += 1;
}

void main() {
    Shape shape1 = {
        .type = SHAPE_SQUARE,
        .dimensions = {5.0f},
        .position = {10.0f, 20.0f},
        .rotation = 45.0f,
        .is_physics_on = true
    };

    Shape shape2 = {
        .type = SHAPE_SQUARE,
        .dimensions = {5.0f},
        .position = {10.0f, 20.0f},
        .rotation = 45.0f,
        .is_physics_on = true
    };

    World world1 = {
        .shape_count = 0,
        .universal_gravitational_constant = 6.6743f,
        .universal_gravitational_contant_exp = -11.0f
    };

    add_shape_to_world(&world1, &shape1);
    add_shape_to_world(&world1, &shape2);

    printf("shape_count is %d\n", world1.shape_count);

}

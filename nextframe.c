#include "world.c"

void update_objects_for_next_frame(World *w, float time_step) {
    // Update the physics of each shape in the world
    int shape_count = w->shape_count;

    float universal_gravitational_constant = w->universal_gravitational_constant;
    float universal_gravitational_constant_exp = w->universal_gravitational_contant_exp;
    
    for (int i = 0; i < shape_count; i++) {
        Shape *s = &w->shape_objects[i];
        if (s->is_physics_on) {
            // Update position based on velocity and acceleration
            s->velocity.x += s->acceleration.x*time_step; // Update x velocity
            s->velocity.y += s->acceleration.y*time_step; // Update y velocity
            
            s->position.x += s->velocity.x*time_step; // Update x position
            s->position.y += s->velocity.y*time_step; // Update y position
            
            // Optionally, apply rotation or other physics effects here
        }
    }
}
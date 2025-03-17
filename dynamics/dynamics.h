#pragma once
#include <stdlib.h>

typedef struct {
  float a; // Particle acceleration
  float v; // Particle velocity
} dyn_particle_t;

float dyn_particle_instant_v(dyn_particle_t *particle);
float dyn_particle_instant_a(dyn_particle_t *particle);

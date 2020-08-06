#include <cmath>
#include <Parfeen/system.h>
#include <Parfeen/constants.h>

void CoulombsLaw(Particle &p1, Particle p2, double tstep) {
    // Get particle coordinates
    double *p1_coords = p1.GetCoords();
    double *p2_coords = p2.GetCoords();

    // Get distance between particles
    double dist = std::sqrt(std::pow(p1_coords[0] - p2_coords[0], 2) + std::pow(p1_coords[1] - p2_coords[1], 2));

    // Get magnitude and components of force and get force vector
    double force = PhyConstants::K * (p1.GetCharge() * p2.GetCharge()) / std::pow(dist, 2);
    double force_x = (force / dist) * (p1_coords[0] - p2_coords[0]);
    double force_y = (force / dist) * (p1_coords[1] - p2_coords[1]);
    double force_vec[2] = {force_x, force_y};

    // Update p1 particle with time diff of tstep
    p1.AddForce(force_vec);
    p1.ApplyForce(tstep);
}

void UpdateSystem(Particle particles[], int len, double timestep) {
    // Create a copy of the particles to work with
    Particle particles_copy[len];

    for (int i = 0; i < len; i++) {
        particles_copy[i] = particles[i];
    }

    // Update each particle in the original
    // Utilize the preserved original state of the system
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            // Skip over self
            if (i == j)
                continue;

            // Update particle with time diff timestep
            CoulombsLaw(particles[i], particles_copy[j], timestep);
        }
    }
}

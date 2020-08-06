#include <iostream>
#include <string>
#include <Parfeen/particle.h>
#include <Parfeen/system.h>

int main() {
    Particle *particles;
    int len;
    int generation = 0;
    double particle_coord[2], particle_charge, particle_mass;

    // Get number of particles
    std::cout << "Number of Particles: ";
    std::cin >> len;

    // Allocate particle data
    particles = new Particle[len];

    // Initialize each particle
    for (int i = 0; i < len; i++) {
        // Get particle data
        std::cout << "Particle " << i << " Coords: ";
        std::cin >> particle_coord[0] >> particle_coord[1];
        std::cout << "Particle " << i << " Charge: ";
        std::cin >> particle_charge;
        std::cout << "Particle " << i << " Mass: ";
        std::cin >> particle_mass;

        // Set particle data
        particles[i].SetCoords(particle_coord);
        particles[i].SetCharge(particle_charge);
        particles[i].SetMass(particle_mass);
    }

    // Simulate system till told to stop
    while (true) {
        // Clear screen
        std::cout << "\033[2J\033[1;1H";

        // Print generation
        std::cout << "Generation: " << generation++ << std::endl;

        // Display data
        for (int i = 0; i < len; i++) {
            std::cout << "Particle " << i << " : (" << particles[i].GetCoords()[0] << ", " << particles[i].GetCoords()[1] << ")" << std::endl;
        }

        // Stop simulation if user inputs q
        if (std::cin.get() == 'q') {
            break;
        }

        // Advance simulation by 1 second
        UpdateSystem(particles, len, 1);
    }

    delete [] particles;

    return 0;
}

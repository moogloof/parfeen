#include <iostream>
#include <limits>
#include <Parfeen/particle.h>
#include <Parfeen/system.h>
#include <utils/display.h>

// Compile array of particles into an array of coords
void CompileCoords(Particle [], int, double **);

int main() {
    Particle *particles;
    int len;
    int generation = 0;
    int screen_width, screen_height, scale;
    char select_option;
    double particle_coord[2], **c_coords, particle_charge, particle_mass;

    // Get display info
    std::cout << "Screen size: ";
    std::cin >> screen_width >> screen_height;
    std::cout << "Graph scale: ";
    std::cin >> scale;

    // Get number of particles
    std::cout << "Number of Particles: ";
    std::cin >> len;

    // Allocate particle data
    particles = new Particle[len];
    c_coords = new double*[len];
    for (int i = 0; i < len; i++)
        c_coords[i] = new double[2];

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

        // Print graph
        CompileCoords(particles, len, c_coords);
        Display(screen_width, screen_height, c_coords, len, scale);

        // Display data
        for (int i = 0; i < len; i++) {
            std::cout << "Particle " << i << " : (" << particles[i].GetCoords()[0] << ", " << particles[i].GetCoords()[1] << ")" << std::endl;
        }

        // Get user input
        select_option = std::cin.get();
        // Stop simulation if user inputs q
        if (select_option == 'q') {
            break;
        } else if (select_option != '\n') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Advance simulation by 1 second
        // Step at smaller intervals for accuracy
        for (int i = 0; i < 100; i++)
            UpdateSystem(particles, len, 0.01);
    }

    // Cleanup
    // Deallocate all dynamic pointers
    delete [] particles;
    for (int i = 0; i < len; i++)
        delete [] c_coords[i];
    delete [] c_coords;

    return 0;
}

void CompileCoords(Particle particles[], int len, double **coords) {
    for (int i = 0; i < len; i++) {
        coords[i][0] = particles[i].GetCoords()[0];
        coords[i][1] = particles[i].GetCoords()[1];
    }
}


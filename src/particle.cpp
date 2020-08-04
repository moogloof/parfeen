// Implementation of Particle.h
#include <Parfeen/particle.h>

/* Particle constructor
 * Set coordinates, charge, and mass of particle
 * Initialize force and velocity of particle */
Particle::Particle(double x, double y, double m, double c) {
    // Set coords
    coords[0] = x;
    coords[1] = y;

    // Initialize velocity
    velocity[0] = 0;
    velocity[1] = 0;

    // Initialize force
    net_force[0] = 0;
    net_force[1] = 0;

    // Set mass
    mass = m;

    // Set charge
    charge = c;
}

/* Set force components */
void Particle::setForce(double force[]) {
    net_force[0] = force[0];
    net_force[1] = force[1];
}

/* Add force components to stored force */
void Particle::addForce(double force[]) {
    net_force[0] += force[0];
    net_force[1] += force[1];
}

/* Return force as an array of components */
double *Particle::getForce() {
    return net_force;
}

/* Set charge of particle */
void Particle::setCharge(double c) {
    charge = c;
}

/* Return charge of particle */
double Particle::getCharge() {
    return charge;
}

/* Apply force components to velocity and update coords */
void Particle::applyForce(double t) {
    // Get acceleration
    double acceleration[2];
    acceleration[0] = net_force[0] / mass;
    acceleration[1] = net_force[1] / mass;

    // Update position of particle
    coords[0] += t * velocity[0];
    coords[1] += t * velocity[1];

    // Update velocity with acceleration
    velocity[0] += t * acceleration[0];
    velocity[1] += t * acceleration[1];
}

void Particle::setMass(double m) {
    mass = m;
}

double Particle::getMass() {
    return mass;
}


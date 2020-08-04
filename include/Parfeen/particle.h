#ifndef PARTICLE_H
#define PARTICLE_H

class Particle {
    private:
        double coords[2];
        double net_force[2];
        double velocity[2];
        double charge;
        double mass;
    public:
        Particle(double, double, double, double);
        void setForce(double []);
        void addForce(double []);
        double *getForce();
        void setCharge(double);
        double getCharge();
        void applyForce(double);
        void setMass(double);
        double getMass();
};

#endif

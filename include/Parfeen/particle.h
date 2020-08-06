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
        Particle();
        void SetForce(double []);
        void AddForce(double []);
        double *GetForce();
        void SetCharge(double);
        double GetCharge();
        void ApplyForce(double);
        void SetMass(double);
        double GetMass();
        void SetCoords(double []);
        double *GetCoords();
};

#endif

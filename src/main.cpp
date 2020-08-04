#include <iostream>
#include <Parfeen/particle.h>

int main() {
    Particle p1(0.0, 0.0, 5.0, 0.001);
    double f[2];

    std::cout << "Force: ";
    std::cin >> f[0] >> f[1];

    p1.setForce(f);

    return 0;
}

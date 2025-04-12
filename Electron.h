#ifndef ELECTRON_H
#define ELECTRON_H

#include "Particle.h"
#include "Photon.h"
#include <vector>
#include <memory>
#include <iostream>

class Electron : public Particle 
{
private:
    double rest_mass;
    std::vector<std::unique_ptr<Photon>> internal_photons;

public:
    Electron(double mass, int num_photons = 1, double photon_energy = 200);

    Photon* radiate();

    void print_data() const override;
};

#endif // ELECTRON_H

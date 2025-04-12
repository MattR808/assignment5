#ifndef PHOTON_H
#define PHOTON_H

#include "Particle.h"
#include <vector>
#include <memory>
#include <iostream>
#include <cmath>

class Electron;

class Photon : public Particle 
{
private:
    double energy;

public:
    Photon(double e);

    double getEnergy() const;

    void print_data() const override;

    // Friend functions for interactions
    friend double photoelectric_effect(const Photon& photon);
    friend double compton_effect(Photon& photon, double theta);
    friend std::vector<std::unique_ptr<Electron>> pair_production(const Photon& photon);
};

#endif // PHOTON_H

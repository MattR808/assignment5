#ifndef RADIOACTIVENUCLEUS_H
#define RADIOACTIVENUCLEUS_H

#include "Nucleus.h"

class RadioactiveNucleus : public Nucleus 
{
private:
    double decayEnergy;

public:
    RadioactiveNucleus(const std::string& n, double energy);
    std::vector<std::unique_ptr<Photon>> decay() override;
    void print_data() const override;
};

#endif // RADIOACTIVENUCLEUS_H

#ifndef STABLENUCLEUS_H
#define STABLENUCLEUS_H

#include "Nucleus.h"

class StableNucleus : public Nucleus 
{
public:
    StableNucleus(const std::string& n);
    std::vector<std::unique_ptr<Photon>> decay() override;
    void print_data() const override;
};

#endif // STABLENUCLEUS_H

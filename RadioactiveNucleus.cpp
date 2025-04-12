#include "RadioactiveNucleus.h"
#include <iostream>

RadioactiveNucleus::RadioactiveNucleus(const std::string& n, double energy)
    : Nucleus(n), decayEnergy(energy) {}

std::vector<std::unique_ptr<Photon>> RadioactiveNucleus::decay() 
{
    std::vector<std::unique_ptr<Photon>> photons;
    decayed = true;

    if(name == "Co") 
    {
        photons.push_back(std::make_unique<Photon>(1173));
        photons.push_back(std::make_unique<Photon>(1333));
    } 
    else if(name == "Na") 
    {
        std::cout<<"Na nucleus undergoes positron emission!"<<std::endl;
        photons.push_back(std::make_unique<Photon>(511));
        photons.push_back(std::make_unique<Photon>(511));
        photons.push_back(std::make_unique<Photon>(1274.5));
    } 
    else 
    {
        photons.push_back(std::make_unique<Photon>(decayEnergy));
    }

    return photons;
}

void RadioactiveNucleus::print_data() const 
{
    std::cout<<"Radioactive nucleus: "<<name<<" with decay energy: "<<decayEnergy<<" keV"<<std::endl;
}

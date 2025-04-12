#include "Electron.h"

Electron::Electron(double mass, int num_photons, double photon_energy)
    : rest_mass(mass) 
    {
    for(int i = 0; i < num_photons; ++i) 
    {
        internal_photons.push_back(std::make_unique<Photon>(photon_energy));
    }
}

Photon* Electron::radiate() 
{
    if(internal_photons.empty()) 
    {
        std::cerr<<"Electron has no more photons to radiate!"<<std::endl;
        return nullptr;
    }

    std::unique_ptr<Photon> p = std::move(internal_photons.back());
    internal_photons.pop_back();

    std::cout<<"Electron radiated a photon with energy: "<<p->getEnergy()<<" keV"<<std::endl;
    return p.release();
}

void Electron::print_data() const 
{
    std::cout<<"Electron with rest mass: "<<rest_mass<<" keV"<<std::endl;
}

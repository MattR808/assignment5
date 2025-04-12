#include "Photon.h"
#include "Electron.h"

Photon::Photon(double e) : energy(e) {}

double Photon::getEnergy() const 
{
    return energy;
}

void Photon::print_data() const 
{
    std::cout<<"Photon with energy: "<<energy<<" keV"<<std::endl;
}

// Friend function definitions
double photoelectric_effect(const Photon& photon) 
{
    return photon.getEnergy();
}

double compton_effect(Photon& photon, double theta) 
{
    double me = 511; // keV
    std::cout<<"Compton scattering angle: "<<theta * 180 / M_PI<<" degrees"<<std::endl;
    double E_prime = photon.getEnergy() / (1 + (photon.getEnergy() / me) * (1 - cos(theta)));
    photon.energy = E_prime;
    return E_prime;
}

std::vector<std::unique_ptr<Electron>> pair_production(const Photon& photon) 
{
    double me = 511; // keV
    std::cerr<<"Photon energy: "<<photon.getEnergy()<<" keV"<<std::endl;

    if(photon.getEnergy() < 2 * me) 
    {
        std::cerr<<"Error: Photon energy too low for pair production!"<<std::endl;
        return {};
    }

    std::cout<<"Pair production successful: Energy "<<photon.getEnergy()<<" keV"<<std::endl;
    std::vector<std::unique_ptr<Electron>> electronPair;
    electronPair.push_back(std::make_unique<Electron>(me));
    electronPair.push_back(std::make_unique<Electron>(me));
    return electronPair;
}

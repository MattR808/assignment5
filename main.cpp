// PHYS30762 Object oriented programming in C++
// Assignment 5 - 11019730 - 11/04/2025
// This program simulates interactions of photons with matter, specifically focusing on:
// - Photon decay from radioactive and stable nuclei.
// - Photon interactions with electrons and nuclei through various effects:
// - Photoelectric effect: The energy of the photon is absorbed by an electron.
// - Compton scattering: The photon undergoes a shift in energy based on scattering angle.
// - Pair production: High-energy photons create electron-positron pairs.
//
// The program:
// - Creates a set of nuclei, both stable and radioactive.
// - Simulates the decay of radioactive nuclei, generating photons.
// - Performs various interactions (photoelectric effect, Compton scattering, pair production)
//   with the generated photons.
// - Displays the resulting photon energies and information about the interactions.


#include "RadioactiveNucleus.h"
#include "StableNucleus.h"
#include "Electron.h"
#include "Photon.h"
#include <vector>
#include <memory>
#include <iostream>
#include <cmath>

int main() 
{
    std::vector<std::unique_ptr<Nucleus>> nuclei;

    nuclei.push_back(std::make_unique<RadioactiveNucleus>("Cs", 661));
    nuclei.push_back(std::make_unique<RadioactiveNucleus>("Na", 1274.5));
    nuclei.push_back(std::make_unique<RadioactiveNucleus>("Co", 0));
    nuclei.push_back(std::make_unique<StableNucleus>("Fe"));

    std::vector<std::unique_ptr<Photon>> all_photons;

    for(auto& nucleus : nuclei) 
    {
        std::cout<<"\n===============\nDecaying nucleus: "<<nucleus->getName()<<std::endl;
        auto photons = nucleus->decay();
        for(auto& photon : photons) 
        {
            photon->print_data();
            all_photons.push_back(std::move(photon));
            std::cout<<"---------------"<<std::endl;
        }
    }

    std::cout<<"\n===============\nInteracting photons with matter:\n";
    for(auto& photon : all_photons) 
    {
        double E = photon->getEnergy();
        std::cout<<"\n===============\nInteracting with photon of energy: "<<E<<" keV\n";

        std::cout<<"- Attempting pair production...\n";
        auto electrons = pair_production(*photon);
        if(!electrons.empty()) 
        {
            std::cout<<"- Pair production successful, radiating from first electron:\n";
            auto new_photon = electrons[0]->radiate();
            if(new_photon) 
            {
                new_photon->print_data();
                delete new_photon;
            }
        }
        std::cout<<"---------------"<<std::endl;

        std::cout<<"- Photoelectric effect energy: "<<photoelectric_effect(*photon)<<" keV\n";
        std::cout<<"---------------"<<std::endl;

        double theta = M_PI / 4;
        std::cout<<"- Compton before: "<<photon->getEnergy()<<" keV\n";
        double E_compton = compton_effect(*photon, theta);
        std::cout<<"- Compton after: "<<E_compton<<" keV\n";
        std::cout<<"==============="<<std::endl;
    }

    return 0;
}

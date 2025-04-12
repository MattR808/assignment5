#include "StableNucleus.h"
#include <iostream>

StableNucleus::StableNucleus(const std::string& n) : Nucleus(n) {}

std::vector<std::unique_ptr<Photon>> StableNucleus::decay() 
{
    std::cerr<<"Error: Stable nucleus cannot decay!"<<std::endl;
    return {};
}

void StableNucleus::print_data() const 
{
    std::cout<<"Stable nucleus: "<<name<<std::endl;
}

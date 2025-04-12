#include "Nucleus.h"

Nucleus::Nucleus(const std::string& n) : name(n), decayed(false) {}

bool Nucleus::has_decayed() const 
{
    return decayed;
}

std::string Nucleus::getName() const 
{
    return name;
}

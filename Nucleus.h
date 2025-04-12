#ifndef NUCLEUS_H
#define NUCLEUS_H

#include "Photon.h"
#include <string>
#include <vector>
#include <memory>

class Nucleus 
{
protected:
    std::string name;
    bool decayed;

public:
    Nucleus(const std::string& n);
    virtual ~Nucleus() = default;

    virtual std::vector<std::unique_ptr<Photon>> decay() = 0;

    bool has_decayed() const;
    std::string getName() const;

    virtual void print_data() const = 0;
};

#endif // NUCLEUS_H

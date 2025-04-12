#ifndef PARTICLE_H
#define PARTICLE_H

class Particle
{
public:
    virtual ~Particle() = default;
    virtual void print_data() const = 0;
};

#endif // PARTICLE_H

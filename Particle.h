// Particle.h
// Declare particle class
#ifndef PARTICLE_H
#define PARTICLE_H

#include "FourMomentum.h"
#include <string>

// delcare particle class. in private, string name, four momentum
// add helper function to check name is a valid sm particle

// public class: parametrised constructor as before
// getter
// print

class Particle
{
private:
    std::string name;
    FourMomentum fourMomentum;

    // Also need to check that the name is a valid SM model
    // Does this by passing the reference 
    static bool isValidName(const std::string& name);

public:
    //parametrised constructor as in FourMomentum.h
    Particle(const std::string& name, double E, double Px, double Py, double Pz);

    // apply rule of 5 to destruct, copy, move ===========
    // Destructor: when object dies clean up memory
    ~Particle();

    // Copy constructor: create deep copy of the pointer, stored in diff memory
    Particle(const Particle& other); 

    // Copy Assignment Operator: clean old memory and copy new memory via assignment
    Particle& operator=(const Particle& other);
    
    // Move Constructor: Steal the pointer instead of copying
    Particle(Particle && other);

    // Move Assignment Operator: Delete old and steal new, consider like cleanup
    Particle& operator=(Particle && other);
    // End of applyig rule of 5 ==============================

    // Getters
    std::string getName() const;
    const FourMomentum& getFourMomentum() const;

    // Print
    void print() const;
};
#endif

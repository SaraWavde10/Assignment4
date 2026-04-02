// FourMomentum.cpp
// Implement FourMomentum class
#include "FourMomentum.h"
#include <iostream>
#include <stdexcept>

//Pending:
// Getters
// Setters
// Operator+ add the two four-momenta by each component
// Dot product: E1*E2 - px1*px2 - py1*py2 - pz1*pz2


// Parameterised constructor
FourMomentum::FourMomentum(double E, double Px, double Py, double Pz)
{
    std::cout << "Calling FourMomentum parameterised constructor..." << std::endl;
    if (E<0) {
        std::cout << "Warning: Energy cannot be negative! Setting to 0" << std::endl;
        E = 0;
    }
    components = new std::vector<double>{E, Px, Py, Pz};
}

// Destructor
FourMomentum::~FourMomentum()
{
    std::cout << "Now Calling FourMomentum destructor..." << std::endl;
    delete components;
    components = nullptr;
}

// Copy constructor: perform deep copy instead of shallow for safety
FourMomentum::FourMomentum(const FourMomentum& other)
{
    std::cout << "Calling FourMomentum copy constructor" << std::endl;
    components = new std::vector<double>(*other.components); // makes a new vector
}

// Copy assignment and call it for user to see
FourMomentum& FourMomentum::operator=(const FourMomentum& other)
{
    std::cout << "Calling FourMomentum copy assignment" << std::endl;
    if (this == &other) return *this;          // ensuring a copy isn't made
    delete components;                           // free the pre-existing memory
    components = new std::vector<double>(*other.components); // perform deep coppy
    return *this; // allow cases like a = b = c
}

// Move constructor: steal the pointer
FourMomentum::FourMomentum(FourMomentum&& other)
{
    std::cout << "Calling FourMomentum move constructor" << std::endl;
    components = other.components;   // steal
    other.components = nullptr;      // leave old object empty
}

// Move assignment
FourMomentum& FourMomentum::operator=(FourMomentum&& other)
{
    std::cout << "Calling FourMomentum move assignment" << std::endl;
    if (this == &other) return *this;
    delete components;
    components = other.components;
    other.components = nullptr;
    return *this;
}

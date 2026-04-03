// FourMomentum.cpp
// Implement FourMomentum class
#include "FourMomentum.h"
#include <iostream>
#include <stdexcept>
// Four-momentum stored as (E, px, py, pz)

// Parameterised constructor
FourMomentum::FourMomentum(double E, double Px, double Py, double Pz)
{
    std::cout << "Calling FourMomentum parameterised constructor..." << std::endl;
    if (E<0) {
        std::cout << "Warning: Energy cannot be negative! Setting to 0" << std::endl;
        E = 0;
    }
    components = new std::vector<double>;
    components->push_back(E);
    components->push_back(Px);
    components->push_back(Py);
    components->push_back(Pz);
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
    if (other.components)
        components = new std::vector<double>(*other.components);
    else
        components = nullptr; // makes a new vector
}

// Copy assignment and call it for user to see
FourMomentum& FourMomentum::operator=(const FourMomentum& other)
{
    std::cout << "Calling FourMomentum copy assignment" << std::endl;
    if (this == &other) return *this;          // ensuring a copy isn't made
    delete components;                           // free the pre-existing memory
    components = new std::vector<double>(*other.components); // perform deep copy
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


// Getters implemented
double FourMomentum::getE()  const { return (*components)[0]; }
double FourMomentum::getPx() const { return (*components)[1]; }
double FourMomentum::getPy() const { return (*components)[2]; }
double FourMomentum::getPz() const { return (*components)[3]; }

// Setters
void FourMomentum::setE(double E)
{
    if (E < 0) {
        std::cout << "Warning: Energy cannot be negative, setting to 0" << std::endl;
        E = 0;
    }
    (*components)[0] = E;
}
void FourMomentum::setPx(double px) { (*components)[1] = px; }
void FourMomentum::setPy(double py) { (*components)[2] = py; }
void FourMomentum::setPz(double pz) { (*components)[3] = pz; }

// Operator+ : adds two four-momenta component by component
FourMomentum FourMomentum::operator+(const FourMomentum& other) const
{
    return FourMomentum(
        getE()  + other.getE(),
        getPx() + other.getPx(),
        getPy() + other.getPy(),
        getPz() + other.getPz()
    );
}

// Dot product: E1*E2 - px1*px2 - py1*py2 - pz1*pz2
double FourMomentum::dotProduct(const FourMomentum& other) const
{
    return getE()  * other.getE()
         - getPx() * other.getPx()
         - getPy() * other.getPy()
         - getPz() * other.getPz();
}
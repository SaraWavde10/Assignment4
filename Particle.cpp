// Particle.cxx
// Implementation of the Particle class
#include "Particle.h"
#include <iostream>
#include <stdexcept>

// Valid particle names using or statements
bool Particle::isValidName(const std::string& n)
{
    return (n == "electron"     ||
            n == "muon"         ||
            n == "tau"          ||
            n == "antielectron" ||
            n == "antimuon"     ||
            n == "antitau");
}

// Parametrised constructor
Particle::Particle(const std::string& n, double E, double Px, double Py, double Pz)
    : name(n), fourMomentum(E, Px, Py, Pz)
{
    std::cout << "Calling Particle parameterised constructor" << std::endl;
    if (!isValidName(n)) {
        std::cout << "Warning: invalid particle name: " << n << ", setting to electron" << std::endl;
        name = "electron";
    }
}
// Destructor
Particle::~Particle()
{
    std::cout << "Calling Particle destructor for " << name << std::endl;
}

// Copy constructor: perform deep copy instead of shallow for safety
Particle::Particle(const Particle& other)
    : name(other.name), fourMomentum(other.fourMomentum)
{
    std::cout << "Calling Particle copy constructor" << std::endl;
}

// Copy assignment and call it for user to see
Particle& Particle::operator=(const Particle& other)
{
    std::cout << "Calling Particle copy assignment" << std::endl;
    if (this == &other) return *this;
    name         = other.name;
    fourMomentum = other.fourMomentum;  // calls FourMomentum copy assignment
    return *this;
}

// Move constructor
Particle::Particle(Particle&& other)
    : name(std::move(other.name)), fourMomentum(std::move(other.fourMomentum))
{
    std::cout << "Calling Particle move constructor" << std::endl;
}

// Move assignment
Particle& Particle::operator=(Particle&& other)
{
    std::cout << "Calling Particle move assignment" << std::endl;
    if (this == &other) return *this;
    name         = std::move(other.name);
    fourMomentum = std::move(other.fourMomentum);
    return *this;
}

// Getters implemented
std::string Particle::getName() const { return name; }
const FourMomentum& Particle::getFourMomentum() const { return fourMomentum; }

// Print
void Particle::print() const
{
    std::cout << "Particle: " << name
              << " | E=" << fourMomentum.getE()
              << " px=" << fourMomentum.getPx()
              << " py=" << fourMomentum.getPy()
              << " pz=" << fourMomentum.getPz()
              << std::endl;
}
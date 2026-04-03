// main.cpp 
#include "Particle.h"
#include "FourMomentum.h"
#include <iostream>
#include <vector>

// main guarded
int main()
{
    std::cout << "\n--- Creating particles ---\n";

    // Test vector: 2 electrons, 4 muons, 2 taus, 1 antielectron, 1 antimuon
    std::vector<Particle> particles = {
        Particle("electron",      0.511, 0.0, 0.0, 0.1),   // [0]
        Particle("electron",      0.511, 0.1, 0.0, 0.0),   // [1]
        Particle("muon",        105.67, 0.0, 0.2, 0.0),    // [2]
        Particle("muon",        105.67, 0.1, 0.1, 0.0),    // [3]
        Particle("muon",        105.67, 0.0, 0.0, 0.3),    // [4]
        Particle("muon",        105.67, 0.2, 0.0, 0.1),    // [5]
        Particle("tau",        1776.86, 0.0, 0.5, 0.0),    // [6]
        Particle("tau",        1776.86, 0.3, 0.0, 0.4),    // [7]
        Particle("antielectron", 0.511, 0.0, 0.0, 0.1),    // [8]
        Particle("antimuon",   105.67, 0.1, 0.0, 0.0),     // [9]
    };

    // Summation of the 4-momenta of the two electrons
    std::cout << "\n--- Summing two electrons ---\n";
    FourMomentum eSum = particles[0].getFourMomentum() + particles[1].getFourMomentum();

    std::cout << "Sum: E=" << eSum.getE()
              << " px=" << eSum.getPx()
              << " py=" << eSum.getPy()
              << " pz=" << eSum.getPz() << std::endl;

    // Dot product of first two muons
    std::cout << "\n--- Dot product of first two muons ---\n";
    double dp = particles[2].getFourMomentum().dotProduct(particles[3].getFourMomentum());
    std::cout << "Dot product = " << dp << std::endl;

    // Copy assignment: electron to new electron 
    std::cout << "\n--- Copy assignment ---\n";
    Particle assignedElectron = particles[0];   // calls copy constructor here actually
    assignedElectron = particles[1];            // this calls copy assignment

    // Copy constructor: first muon to new muon 
    std::cout << "\n--- Copy constructor ---\n";
    Particle copiedMuon(particles[2]);

    // Move constructor: antielectron 
    std::cout << "\n--- Move constructor ---\n";
    Particle movedAntielectron(std::move(particles[8]));

    // Move assignment: antimuon
    std::cout << "\n--- Move assignment ---\n";
    Particle movedAntimuon("antimuon", 105.66, 0.0, 0.0, 0.0);
    movedAntimuon = std::move(particles[9]);

    std::cout << "\n--- End of main, will now use destructors ---\n";
    return 0;
}
// FourMomentum.h 
// Declare class here using parametrised constructor
// Then apply rule of 5 
// Getters
// Setters
// Operators

// Used https://www.geeksforgeeks.org/cpp/rule-of-five-in-cpp/ 

// required classes: name and four momentum
#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include <vector>

class FourMomentum{
private:
     //components is a vector not rly defined in this line, but as a pointer
    // uses dynamic memory so requires rule of 5
     std::vector<double>* components;

public:
    // store the 4 momentum components
    FourMomentum(double E, double Px, double Py, double Pz);

    // apply rule of 5 to destruct, copy, move ===========
    // Destructor: when object dies clean up memory
    ~FourMomentum();

    // Copy constructor: create deep copy of the pointer, stored in diff memory
    FourMomentum(const FourMomentum& other); 

    // Copy Assignment Operator: clean old memory and copy new memory via assignment
    FourMomentum& operator=(const FourMomentum& other);
    
    // Move Constructor: Steal the pointer instead of copying
    FourMomentum(FourMomentum && other);

    // Move Assignment Operator: Delete old and steal new, consider like cleanup
    FourMomentum& operator=(FourMomentum && other);
    // End of applyig rule of 5 ==============================

    // Getters =========
    double getE()const;
    double getPx()const;
    double getPy()const;
    double getPz()const;

    // Setters =========
    void setE(double E);
    void setPx(double Px);
    void setPy(double Py);
    void setPz(double Pz);

    // Operators
    FourMomentum operator+(const FourMomentum& other) const;
    double dotProduct(const FourMomentum& other) const;

    

};

#endif
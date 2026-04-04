# Assignment 4 - Particle Physics 4 Vector Demo

## How to Compile and Run
```
g++ -Wall -std=c++17 -o assignment4 main.cpp Particle.cpp FourMomentum.cpp
```
```
./assignment4
```
## How to Use the Classes

### FourMomentum Class
Stores the four-momentum of a particle as (E, px, py, pz) in MeV using natural units (c=1). Uses getters to access components. 
From here, the four momenta are added together and dot produced to obtain the result.

### Particle Class
Stores a named particle with a FourMomentum. Valid names are:
electron, muon, tau, antielectron, antimuon, antitau.

The user can view the particle information by
    electron.print();

If an invalid name is given, a warning is printed and the name defaults to "electron".
If a negative energy is given, a warning is printed and energy is set to 0.

## Physics Background

In special relativity, a particle's energy and momentum are combined into a 
single four-vector called the four-momentum:

   $$ P = (E, px, py, pz) $$

All values are in MeV (megaelectronvolts). The dot product of the two four-momenta is a Lorentz invariant, which is the same result in all frames of references. 
It is defined as

    $$ P1 · P2 = E_{1}E_{2} - p_{x1}p_{x2} - p_{y1}p_{y2} - p_{z1}p_{z2}$$

This is useful to understand particle collisions. 

## Code Design

The code is split into two classes:

### FourMomentum
- Stores components as a pointer to a dynamically allocated vector, holding four momenta info
- The user accesses components only through getters/setters, not the vector directly
- The Rule of 5 is implemented because the class manages heap memory via new/delete:
    - Destructor: deletes the vector to prevent memory leaks
    - Copy constructor: allocates a new vector and copies values (deep copy)
    - Copy assignment: checks for self-assignment, frees old memory, deep copies
    - Move constructor: steals the pointer from a temporary object
    - Move assignment: checks self-assignment, frees old memory, steals pointer

### Particle
- Stores a name and a FourMomentum object
- Name is validated against a list of Standard Model particles
- The Rule of 5 is implemented to correctly handle the FourMomentum quantities

### main.cpp
- Creates a test vector of particles: 2 electrons, 4 muons, 2 taus, 
  1 antielectron, 1 antimuon
- Demonstrates: four-momentum sum, dot product, copy assignment,
  copy constructor, move constructor, move assignment
- All constructor/destructor calls are printed to show the Rule of 5 in action
 
## Workflow Record
- 30 March: recapped concepts and syntax with mix of YouTube videos and AI. Wrote pseudo code version
- 2 April: During the day I prepared my skeleton code and write the .h files. At night I started the first CPP files. In between I drafted my README.md locally
- 3 April: Write the rest of the CPP files. Struggled here more so watched videos etc. 
- 4 April: updated README.md


## Disclosure of Delegation to Generative AI

The authors declare the use of generative AI in the research and writing process. According to the GAIDeT taxonomy (2025), the following tasks were delegated to GAI tools under full human supervision:

- Research design
- Reformatting

The GAI tool used was: Claude (Anthropic).
Responsibility for the final manuscript lies entirely with the authors.
GAI tools are not listed as authors and do not bear responsibility for the final outcomes.
Declaration submitted by: Sara Wavde

Additional note: I used Claude AI prior to writing the code to understand the role of smart pointers, rule of 5 etc other terminology that was unfamiliar to me. I then wrote my psuedocode version of the programme, and had it verify my logic. The code was written mostly by myself, except for some output lines which I had Claude AI reformat to present in a more elegant manner. 
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

// Classe Dog - eredita da Animal
// Ora ha un cervello (Brain) allocato dinamicamente
class Dog : public Animal {
private:
    Brain* brain; // Puntatore al cervello - allocato dinamicamente

public:
    // Costruttore di default
    Dog();
    
    // Costruttore di copia - deve gestire il deep copy del cervello
    Dog(const Dog& other);
    
    // Operatore di assegnazione - deve gestire il deep copy del cervello
    Dog& operator=(const Dog& other);
    
    // Distruttore - deve deallocare il cervello
    ~Dog();
    
    // Override del metodo makeSound
    void makeSound() const;
    
    // Metodo per accedere al cervello
    Brain* getBrain() const;
};

#endif


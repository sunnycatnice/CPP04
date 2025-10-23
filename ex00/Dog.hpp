#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

// Classe Dog - eredita da Animal
class Dog : public Animal {
public:
    // Costruttore di default
    Dog();
    
    // Costruttore di copia
    Dog(const Dog& other);
    
    // Operatore di assegnazione
    Dog& operator=(const Dog& other);
    
    // Distruttore
    ~Dog();
    
    // Override del metodo makeSound - produce il suono di un cane
    void makeSound() const;
};

#endif


#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

// Classe Dog - eredita da AAnimal (classe astratta)
// DEVE implementare makeSound() perché è puramente virtuale in AAnimal
class Dog : public AAnimal {
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
    
    // IMPLEMENTAZIONE OBBLIGATORIA del metodo puramente virtuale
    void makeSound() const;
    
    // Metodo per accedere al cervello
    Brain* getBrain() const;
};

#endif


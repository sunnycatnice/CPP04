#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

// Classe Cat - eredita da Animal
// Ora ha un cervello (Brain) allocato dinamicamente
class Cat : public Animal {
private:
    Brain* brain; // Puntatore al cervello - allocato dinamicamente

public:
    // Costruttore di default
    Cat();
    
    // Costruttore di copia - deve gestire il deep copy del cervello
    Cat(const Cat& other);
    
    // Operatore di assegnazione - deve gestire il deep copy del cervello
    Cat& operator=(const Cat& other);
    
    // Distruttore - deve deallocare il cervello
    ~Cat();
    
    // Override del metodo makeSound
    void makeSound() const;
    
    // Metodo per accedere al cervello
    Brain* getBrain() const;
};

#endif


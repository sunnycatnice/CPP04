#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

// Classe Cat - eredita da Animal
class Cat : public Animal {
public:
    // Costruttore di default
    Cat();
    
    // Costruttore di copia
    Cat(const Cat& other);
    
    // Operatore di assegnazione
    Cat& operator=(const Cat& other);
    
    // Distruttore
    ~Cat();
    
    // Override del metodo makeSound - produce il suono di un gatto
    void makeSound() const;
};

#endif


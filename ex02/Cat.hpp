#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

// Classe Cat - eredita da AAnimal (classe astratta)
// DEVE implementare makeSound() perché è puramente virtuale in AAnimal
class Cat : public AAnimal {
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
    
    // IMPLEMENTAZIONE OBBLIGATORIA del metodo puramente virtuale
    void makeSound() const;
    
    // Metodo per accedere al cervello
    Brain* getBrain() const;
};

#endif


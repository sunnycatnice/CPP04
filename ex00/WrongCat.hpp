#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

// Classe WrongCat - eredita da WrongAnimal
// Dimostra cosa succede quando il metodo della classe base NON è virtuale
class WrongCat : public WrongAnimal {
public:
    // Costruttore di default
    WrongCat();
    
    // Costruttore di copia
    WrongCat(const WrongCat& other);
    
    // Operatore di assegnazione
    WrongCat& operator=(const WrongCat& other);
    
    // Distruttore
    ~WrongCat();
    
    // Questo metodo NON fa override perché il metodo base non è virtuale
    void makeSound() const;
};

#endif


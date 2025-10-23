#include "WrongCat.hpp"

// Costruttore di default - imposta il tipo a "WrongCat"
WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

// Costruttore di copia - crea una copia del gatto
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

// Operatore di assegnazione - assegna i valori da un altro gatto
WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

// Distruttore - pulisce le risorse
WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

// Metodo makeSound - ma NON fa override perché il metodo base non è virtuale
// Quando chiamato tramite un puntatore WrongAnimal*, verrà chiamato il metodo di WrongAnimal!
void WrongCat::makeSound() const {
    std::cout << "Wrong Meow! Wrong Meow!" << std::endl;
}


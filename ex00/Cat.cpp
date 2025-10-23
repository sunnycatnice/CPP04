#include "Cat.hpp"

// Costruttore di default - imposta il tipo a "Cat"
Cat::Cat() {
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

// Costruttore di copia - crea una copia del gatto
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

// Operatore di assegnazione - assegna i valori da un altro gatto
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

// Distruttore - pulisce le risorse
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

// Override del metodo makeSound - il gatto miagola
void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}


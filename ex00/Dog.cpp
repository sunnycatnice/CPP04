#include "Dog.hpp"

// Costruttore di default - imposta il tipo a "Dog"
Dog::Dog() {
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

// Costruttore di copia - crea una copia del cane
Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
}

// Operatore di assegnazione - assegna i valori da un altro cane
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

// Distruttore - pulisce le risorse
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

// Override del metodo makeSound - il cane abbaia
void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}


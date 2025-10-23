#include "AAnimal.hpp"

// Costruttore di default - inizializza il tipo a "AAnimal"
AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal constructor called" << std::endl;
}

// Costruttore di copia - crea una copia dell'animale
AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "AAnimal copy constructor called" << std::endl;
}

// Operatore di assegnazione - assegna i valori da un altro animale
AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "AAnimal assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// Distruttore - pulisce le risorse
AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

// Restituisce il tipo dell'animale
std::string AAnimal::getType() const {
    return this->type;
}


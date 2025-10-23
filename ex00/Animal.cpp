#include "Animal.hpp"

// Costruttore di default - inizializza il tipo a "Animal"
Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

// Costruttore di copia - crea una copia dell'animale
Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

// Operatore di assegnazione - assegna i valori da un altro animale
Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// Distruttore - pulisce le risorse
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

// Metodo che produce un suono generico
void Animal::makeSound() const {
    std::cout << "Some generic animal sound!" << std::endl;
}

// Restituisce il tipo dell'animale
std::string Animal::getType() const {
    return this->type;
}


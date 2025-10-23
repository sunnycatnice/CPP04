#include "WrongAnimal.hpp"

// Costruttore di default - inizializza il tipo a "WrongAnimal"
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

// Costruttore di copia - crea una copia dell'animale
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

// Operatore di assegnazione - assegna i valori da un altro animale
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// Distruttore - pulisce le risorse
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

// Metodo che produce un suono generico - NON è virtuale
void WrongAnimal::makeSound() const {
    std::cout << "Some generic wrong animal sound!" << std::endl;
}

// Restituisce il tipo dell'animale
std::string WrongAnimal::getType() const {
    return this->type;
}


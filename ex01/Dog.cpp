#include "Dog.hpp"

// Costruttore di default - crea un nuovo cervello
Dog::Dog() : brain(new Brain()) {
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

// Costruttore di copia - crea una COPIA PROFONDA (deep copy)
// È fondamentale allocare un NUOVO cervello e copiare i contenuti
// altrimenti due cani condividerebbero lo stesso cervello!
Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
}

// Operatore di assegnazione - gestisce il deep copy
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        // Dealloca il vecchio cervello
        delete this->brain;
        // Crea un nuovo cervello copiando quello dell'altro cane
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

// Distruttore - DEVE deallocare il cervello per evitare memory leak
Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

// Override del metodo makeSound
void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

// Restituisce il puntatore al cervello
Brain* Dog::getBrain() const {
    return this->brain;
}


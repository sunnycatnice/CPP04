#include "Cat.hpp"

// Costruttore di default - crea un nuovo cervello
Cat::Cat() : brain(new Brain()) {
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

// Costruttore di copia - crea una COPIA PROFONDA (deep copy)
// È fondamentale allocare un NUOVO cervello e copiare i contenuti
// altrimenti due gatti condividerebbero lo stesso cervello!
Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copy constructor called" << std::endl;
}

// Operatore di assegnazione - gestisce il deep copy
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        // Dealloca il vecchio cervello
        delete this->brain;
        // Crea un nuovo cervello copiando quello dell'altro gatto
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

// Distruttore - DEVE deallocare il cervello per evitare memory leak
Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

// Override del metodo makeSound
void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

// Restituisce il puntatore al cervello
Brain* Cat::getBrain() const {
    return this->brain;
}


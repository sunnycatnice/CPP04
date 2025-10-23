#include "Brain.hpp"

// Costruttore di default - inizializza il cervello
Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
    // Le idee sono inizializzate automaticamente a stringhe vuote
}

// Costruttore di copia - crea una COPIA PROFONDA (deep copy) del cervello
// Questo è essenziale per evitare che due animali condividano lo stesso cervello
Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    // Copia ogni singola idea dall'altro cervello
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
}

// Operatore di assegnazione - assegna una COPIA PROFONDA (deep copy)
Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {
        // Copia ogni singola idea dall'altro cervello
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

// Distruttore - pulisce le risorse
Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

// Imposta un'idea a un dato indice
void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        this->ideas[index] = idea;
    }
}

// Ottiene un'idea da un dato indice
std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return this->ideas[index];
    }
    return "";
}


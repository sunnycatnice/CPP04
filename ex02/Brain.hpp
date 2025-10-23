#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

// Classe Brain - rappresenta il cervello di un animale
// Contiene 100 idee (ideas)
class Brain {
private:
    std::string ideas[100]; // Array di 100 stringhe che rappresentano le idee

public:
    // Costruttore di default
    Brain();
    
    // Costruttore di copia - importante per il deep copy
    Brain(const Brain& other);
    
    // Operatore di assegnazione - importante per il deep copy
    Brain& operator=(const Brain& other);
    
    // Distruttore
    ~Brain();
    
    // Metodi per gestire le idee
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

// Classe base Animal - rappresenta un animale generico
class Animal {
protected:
    std::string type; // Tipo dell'animale (protetto per essere accessibile dalle classi derivate)

public:
    // Costruttore di default
    Animal();
    
    // Costruttore di copia
    Animal(const Animal& other);
    
    // Operatore di assegnazione
    Animal& operator=(const Animal& other);
    
    // Distruttore virtuale - importante per il polimorfismo
    virtual ~Animal();
    
    // Metodo virtuale - permette l'override nelle classi derivate
    virtual void makeSound() const;
    
    // Getter per il tipo
    std::string getType() const;
};

#endif


#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

// Classe astratta AAnimal - rappresenta un animale generico
// È ASTRATTA perché ha un metodo puramente virtuale (makeSound = 0)
// NON può essere istanziata direttamente!
class AAnimal {
protected:
    std::string type; // Tipo dell'animale (protetto per essere accessibile dalle classi derivate)

public:
    // Costruttore di default
    AAnimal();
    
    // Costruttore di copia
    AAnimal(const AAnimal& other);
    
    // Operatore di assegnazione
    AAnimal& operator=(const AAnimal& other);
    
    // Distruttore virtuale - importante per il polimorfismo
    virtual ~AAnimal();
    
    // Metodo PURAMENTE VIRTUALE - rende la classe astratta
    // Le classi derivate DEVONO implementarlo
    virtual void makeSound() const = 0;
    
    // Getter per il tipo
    std::string getType() const;
};

#endif


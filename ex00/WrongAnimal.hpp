#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

// Classe WrongAnimal - dimostra cosa succede SENZA il polimorfismo corretto
// Nota: makeSound() NON è virtuale, quindi non c'è polimorfismo
class WrongAnimal {
protected:
    std::string type; // Tipo dell'animale

public:
    // Costruttore di default
    WrongAnimal();
    
    // Costruttore di copia
    WrongAnimal(const WrongAnimal& other);
    
    // Operatore di assegnazione
    WrongAnimal& operator=(const WrongAnimal& other);
    
    // Distruttore NON virtuale
    ~WrongAnimal();
    
    // Metodo NON virtuale - questo causa problemi con il polimorfismo
    void makeSound() const;
    
    // Getter per il tipo
    std::string getType() const;
};

#endif


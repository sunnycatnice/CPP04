#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Testing correct polymorphism ===" << std::endl;
    
    // Creazione di un animale generico, un cane e un gatto
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    // Stampa i tipi
    std::cout << "\nTypes:" << std::endl;
    std::cout << "meta type: " << meta->getType() << std::endl;
    std::cout << "dog type: " << dog->getType() << std::endl;
    std::cout << "cat type: " << cat->getType() << std::endl;
    
    // Test del polimorfismo - ogni animale fa il suo verso
    std::cout << "\nSounds:" << std::endl;
    std::cout << "meta sound: ";
    meta->makeSound(); // Suono generico
    std::cout << "dog sound: ";
    dog->makeSound();  // Woof! (grazie al polimorfismo)
    std::cout << "cat sound: ";
    cat->makeSound();  // Meow! (grazie al polimorfismo)
    
    // Pulizia della memoria
    std::cout << "\nDeleting animals:" << std::endl;
    delete meta;
    delete dog;
    delete cat;
    
    std::cout << "\n=== Testing WRONG polymorphism ===" << std::endl;
    
    // Creazione di WrongAnimal e WrongCat
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    // Stampa i tipi
    std::cout << "\nTypes:" << std::endl;
    std::cout << "wrongMeta type: " << wrongMeta->getType() << std::endl;
    std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
    
    // Test del polimorfismo SBAGLIATO
    // WrongCat farà il verso di WrongAnimal, non il suo!
    std::cout << "\nSounds:" << std::endl;
    std::cout << "wrongMeta sound: ";
    wrongMeta->makeSound(); // Suono generico
    std::cout << "wrongCat sound: ";
    wrongCat->makeSound();  // Suono generico (SBAGLIATO! perché makeSound non è virtuale)
    
    // Pulizia della memoria
    std::cout << "\nDeleting wrong animals:" << std::endl;
    delete wrongMeta;
    delete wrongCat;
    
    return 0;
}


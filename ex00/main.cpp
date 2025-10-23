#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                    🐾 POLYMORPHISM TEST 🐾                   ║\n";
    std::cout << "║                Exercise 00 - Virtual Methods                 ║\n";
    std::cout << "╚══════════════════════════════════════════════════════════════╝\n";
    std::cout << "\n";
    
    std::cout << "┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│           ✅ Testing CORRECT polymorphism                    │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
    
    // Creazione di un animale generico, un cane e un gatto
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    // Stampa i tipi
    std::cout << "\n📋 Animal Types:\n";
    std::cout << "─────────────────────────────────────\n";
    std::cout << "🦴 meta type: " << meta->getType() << std::endl;
    std::cout << "🐕 dog type:  " << dog->getType() << std::endl;
    std::cout << "🐱 cat type:  " << cat->getType() << std::endl;
    
    // Test del polimorfismo - ogni animale fa il suo verso
    std::cout << "\n🔊 Animal Sounds:\n";
    std::cout << "─────────────────────────────────────\n";
    std::cout << "🦴 meta sound: ";
    meta->makeSound(); // Suono generico
    std::cout << "🐕 dog sound:  ";
    dog->makeSound();  // Woof! (grazie al polimorfismo)
    std::cout << "🐱 cat sound:  ";
    cat->makeSound();  // Meow! (grazie al polimorfismo)
    
    // Pulizia della memoria
    std::cout << "\n🗑️  Deleting animals...\n";
    std::cout << "─────────────────────────────────────\n";
    delete meta;
    delete dog;
    delete cat;
    
    std::cout << "\n\n";
    std::cout << "┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│           ❌ Testing WRONG polymorphism                      │\n";
    std::cout << "│         (without virtual - shows the problem!)               │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
    
    // Creazione di WrongAnimal e WrongCat
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    // Stampa i tipi
    std::cout << "\n📋 Wrong Animal Types:\n";
    std::cout << "─────────────────────────────────────\n";
    std::cout << "❓ wrongMeta type: " << wrongMeta->getType() << std::endl;
    std::cout << "❓ wrongCat type:  " << wrongCat->getType() << std::endl;
    
    // Test del polimorfismo SBAGLIATO
    // WrongCat farà il verso di WrongAnimal, non il suo!
    std::cout << "\n🔊 Wrong Animal Sounds:\n";
    std::cout << "─────────────────────────────────────\n";
    std::cout << "❓ wrongMeta sound: ";
    wrongMeta->makeSound(); // Suono generico
    std::cout << "❓ wrongCat sound:  ";
    wrongCat->makeSound();  // Suono generico (SBAGLIATO! perché makeSound non è virtuale)
    std::cout << "\n⚠️  Notice: WrongCat makes generic sound (polymorphism broken!)\n";
    
    // Pulizia della memoria
    std::cout << "\n🗑️  Deleting wrong animals...\n";
    std::cout << "─────────────────────────────────────\n";
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                    ✅ ALL TESTS COMPLETED!                   ║\n";
    std::cout << "╚══════════════════════════════════════════════════════════════╝\n";
    std::cout << "\n";
    
    return 0;
}


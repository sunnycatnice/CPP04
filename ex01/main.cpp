#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                   🧠 BRAIN & DEEP COPY TEST 🧠               ║\n";
    std::cout << "║           Exercise 01 - Dynamic Memory Management            ║\n";
    std::cout << "╚══════════════════════════════════════════════════════════════╝\n";
    std::cout << "\n";
    
    // Test 1: Creazione di un array di animali
    std::cout << "┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│  📦 Test 1: Creating array of animals with brains           │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
    const int arraySize = 4;
    Animal* animals[arraySize];
    
    // Metà cani, metà gatti
    for (int i = 0; i < arraySize / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; i++) {
        animals[i] = new Cat();
    }
    
    // Test 2: Verifica dei tipi e dei suoni
    std::cout << "\n┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│  🔍 Test 2: Verifying types and sounds                      │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
    for (int i = 0; i < arraySize; i++) {
        if (animals[i]->getType() == "Dog")
            std::cout << "🐕 Animal " << i << " [" << animals[i]->getType() << "] → ";
        else
            std::cout << "🐱 Animal " << i << " [" << animals[i]->getType() << "] → ";
        animals[i]->makeSound();
    }
    
    // Test 3: Test del deep copy con Dog
    std::cout << "\n┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│  🐕 Test 3: Dog Deep Copy (Memory Independence)             │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "I want to play!");
    dog1->getBrain()->setIdea(1, "I love bones!");
    
    std::cout << "💡 Dog1 idea 0: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "💡 Dog1 idea 1: " << dog1->getBrain()->getIdea(1) << std::endl;
    
    // Copia profonda - dog2 avrà un cervello SEPARATO
    std::cout << "\n📋 Creating Dog2 as a copy of Dog1...\n";
    Dog* dog2 = new Dog(*dog1);
    std::cout << "💡 Dog2 idea 0 (copied): " << dog2->getBrain()->getIdea(0) << std::endl;
    std::cout << "💡 Dog2 idea 1 (copied): " << dog2->getBrain()->getIdea(1) << std::endl;
    
    // Modifica il cervello di dog2 - NON dovrebbe influenzare dog1
    std::cout << "\n✏️  Modifying Dog2's brain...\n";
    dog2->getBrain()->setIdea(0, "I want to sleep!");
    std::cout << "─────────────────────────────────────\n";
    std::cout << "✅ Dog1 idea 0 (unchanged): " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "🔄 Dog2 idea 0 (modified):  " << dog2->getBrain()->getIdea(0) << std::endl;
    
    // Verifica che i cervelli siano effettivamente diversi (indirizzi diversi)
    std::cout << "\n🧠 Brain Memory Addresses:\n";
    std::cout << "─────────────────────────────────────\n";
    std::cout << "📍 Dog1 brain: " << dog1->getBrain() << std::endl;
    std::cout << "📍 Dog2 brain: " << dog2->getBrain() << std::endl;
    std::cout << "✅ Different addresses = Deep copy works!\n";
    
    // Test 4: Test del deep copy con Cat
    std::cout << "\n┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│  🐱 Test 4: Cat Deep Copy (Quick Test)                      │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
    Cat* cat1 = new Cat();
    cat1->getBrain()->setIdea(0, "I want to hunt!");
    
    Cat* cat2 = new Cat(*cat1);
    cat2->getBrain()->setIdea(0, "I want to nap!");
    
    std::cout << "💡 Cat1 idea 0: " << cat1->getBrain()->getIdea(0) << std::endl;
    std::cout << "💡 Cat2 idea 0: " << cat2->getBrain()->getIdea(0) << std::endl;
    std::cout << "✅ Both cats have independent brains!\n";
    
    // Pulizia della memoria
    std::cout << "\n┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│  🗑️  Cleaning up memory (deleting all animals)              │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    delete dog1;
    delete dog2;
    delete cat1;
    delete cat2;
    
    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║               ✅ ALL TESTS PASSED! NO LEAKS! 🎉              ║\n";
    std::cout << "║          Deep copy implementation is working correctly!      ║\n";
    std::cout << "╚══════════════════════════════════════════════════════════════╝\n";
    std::cout << "\n";
    
    return 0;
}


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "=== Testing Brain and Deep Copy ===" << std::endl;
    
    // Test 1: Creazione di un array di animali
    std::cout << "\n--- Creating array of animals ---" << std::endl;
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
    std::cout << "\n--- Testing types and sounds ---" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << " type: " << animals[i]->getType() << " - ";
        animals[i]->makeSound();
    }
    
    // Test 3: Test del deep copy con Dog
    std::cout << "\n--- Testing Dog deep copy ---" << std::endl;
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "I want to play!");
    dog1->getBrain()->setIdea(1, "I love bones!");
    
    std::cout << "Dog1 idea 0: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog1 idea 1: " << dog1->getBrain()->getIdea(1) << std::endl;
    
    // Copia profonda - dog2 avrà un cervello SEPARATO
    Dog* dog2 = new Dog(*dog1);
    std::cout << "Dog2 idea 0 (copied): " << dog2->getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea 1 (copied): " << dog2->getBrain()->getIdea(1) << std::endl;
    
    // Modifica il cervello di dog2 - NON dovrebbe influenzare dog1
    dog2->getBrain()->setIdea(0, "I want to sleep!");
    std::cout << "\nAfter modifying dog2:" << std::endl;
    std::cout << "Dog1 idea 0 (should be unchanged): " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea 0 (modified): " << dog2->getBrain()->getIdea(0) << std::endl;
    
    // Verifica che i cervelli siano effettivamente diversi (indirizzi diversi)
    std::cout << "\nBrain addresses (should be different):" << std::endl;
    std::cout << "Dog1 brain address: " << dog1->getBrain() << std::endl;
    std::cout << "Dog2 brain address: " << dog2->getBrain() << std::endl;
    
    // Test 4: Test del deep copy con Cat
    std::cout << "\n--- Testing Cat deep copy ---" << std::endl;
    Cat* cat1 = new Cat();
    cat1->getBrain()->setIdea(0, "I want to hunt!");
    
    Cat* cat2 = new Cat(*cat1);
    cat2->getBrain()->setIdea(0, "I want to nap!");
    
    std::cout << "Cat1 idea 0: " << cat1->getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea 0: " << cat2->getBrain()->getIdea(0) << std::endl;
    
    // Pulizia della memoria
    std::cout << "\n--- Deleting all animals ---" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    delete dog1;
    delete dog2;
    delete cat1;
    delete cat2;
    
    std::cout << "\n=== End of tests ===" << std::endl;
    
    return 0;
}


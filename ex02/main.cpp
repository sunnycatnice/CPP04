#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "=== Testing Abstract Class ===" << std::endl;
    
    // La seguente riga NON compilerebbe perché AAnimal è una classe astratta!
    // AAnimal* test = new AAnimal(); // ERRORE: cannot instantiate abstract class
    
    // Test 1: Creazione di un array di animali (tramite puntatori alla classe astratta)
    std::cout << "\n--- Creating array of animals ---" << std::endl;
    const int arraySize = 6;
    AAnimal* animals[arraySize];
    
    // Metà cani, metà gatti - possiamo usare puntatori AAnimal* perché Dog e Cat ereditano da AAnimal
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
    dog1->getBrain()->setIdea(0, "I want to chase cats!");
    dog1->getBrain()->setIdea(1, "Where's my ball?");
    
    std::cout << "Dog1 idea 0: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog1 idea 1: " << dog1->getBrain()->getIdea(1) << std::endl;
    
    // Copia profonda - dog2 avrà un cervello SEPARATO
    Dog* dog2 = new Dog(*dog1);
    std::cout << "Dog2 idea 0 (copied): " << dog2->getBrain()->getIdea(0) << std::endl;
    
    // Modifica il cervello di dog2 - NON dovrebbe influenzare dog1
    dog2->getBrain()->setIdea(0, "I'm tired of chasing!");
    std::cout << "\nAfter modifying dog2:" << std::endl;
    std::cout << "Dog1 idea 0 (unchanged): " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea 0 (modified): " << dog2->getBrain()->getIdea(0) << std::endl;
    
    // Test 4: Test del deep copy con Cat
    std::cout << "\n--- Testing Cat deep copy ---" << std::endl;
    Cat* cat1 = new Cat();
    cat1->getBrain()->setIdea(0, "I need to find some mice!");
    
    Cat* cat2 = new Cat(*cat1);
    cat2->getBrain()->setIdea(0, "Time for a nap!");
    
    std::cout << "Cat1 idea 0: " << cat1->getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea 0: " << cat2->getBrain()->getIdea(0) << std::endl;
    
    // Test 5: Test dell'operatore di assegnazione
    std::cout << "\n--- Testing assignment operator ---" << std::endl;
    Dog* dog3 = new Dog();
    dog3->getBrain()->setIdea(0, "Original idea");
    
    Dog* dog4 = new Dog();
    dog4->getBrain()->setIdea(0, "Will be replaced");
    
    std::cout << "Before assignment - Dog4 idea 0: " << dog4->getBrain()->getIdea(0) << std::endl;
    *dog4 = *dog3; // Operatore di assegnazione
    std::cout << "After assignment - Dog4 idea 0: " << dog4->getBrain()->getIdea(0) << std::endl;
    
    // Modifica dog3 per verificare che dog4 abbia una copia indipendente
    dog3->getBrain()->setIdea(0, "Modified original");
    std::cout << "After modifying dog3:" << std::endl;
    std::cout << "Dog3 idea 0: " << dog3->getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog4 idea 0 (should be unchanged): " << dog4->getBrain()->getIdea(0) << std::endl;
    
    // Pulizia della memoria
    std::cout << "\n--- Deleting all animals ---" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    delete dog1;
    delete dog2;
    delete dog3;
    delete dog4;
    delete cat1;
    delete cat2;
    
    std::cout << "\n=== End of tests ===" << std::endl;
    
    return 0;
}


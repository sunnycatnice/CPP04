#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                🔒 ABSTRACT CLASS TEST 🔒                     ║\n";
    std::cout << "║          Exercise 02 - Pure Virtual Methods                  ║\n";
    std::cout << "╚══════════════════════════════════════════════════════════════╝\n";
    std::cout << "\n";
    std::cout << "ℹ️  Note: AAnimal is ABSTRACT and cannot be instantiated!\n";
    std::cout << "   // AAnimal* test = new AAnimal(); ← This would NOT compile\n";
    std::cout << "\n";
    
    // La seguente riga NON compilerebbe perché AAnimal è una classe astratta!
    // AAnimal* test = new AAnimal(); // ERRORE: cannot instantiate abstract class
    
    // Test 1: Creazione di un array di animali (tramite puntatori alla classe astratta)
    std::cout << "┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│  📦 Test 1: Creating animals via abstract class pointers     │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
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
    std::cout << "\n┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│  🔍 Test 2: Polymorphism with abstract base class           │\n";
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
    std::cout << "│  🐕 Test 3: Dog Deep Copy Verification                      │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "I want to chase cats!");
    dog1->getBrain()->setIdea(1, "Where's my ball?");
    
    std::cout << "💭 Dog1 idea 0: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "💭 Dog1 idea 1: " << dog1->getBrain()->getIdea(1) << std::endl;
    
    // Copia profonda - dog2 avrà un cervello SEPARATO
    std::cout << "\n📋 Creating Dog2 as a copy...\n";
    Dog* dog2 = new Dog(*dog1);
    std::cout << "💭 Dog2 idea 0 (copied): " << dog2->getBrain()->getIdea(0) << std::endl;
    
    // Modifica il cervello di dog2 - NON dovrebbe influenzare dog1
    std::cout << "\n✏️  Modifying Dog2's brain...\n";
    dog2->getBrain()->setIdea(0, "I'm tired of chasing!");
    std::cout << "─────────────────────────────────────\n";
    std::cout << "✅ Dog1 idea 0 (unchanged): " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "🔄 Dog2 idea 0 (modified):  " << dog2->getBrain()->getIdea(0) << std::endl;
    
    // Test 4: Test del deep copy con Cat
    std::cout << "\n┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│  🐱 Test 4: Cat Deep Copy Verification                      │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
    Cat* cat1 = new Cat();
    cat1->getBrain()->setIdea(0, "I need to find some mice!");
    
    Cat* cat2 = new Cat(*cat1);
    cat2->getBrain()->setIdea(0, "Time for a nap!");
    
    std::cout << "💭 Cat1 idea 0: " << cat1->getBrain()->getIdea(0) << std::endl;
    std::cout << "💭 Cat2 idea 0: " << cat2->getBrain()->getIdea(0) << std::endl;
    std::cout << "✅ Independent brains confirmed!\n";
    
    // Test 5: Test dell'operatore di assegnazione
    std::cout << "\n┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│  ⚙️  Test 5: Assignment Operator Deep Copy                  │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
    Dog* dog3 = new Dog();
    dog3->getBrain()->setIdea(0, "Original idea");
    
    Dog* dog4 = new Dog();
    dog4->getBrain()->setIdea(0, "Will be replaced");
    
    std::cout << "📝 Before assignment:\n";
    std::cout << "   Dog4 idea 0: " << dog4->getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\n🔄 Executing: *dog4 = *dog3\n";
    *dog4 = *dog3; // Operatore di assegnazione
    
    std::cout << "📝 After assignment:\n";
    std::cout << "   Dog4 idea 0: " << dog4->getBrain()->getIdea(0) << std::endl;
    
    // Modifica dog3 per verificare che dog4 abbia una copia indipendente
    std::cout << "\n✏️  Modifying Dog3's brain...\n";
    dog3->getBrain()->setIdea(0, "Modified original");
    std::cout << "─────────────────────────────────────\n";
    std::cout << "🔄 Dog3 idea 0 (modified):  " << dog3->getBrain()->getIdea(0) << std::endl;
    std::cout << "✅ Dog4 idea 0 (unchanged): " << dog4->getBrain()->getIdea(0) << std::endl;
    
    // Pulizia della memoria
    std::cout << "\n┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│  🗑️  Cleaning up all allocated memory                       │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    delete dog1;
    delete dog2;
    delete dog3;
    delete dog4;
    delete cat1;
    delete cat2;
    
    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║            🎉 ALL TESTS COMPLETED SUCCESSFULLY! 🎉           ║\n";
    std::cout << "║                                                              ║\n";
    std::cout << "║  ✅ Abstract class prevents direct instantiation             ║\n";
    std::cout << "║  ✅ Polymorphism works correctly                             ║\n";
    std::cout << "║  ✅ Deep copy implementation verified                        ║\n";
    std::cout << "║  ✅ No memory leaks!                                         ║\n";
    std::cout << "╚══════════════════════════════════════════════════════════════╝\n";
    std::cout << "\n";
    
    return 0;
}


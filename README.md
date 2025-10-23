# CPP04 - Polymorphism, Abstract Classes, and Interfaces

Questo progetto contiene tre esercizi che dimostrano concetti fondamentali della programmazione orientata agli oggetti in C++.

## Struttura del Progetto

### 📁 ex00 - Polymorphism (Polimorfismo)

Questo esercizio dimostra il **polimorfismo** in C++.

**Concetti chiave:**

- **Classi virtuali**: La classe `Animal` ha metodi virtuali che permettono il polimorfismo
- **Override dei metodi**: `Dog` e `Cat` fanno override del metodo `makeSound()`
- **Distruttore virtuale**: Necessario per la corretta deallocazione della memoria

**Classi implementate:**

- `Animal` - Classe base con metodi virtuali
- `Dog` - Eredita da Animal, fa "Woof!"
- `Cat` - Eredita da Animal, fa "Meow!"
- `WrongAnimal` - Dimostra cosa succede SENZA metodi virtuali
- `WrongCat` - Non può fare correttamente l'override perché WrongAnimal non usa virtual

**Cosa impari:**
Il polimorfismo permette di chiamare il metodo corretto sulla classe derivata anche usando un puntatore alla classe base. Senza `virtual`, viene sempre chiamato il metodo della classe base.

**Compilazione ed esecuzione:**

```bash
cd ex00
make
./polymorphism
make clean  # pulisce i file .o
```

---

### 📁 ex01 - Brain (Deep Copy)

Questo esercizio aggiunge la classe `Brain` e dimostra l'importanza del **deep copy**.

**Concetti chiave:**

- **Allocazione dinamica**: Brain è allocato con `new` nello heap
- **Deep copy**: Il costruttore di copia e l'operatore di assegnazione devono copiare anche il Brain
- **Memory management**: È essenziale deallocare il Brain nel distruttore per evitare memory leak

**Classi implementate:**

- `Brain` - Contiene 100 idee (stringhe)
- `Animal` - Classe base
- `Dog` - Ha un Brain allocato dinamicamente
- `Cat` - Ha un Brain allocato dinamicamente

**Cosa impari:**
Quando una classe contiene puntatori a memoria allocata dinamicamente, è fondamentale implementare:

1. **Costruttore di copia** - crea una nuova copia del Brain
2. **Operatore di assegnazione** - copia il contenuto del Brain
3. **Distruttore** - dealloca il Brain

Senza deep copy, due oggetti condividerebbero lo stesso Brain, causando problemi quando uno viene distrutto.

**Compilazione ed esecuzione:**

```bash
cd ex01
make
./brain
make clean  # pulisce i file .o
```

---

### 📁 ex02 - Abstract Class (Classe Astratta)

Questo esercizio trasforma Animal in una **classe astratta**.

**Concetti chiave:**

- **Metodo puramente virtuale**: `virtual void makeSound() const = 0;`
- **Classe astratta**: Una classe con almeno un metodo puramente virtuale NON può essere istanziata
- **Obbligo di implementazione**: Le classi derivate DEVONO implementare tutti i metodi puramente virtuali

**Classi implementate:**

- `AAnimal` - Classe astratta (ha makeSound puramente virtuale)
- `Dog` - Deve implementare makeSound() per essere istanziabile
- `Cat` - Deve implementare makeSound() per essere istanziabile
- `Brain` - Come in ex01

**Cosa impari:**
Le classi astratte sono usate come interfacce o classi base che non hanno senso istanziare da sole. Garantiscono che tutte le classi derivate implementino certi metodi, rendendo il codice più robusto e type-safe.

**Compilazione ed esecuzione:**

```bash
cd ex02
make
./abstract
make clean  # pulisce i file .o
```

---

## Differenze tra gli esercizi

| Aspetto                  | ex00             | ex01             | ex02             |
| ------------------------ | ---------------- | ---------------- | ---------------- |
| Polimorfismo             | ✅ Con `virtual` | ✅ Con `virtual` | ✅ Con `virtual` |
| Brain (memoria dinamica) | ❌               | ✅               | ✅               |
| Deep copy                | ❌               | ✅               | ✅               |
| Classe astratta          | ❌               | ❌               | ✅               |
| Può istanziare Animal    | ✅               | ✅               | ❌               |

---

## Comandi Makefile

Tutti gli esercizi supportano i seguenti comandi:

```bash
make          # Compila il progetto
make clean    # Rimuove i file oggetto (.o)
make fclean   # Rimuove i file oggetto e l'eseguibile
make re       # Ricompila tutto da zero (fclean + all)
```

---

## Note Importanti

### Memory Management

- Ogni `new` deve avere un corrispondente `delete`
- Il distruttore della classe base deve essere `virtual`
- Il deep copy è essenziale quando si usano puntatori

### Virtual vs Non-Virtual

- **Virtual**: Permette l'override e il polimorfismo dinamico
- **Non-virtual**: Il metodo chiamato dipende dal tipo del puntatore, non dall'oggetto

### Classi Astratte

- Non possono essere istanziate direttamente
- Servono come interfacce o classi base
- Obbligano le classi derivate a implementare certi metodi

---

## Compilazione

Tutti i progetti sono compilati con:

- Compilatore: `c++`
- Standard: `C++98`
- Flag: `-Wall -Wextra -Werror`

---

## Autore

Progetto realizzato per il corso CPP04 della 42 School.

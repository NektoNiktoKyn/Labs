#ifndef ANIMAL_H
#define ANIMAL_H

typedef struct {
    int id;
    char type[50];
    char name[50];
    int age;
    int enclosure;
} Animal;

void printAnimals(Animal* animals, int count);
int findAnimalById(Animal* animals, int count, int id);
int findAnimalByName(Animal* animals, int count, const char* name);
void saveToFile(Animal* animals, int count, const char* filename);
int loadFromFile(Animal** animals, const char* filename);
void addAnimal(Animal** animals, int* count, Animal newAnimal);
void removeAnimal(Animal** animals, int* count, int id);
void editAnimal(Animal* animals, int count, int id, Animal updated);

#endif

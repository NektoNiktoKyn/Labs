#include <string.h>

#include "animal.h"

// Ищем животное по ID - возвращаем её позицию в списке
int findAnimalById(Animal* animals, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (animals[i].id == id) {
            return i;  // Нашли!
        }
    }
    return -1;  // Ничего не нашли
}

// Ищем по имени (регистр имеет значение!)
int findAnimalByName(Animal* animals, int count, const char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(animals[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

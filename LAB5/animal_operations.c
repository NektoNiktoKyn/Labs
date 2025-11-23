#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"

// Красиво выводим всех животных
void printAnimals(Animal* animals, int count) {
    if (count == 0) {
        printf("В зоопарке нет животных\n");
        return;
    }

    printf("\n  Список обитателей зоопарка (всего :%d животных):\n", count);
    printf("┌─────┬────────────┬────────────┬────────┬─────────┐\n");
    printf("│ ID  │    Вид     │   Кличка   │ Возраст│ Вольер  │\n");
    printf("├─────┼────────────┼────────────┼────────┼─────────┤\n");

    for (int i = 0; i < count; i++) {
        printf("│ %-3d │ %-10s │ %-10s │ %-6d │ %-7d │\n",
               animals[i].id, animals[i].type, animals[i].name,
               animals[i].age, animals[i].enclosure);
    }
    printf("└─────┴────────────┴────────────┴────────┴─────────┘\n");
}

// Добавляем нового животного в наш зоопарк
void addAnimal(Animal** animals, int* count, Animal newAnimal) {
    *animals = realloc(*animals, (*count + 1) * sizeof(Animal));
    if (*animals == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    (*animals)[*count] = newAnimal;
    (*count)++;
    printf("Добавлен новое животное: %s по кличке '%s' (ID: %d)\n",
           newAnimal.type, newAnimal.name, newAnimal.id);
}

// Удаляем животное из базы данных зоопарка
void removeAnimal(Animal** animals, int* count, int id) {
    int index = findAnimalById(*animals, *count, id);
    if (index == -1) {
        printf("Животное с ID %d не найдено!\n", id);
        return;
    }

    printf("Удаляем %s '%s' из базы...\n",
           (*animals)[index].type, (*animals)[index].name);

    // Сдвигаем хвост массива на одну позицию
    for (int i = index; i < *count - 1; i++) {
        (*animals)[i] = (*animals)[i + 1];
    }

    (*count)--;
    *animals = realloc(*animals, (*count) * sizeof(Animal));
    printf("Животное удалено из базы\n");
}

// Обновляем информацию о животном
void editAnimal(Animal* animals, int count, int id, Animal updated) {
    int index = findAnimalById(animals, count, id);
    if (index == -1) {
        printf("Животное с ID %d не найдено!\n", id);
        return;
    }

    updated.id = id;  // Сохраняем оригинальный ID
    animals[index] = updated;
    printf("Данные животного ID %d обновлены\n", id);
}

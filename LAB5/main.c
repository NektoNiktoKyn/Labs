#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "animal.h"

void printMenu() {
    printf("\n--- ЗООПАРК - Управление животными ---\n");
    printf("1. Показать всех обитателей\n");
    printf("2. Найти животное\n");
    printf("3. Убрать животное из зоопарка\n");
    printf("4. Принять новое животное\n");
    printf("5. Изменить данные о животном\n");
    printf("6. Выйти из программы\n");
    printf("Ваш выбор: ");
}

void printAnimalDetails(Animal* a) {
    printf("ID: %d | Вид: %s | Кличка: %s | лет: %d | Вольер №%d\n", 
           a->id, a->type, a->name, a->age, a->enclosure);
}

// Безопасное чтение числа с проверкой
int readInt(const char* prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        printf("Ошибка! Введите число: ");
        while (getchar() != '\n');  // Чистим буфер
    }
    return value;
}

int main() {
    Animal* animals = NULL;
    int count = loadFromFile(&animals, "database.txt");

    printf("Добро пожаловать в систему учета животных!\n");

    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        getchar(); //Лишний проблемный ENTER

        switch(choice) {
            case 1: {
                printAnimals(animals, count);
                break;
            }
            case 2: {
                printf("Искать по (1 - номеру, 2 - кличке): ");
                int option;
                scanf("%d", &option);
                getchar();

                if (option == 1) {
                    int id = readInt("Введите номер животного: ");
                    int index = findAnimalById(animals, count, id);
                    if (index != -1) {
                        printf("Найдено: ");
                        printAnimalDetails(&animals[index]);
                    } else {
                        printf("Животное с номером %d не найдено!\n", id);
                    }
                } else {
                    char name[50];
                    printf("Введите кличку: ");
                    scanf("%49s", name);
                    int index = findAnimalByName(animals, count, name);
                    if (index != -1) {
                        printf("Найдено: ");
                        printAnimalDetails(&animals[index]);
                    } else {
                        printf("Животное с кличкой '%s' не найдено!\n", name);
                    }
                }
                break;
            }
            case 3: {
                int id = readInt("Введите номер животного для удаления: ");
                removeAnimal(&animals, &count, id);
                saveToFile(animals, count, "database.txt");
                break;
            }
            case 4: {
                Animal newAnimal;
                printf("Добавление нового животного:\n");
                printf("Вид: "); scanf("%49s", newAnimal.type);
                printf("Кличка: "); scanf("%49s", newAnimal.name);
                newAnimal.age = readInt("Возраст: ");
                newAnimal.enclosure = readInt("Номер вольера: ");

                // Генерируем новый ID
                newAnimal.id = count > 0 ? animals[count-1].id + 1 : 1000;

                addAnimal(&animals, &count, newAnimal);
                saveToFile(animals, count, "database.txt");
                break;
            }
            case 5: {
                int id = readInt("Введите номер животного для редактирования: ");
                Animal updated;
                printf("Введите новые данные:\n");
                printf("Вид: "); scanf("%49s", updated.type);
                printf("Кличка: "); scanf("%49s", updated.name);
                updated.age = readInt("Возраст: ");
                updated.enclosure = readInt("Номер вольера: ");

                editAnimal(animals, count, id, updated);
                saveToFile(animals, count, "database.txt");
                break;
            }
            case 6: {
                printf("До свидания! Сохраняем данные...\n");
                break;
            }
            default: {
                printf("Неизвестная команда! Попробуйте снова.\n");
                break;
            }
        }
    } while (choice != 6);

    free(animals);
    return 0;
}

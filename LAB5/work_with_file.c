#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"

// Читаем зверинец из файла - возвращаем количество прочитанных зверушек
int loadFromFile(Animal** animals, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Не могу открыть файл %s\n", filename);
        return 0;
    }

    int capacity = 10;  // Начинаем с места для 10 зверушек
    int count = 0;
    *animals = malloc(capacity * sizeof(Animal));

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Если места не хватает - расширяем вольер
        if (count >= capacity) {
            capacity = capacity * 2;
            *animals = realloc(*animals, capacity * sizeof(Animal));
        }

        Animal a;
        // Парсим строку формата "id~тип~имя~возраст~вольер"
        if (sscanf(line, "%d~%49[^~]~%49[^~]~%d~%d",
                   &a.id, a.type, a.name, &a.age, &a.enclosure) == 5) {
            (*animals)[count++] = a;
        } else {
            printf("Пропускаю некорректную строку: %s", line);
        }
    }

    fclose(file);
    printf("Загружено %d животных из файла\n", count);
    return count;
}

// Сохраняем наших питомцев обратно в файл
void saveToFile(Animal* animals, int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка сохранения в файл %s\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d~%s~%s~%d~%d\n",
                animals[i].id, animals[i].type, animals[i].name,
                animals[i].age, animals[i].enclosure);
    }
    fclose(file);
    printf("Сохранено %d животных в файл\n", count);
}

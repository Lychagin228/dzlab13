#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_LENGTH 1000

int main() {

    setlocale(LC_CTYPE, "RUS");

    char input[MAX_LENGTH];
    int target_length;
    int count = 0;
    int in_word = 0;
    int current_length = 0;

    // Ввод строки от пользователя
    printf("Введите строку: ");
    fgets(input, MAX_LENGTH, stdin);

    // Удаление символа новой строки, если он есть
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Ввод целевой длины слова
    printf("Введите длину слова для поиска: ");
    scanf("%d", &target_length);

    // Проверка корректности введенной длины
    if (target_length <= 0) {
        printf("Длина слова должна быть положительным числом.\n");
        return 1;
    }

    // Подсчет слов указанной длины
    for (int i = 0; input[i] != '\0'; i++) {
        if (isspace(input[i])) {
            // Если встретили пробел и были внутри слова
            if (in_word) {
                if (current_length == target_length) {
                    count++;
                }
                in_word = 0;
                current_length = 0;
            }
        }
        else {
            // Если символ не пробельный - это часть слова
            in_word = 1;
            current_length++;
        }
    }

    // Проверка последнего слова в строке
    if (in_word && current_length == target_length) {
        count++;
    }

    // Вывод результата
    printf("Количество слов длиной %d символов: %d\n", target_length, count);

    return 0;
}
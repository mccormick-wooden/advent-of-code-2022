// This list represents the Calories of the food carried by five Elves:

//     The first Elf is carrying food with 1000, 2000, and 3000 Calories, a total of 6000 Calories.
//     The second Elf is carrying one food item with 4000 Calories.
//     The third Elf is carrying food with 5000 and 6000 Calories, a total of 11000 Calories.
//     The fourth Elf is carrying food with 7000, 8000, and 9000 Calories, a total of 24000 Calories.
//     The fifth Elf is carrying one food item with 10000 Calories.

// In case the Elves get hungry and need extra snacks, they need to know which Elf to ask: they'd like to know how many Calories are being carried by the Elf carrying the most Calories. In the example above, this is 24000 (carried by the fourth Elf).

// Find the Elf carrying the most Calories. How many total Calories is that Elf carrying?

#include <stdio.h>
#include <stdlib.h>

const char* CALORIE_FILE_PATH = "input.txt";

int main() {
    FILE* fs = NULL;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int current_elf_total = 0;
    int most_calories = 0;

    if ((fs = fopen(CALORIE_FILE_PATH, "r")) == NULL) {
        return 1;
    }

    while((read = getline(&line, &len, fs)) != -1) {
        int current_line_value = 0;
        if ((current_line_value = atoi(line)) != 0) {
            current_elf_total += current_line_value;
        } else {
            if (current_elf_total > most_calories) {
                most_calories = current_elf_total;
            }
            current_elf_total = 0;
        }
    }

    printf("best: %d\n", most_calories);
    fclose(fs);
    return 0;
}

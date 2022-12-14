#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *INPUT_FILE_PATH = "input.txt";

int main(void) {
    FILE *fp = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int groupValue = 0;
    int solution = 0;

    if ((fp = fopen(INPUT_FILE_PATH, "r")) == NULL) {
        fprintf(stderr, "Can't find %s\n", INPUT_FILE_PATH);
        return EXIT_FAILURE;
    }

    while((read = getline(&line, &len, fp)) != -1) {
        if (strncmp(line, "\n", (long unsigned int)1) == 0) {
            if (groupValue > solution) {
                solution = groupValue;
            }
            groupValue = 0;
        } else {
            groupValue += atoi(line);
        }
    }

    printf("solution: %d\n", solution);

    //cleanup
    fclose(fp);
    free(line);
    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 150000

/* opening a file with option to be abale to read*/
void openFile(char *filename, char *text) {
    printf("Attempting to open file: '%s'\n", filename); // Confirm the filename

    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        size_t bytesRead = fread(text, sizeof(char), MAX_TEXT_SIZE, file);
        printf("Bytes read: %zu\n", bytesRead); // Display how many bytes were read
        fclose(file);
    } else {
        perror("Error opening file"); // Print detailed error message
        printf("Failed to open file '%s'\n", filename); // Confirm the filename again
    }
}


/* opening a file with option to be abale to write*/
void saveFile(char *filename, char *text) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fwrite(text, sizeof(char), strlen(text), file);
        fclose(file);
    } else {
        printf("Failed to save the file.\n");
    }
}

void editFile(char *text) {
    printf("Enter text to add: ");
    fgets(text + strlen(text), MAX_TEXT_SIZE - strlen(text), stdin);
}

void searchInFile(char *text) {
    char searchStr[100];
    printf("Enter the string to search: ");
    fgets(searchStr, 100, stdin);
    searchStr[strcspn(searchStr, "\n")] = 0; // Removing newline character

    int line = 1;
    int count = 0;
    char *temp = text;
    char *found;

    while ((found = strstr(temp, searchStr)) != NULL) {
        count++;
        printf("Found at line %d, position %ld\n", line, found - temp + 1);
        
        temp = found + strlen(searchStr);

        // Counting the number of lines till this point
        for (char *p = text; p < found; ++p) {
            if (*p == '\n') {
                line++;
            }
        }
    }

    if (count == 0) {
        printf("String not found.\n");
    } else {
        printf("'%s' found %d times.\n", searchStr, count);
    }
}


int main() {
    char filename[100];
    char text[MAX_TEXT_SIZE] = {0};
    int choice;

    while (1) {
        printf("1. Open file\n");
        printf("2. Edit text\n");
        printf("3. Save file\n");
        printf("4. search in file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Getting a newline character

        switch (choice) {
            case 1:
                printf("Enter filename to open: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                openFile(filename, text);
                break;
            case 2:
                editFile(text);
                break;
           case 3:
                printf("Enter filename to save: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Removing newline character
                saveFile(filename, text);
                break;
            case 4:
                searchInFile(text);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

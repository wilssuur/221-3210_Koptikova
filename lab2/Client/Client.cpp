#include <stdio.h>
#include <windows.h>

#define BUFFER_SIZE 1024

void readFromFile(const char* fileName) {

    FILE* file;
    fopen_s(&file, fileName, "r");
    if (file == NULL) {
        printf("Failed to open file for reading!\n");
        return;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread_s(buffer, BUFFER_SIZE, sizeof(buffer[0]), BUFFER_SIZE, file)) > 0) {
        printf("%.*s", (int)bytesRead, buffer);
    }

    fclose(file);
}

void writeToFile(const char* fileName, const char* data) {
    FILE* file;
    fopen_s(&file, fileName, "w");
    if (file == NULL) {
        printf("Failed to open file for writing!\n");
        return;
    }

    size_t bytesWritten = fwrite(data, sizeof(char), strlen(data), file);
    if (bytesWritten != strlen(data)) {
        printf("Failed to write to file\n");
    }

    fclose(file);
}

int main() {
    char fileName[] = "test.testlabextension";
    char dataToWrite[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do ";
    printf("1 for read and 2 for write:\n");

    int choice;
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        readFromFile(fileName);
        break;
    case 2:
        writeToFile(fileName, dataToWrite);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }

    printf("\n");
    system("pause");

    return 0;
}
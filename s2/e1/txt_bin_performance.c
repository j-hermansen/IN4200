
#include <stdio.h>
#include <time.h>

void readTextFile();
void writeTextFile();
void writeBinFile();
void readBinFile();
void readWriteTextFile();
void readWriteBinFile();



int main() {

    clock_t begin = clock();
    readWriteTextFile();
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time used for writing and reading to textfile: %lf\n", time_spent);

    begin = clock();
    readWriteBinFile();
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time used for writing and reading to binfile: %lf\n", time_spent);

}

void readWriteTextFile() {
    writeTextFile();
    readTextFile();
}

void readWriteBinFile() {
    writeBinFile();
    readBinFile();
}

void writeTextFile() {

    int num = 122121342;
    FILE *fptr;

    fptr = fopen("textfile.txt", "w");

    fprintf(fptr, "%d", num);
    fclose(fptr);

}

void readTextFile() {


    int num;
    FILE *fptr;

    fptr = fopen("textfile.txt", "r");


    fscanf(fptr, "%d", &num);

    printf("read value from file: %d\n", num);
    fclose(fptr);
}

void writeBinFile() {

    int num = 122121342;
    FILE *fptr;

    fptr = fopen("textfile.txt", "w");

    fwrite(&num, sizeof(int), 1, fptr);
    fclose(fptr);

}

void readBinFile() {


    int num;
    FILE *fptr;

    fptr = fopen("textfile.txt", "r");


    fread(&num, sizeof(int), 1, fptr);

    printf("read value from bin file: %d\n", num);
    fclose(fptr);
}

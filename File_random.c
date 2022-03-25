#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define N 8  // Всего чисел в файле
#define S 2   // Размер числа


// Приводит число к заданному размеру size
int stabilisation(int number, int size) {        
    int flag = 0;
    while (flag != 1) {
        if (number > pow(10, size)) {
            number = number / 10;
        }
        else if (number < pow(10, (size - 1))) {
            number = number * 10;
        }
        else {
            flag = 1;
        }
    }
    return number;
}


// Записываем числа из файла source в массив source_array
void writing_source_array(int* source_array,  FILE *source_file) {   
    fscanf(source_file, "%d", (source_array));
}

// Отправляет полученное число в функцию  stabilisation а затем записывет его в source файл
void writing_source(FILE* source_file, int* source_array, int size_source_array) {                  

    int number;

    for (int i = 0; i < size_source_array; i++) {
    number = rand();  
    number = stabilisation(number, S);                             
    fprintf(source_file, "%d", number);
    writing_source_array(source_array, source_file);
    }

}

// Читаем числа из массива и записываем их в случайном порядке в файл target
void rand_writing_target_array(int* source_array, int size_source_array, FILE *target_file) {                                                                                         
    int counter = 0;
    while (counter != size_source_array) {
        int i = (rand() % size_source_array);
        printf("%d ", i);
        if (*(source_array + i) != 0) {                               
            fprintf(target_file, "%d\n", *(source_array + i));        // Находим рандомное i до тех пор пока не наткнемся на не "пустую" ячейку
            *(source_array + i) = 0;                                  // Уже использованые теперь "пустые" ячейки помечаем нулем
            counter++;                                                // Наращиваем счетчик до тех пор пока не перенесем весь массив
        }
    }
}
 
void main (void) {
	
	FILE *source_file;
    FILE *target_file;
    int source_array[N] = { 0 };
    int size_source_array = N;

	srand(time(NULL));
	
	source_file = fopen("source.txt", "w");
    writing_source(source_file, source_array, size_source_array);
	fclose(source_file);

    target_file = fopen("target.txt", "w");
    rand_writing_target_array(source_array, size_source_array, target_file);
    fclose(target_file);

}
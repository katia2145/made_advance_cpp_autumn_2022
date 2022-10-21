#include <stdio.h>
#include <string.h>
#include "ReadCsv.h"
#include "Statistics.h"

#define MAXPATHLEN 100

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("Неверно запущена программа");
        return 0;
    }

    char path_to_csv[MAXPATHLEN] = "/home/code/made_advance_cpp_autumn_2022/1_homework/csv_examples/input.csv";
    printf("Введите путь к csv файлу, для его анализа:\n");
    scanf("%s", path_to_csv);
    
    struct readerCsv csvRows = read_csv(path_to_csv, true);

    char type[MAXCHAR];
    printf("Введите вид полотна:\n");
    scanf("%s", type);

    int number_of_lanes = 10;
    printf("Введите количество полос движения:\n");
    scanf("%d", &number_of_lanes);

    double quality = mean_quality(csvRows, type, number_of_lanes);
    
    printf("%0.3f\n", quality);

    return 0;
}
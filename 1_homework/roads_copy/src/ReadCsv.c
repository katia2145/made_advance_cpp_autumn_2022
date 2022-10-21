#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "Roadbed.h"
#include "ReadCsv.h"

bool file_exists(char *filename)
{
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

int get_cnt_lines_of_file(char path_to_csv[])
{
    FILE *fp;
    fp = fopen(path_to_csv, "r");
    int cnt_lines = 0;

    while (feof(fp) != true)
    {
        char row[MAXCHAR];
        fgets(row, MAXCHAR, fp);
        ++cnt_lines;
    }
    fclose(fp);
    return cnt_lines;
}

struct roadbed parse_line(char line[])
{
    struct roadbed road;
    int i = 0;
    char *ptr = strtok(line, ",");

    for (; ptr != NULL && i < 4; ptr = strtok(NULL, ","), ++i)
    {
        switch (i)
        {
        case 0:
            for (int j = 0; j < strlen(ptr); ++j)
            {
                road.type[j] = ptr[j];
            }
            break;
        case 1:
            road.length = atoi(ptr);
            break;
        case 2:
            road.quality = atoi(ptr);
            break;
        case 3:
            road.number_of_lanes = atoi(ptr);
            break;
        default:
            break;
        }
    }
    return road;
}

struct readerCsv read_csv(char path_to_csv[], bool header)
{
    if (file_exists(path_to_csv) != 1)
    {
        printf("%s файл не существует\n", path_to_csv);
        exit(1);
    }

    int cnt_lines = get_cnt_lines_of_file(path_to_csv);
    struct roadbed rows[cnt_lines];
    FILE *fp;
    fp = fopen(path_to_csv, "r");

    int row_num = 0;
    while (!feof(fp))
    {
        char line[MAXCHAR];
        if (fgets(line, MAXCHAR, fp))
        {
            if(header && row_num == 0){
                ++row_num;
                continue;
            }
            int line_len = (int)strlen(line);
            rows[row_num] = parse_line(line);
            row_num += 1;
        }
    }

    fclose(fp);

    struct readerCsv roads;
    roads.rows = rows;
    roads.cnt_lines = cnt_lines;
    return roads;
}

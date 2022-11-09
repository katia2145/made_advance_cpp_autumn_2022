#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>

#define MAXCHAR 1000

bool file_exists(char *filename);

int get_cnt_lines_of_file(char path_to_csv[]);

struct readerCsv read_csv(char path_to_csv[], bool header);

struct roadbed parse_line(char line[]);
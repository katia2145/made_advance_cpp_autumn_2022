#define MAXCHAR 1000

struct roadbed
{
    char type[MAXCHAR];
    int length;
    int quality;
    int number_of_lanes;
};

struct readerCsv
{
    struct roadbed *rows;
    int cnt_lines;
};
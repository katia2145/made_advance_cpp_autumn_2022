#include <stdio.h>
#include <string.h>
#include "Roadbed.h"

double mean_quality(struct readerCsv roads, char type[], int number_of_lanes){
    struct roadbed *rows = roads.rows;
    double quality = 0;
    int cnt_type_roads = 0;

    for(int i = 0; i < roads.cnt_lines; ++i){
        if(rows[i].number_of_lanes == number_of_lanes && \
           strcmp(rows[i].type, type) == 0){
            quality += rows[i].quality;
            ++cnt_type_roads;
        }
    }   

    if(cnt_type_roads == 0){
        return 0.0;
    }
    return quality / cnt_type_roads;
}
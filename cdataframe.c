#include "cdataframe.h"
#include <stdlib.h>
#include <stdio.h>

CDataframe *create_cdataframe(size_t initial_capacity) {
    CDataframe *df = malloc(sizeof(*df));
    if (df) {
        df->columns = malloc(initial_capacity * sizeof(Column *));
        df->num_columns = 0;
    }
    return df;
}

void add_column(CDataframe *df, Column *col) {
    df->columns[df->num_columns++] = col;
}

void delete_cdataframe(CDataframe **df) {
    if (df && *df) {
        for (size_t i = 0; i < (*df)->num_columns; i++) {
            delete_column(&((*df)->columns[i]));
        }
        free((*df)->columns);
        free(*df);
        *df = NULL;
    }
}

void print_cdataframe(const CDataframe *df) {
    for (size_t i = 0; i < df->num_columns; i++) {
        print_column(df->columns[i]);
    }
}

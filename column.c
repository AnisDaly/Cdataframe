#include "column.h"
#include <stdlib.h>
#include <stdio.h>

Column *create_column(const char *title) {
    Column *col = malloc(sizeof(*col));
    if (col) {
        col->title = strdup(title);
        col->data = NULL;
        col->size = 0;
        col->capacity = 0;
    }
    return col;
}

void insert_value(Column *col, int value) {
    if (col->size >= col->capacity) {
        size_t new_capacity = col->capacity == 0 ? 4 : col->capacity * 2;
        int *new_data = realloc(col->data, new_capacity * sizeof(int));
        if (new_data) {
            col->data = new_data;
            col->capacity = new_capacity;
        }
    }
    if (col->size < col->capacity) {
        col->data[col->size++] = value;
    }
}

void delete_column(Column **col) {
    if (col && *col) {
        free((*col)->data);
        free((*col)->title);
        free(*col);
        *col = NULL;
    }
}

void print_column(const Column *col) {
    printf("Column: %s\n", col->title);
    for (size_t i = 0; i < col->size; i++) {
        printf("[%zu] %d\n", i, col->data[i]);
    }
}

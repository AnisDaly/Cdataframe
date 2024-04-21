#ifndef COLUMN_H
#define COLUMN_H

#include <stddef.h>

typedef struct {
    char *title;
    int *data;
    size_t size;
    size_t capacity;
} Column;

Column *create_column(const char *title);
void insert_value(Column *col, int value);
void delete_column(Column **col);
void print_column(const Column *col);

#endif

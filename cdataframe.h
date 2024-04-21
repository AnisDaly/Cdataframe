#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"

typedef struct {
    Column **columns;
    size_t num_columns;
} CDataframe;

CDataframe *create_cdataframe(size_t initial_capacity);
void add_column(CDataframe *df, Column *col);
void delete_cdataframe(CDataframe **df);
void print_cdataframe(const CDataframe *df);

#endif

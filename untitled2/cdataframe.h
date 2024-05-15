// cdataframe.h

#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum for different data types
typedef enum {
    INT, FLOAT, CHAR, STRING
} DataType;

// Union to hold data of different types
typedef union {
    int i;
    float f;
    char c;
    char* s;
} Data;

// Structure for a column
typedef struct {
    char* name;
    DataType type;
    Data* data;
    int size;
    int capacity;
} Column;

// Structure for the CDataframe
typedef struct {
    Column** columns;
    int num_columns;
    int capacity;
} CDataframe;

// Function declarations
Column* create_column(char* name, DataType type, int initial_capacity);
void add_data(Column* col, Data data);
void free_column(Column* col);
CDataframe* create_cdataframe(int initial_capacity);
void add_column(CDataframe* df, Column* col);
void display_cdataframe(CDataframe* df);
void free_cdataframe(CDataframe* df);

#endif

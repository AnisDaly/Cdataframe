// cdataframe.c

#include "cdataframe.h"

// Creates a column with a specified initial capacity
Column* create_column(char* name, DataType type, int initial_capacity) {
    Column* col = malloc(sizeof(Column));
    col->name = strdup(name);
    col->type = type;
    col->size = 0;
    col->capacity = initial_capacity;
    col->data = malloc(sizeof(Data) * col->capacity);
    return col;
}

// Resizes the column to accommodate more data
static void resize_column(Column* col) {
    col->capacity *= 2;
    col->data = realloc(col->data, sizeof(Data) * col->capacity);
}

// Adds data to a column
void add_data(Column* col, Data data) {
    if (col->size == col->capacity) {
        resize_column(col);
    }
    col->data[col->size++] = data;
}

// Frees memory allocated to a column
void free_column(Column* col) {
    if (col->type == STRING) {
        for (int i = 0; i < col->size; i++) {
            free(col->data[i].s);
        }
    }
    free(col->data);
    free(col->name);
    free(col);
}

// Creates a new dataframe with a specified initial capacity for columns
CDataframe* create_cdataframe(int initial_capacity) {
    CDataframe* df = malloc(sizeof(CDataframe));
    df->num_columns = 0;
    df->capacity = initial_capacity;
    df->columns = malloc(sizeof(Column*) * df->capacity);
    return df;
}

// Adds a column to the dataframe
void add_column(CDataframe* df, Column* col) {
    if (df->num_columns == df->capacity) {
        df->capacity *= 2;
        df->columns = realloc(df->columns, sizeof(Column*) * df->capacity);
    }
    df->columns[df->num_columns++] = col;
}

// Displays the dataframe's contents
void display_cdataframe(CDataframe* df) {
    for (int i = 0; i < df->num_columns; i++) {
        printf("Column: %s\n", df->columns[i]->name);
        // Display column data based on type
    }
}

// Frees memory allocated to the dataframe
void free_cdataframe(CDataframe* df) {
    for (int i = 0; i < df->num_columns; i++) {
        free_column(df->columns[i]);
    }
    free(df->columns);
    free(df);
}

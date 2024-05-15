// main.c

#include "cdataframe.h"

int main() {
    // Create a dataframe
    CDataframe* df = create_cdataframe(2);  // Initial capacity for 2 columns

    // Create a column for integers
    Column* int_col = create_column("Integer Column", INT, 10);
    Data data;
    data.i = 5;
    add_data(int_col, data);

    // Create a column for strings
    Column* str_col = create_column("String Column", STRING, 10);
    data.s = strdup("Hello");
    add_data(str_col, data);

    // Add columns to the dataframe
    add_column(df, int_col);
    add_column(df, str_col);

    // Display the dataframe
    display_cdataframe(df);

    // Free memory
    free_cdataframe(df);

    return 0;
}

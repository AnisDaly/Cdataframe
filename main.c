#include <stdio.h>
#include "column.h"
#include "cdataframe.h"

int main() {
    CDataframe *df = create_cdataframe(3);


    Column *col1 = create_column("Age");
    Column *col2 = create_column("Score");


    insert_value(col1, 25);
    insert_value(col1, 30);
    insert_value(col1, 22);

    insert_value(col2, 88);
    insert_value(col2, 92);
    insert_value(col2, 75);


    add_column(df, col1);
    add_column(df, col2);


    print_cdataframe(df);


    delete_cdataframe(&df);

    return 0;
}

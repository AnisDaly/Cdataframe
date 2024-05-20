#ifndef DATA_TYPES_H
#define DATA_TYPES_H

// Énumération des différents types de données que les colonnes peuvent contenir
typedef enum {
    INT,    // Entier
    FLOAT,  // Flottant
    DOUBLE, // Double précision
    CHAR,   // Caractère
    STRING  // Chaîne de caractères
} DataType;

// Union permettant de stocker des valeurs de différents types
typedef union {
    int int_val;    // Valeur entière
    float float_val;  // Valeur flottante
    double double_val; // Valeur double
    char char_val;  // Valeur caractère
    char* string_val;  // Pointeur vers une chaîne de caractères
} DataValue;

// Structure représentant une donnée et son type
typedef struct {
    DataType type;  // Type de la donnée
    DataValue value; // Valeur de la donnée
} Data;

#endif
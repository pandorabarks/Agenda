/* Una agenda en C.
IMPORTANTE: Este programa está diseñado únicamente para propósitos educativos.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos de funciones
int agregar();
int borrar();
int modificar();
int busqueda();
int mostrar();
int guardar();

// Estructura principal
typedef struct persona
{
    char nombre[30];
    char apellidos[90];
    char email[90];
    char telefono[30];
    struct persona *next;
}persona;

struct persona *head;
struct persona *tail;

int main(){
    int sel;

    head = (struct persona*)malloc(sizeof(struct persona));
    tail = (struct persona*)malloc(sizeof(struct persona));

    do
    {
        printf("\t-- Menú -- \n\n1.- Ingresar nuevo contacto\n2.- Modificar contacto\n3.- Borrar contacto\n4.- Búsqueda\n5.- Mostrar todos los contactos\n6.- Guardar la lista de contactos actual\n7.- Salir\n\nA continuación, ingrese la opción: ");
        scanf("%d", &sel);

        switch (sel)
        {
        case 1:
            agregar();
            break;

        case 2:
            modificar();
            break;

        case 3:
            borrar();
            break;

        case 4:
            busqueda();
            break;

        case 5:
            mostrar();
            break;
        
        case 6:
            guardar();
            break;

        case 7:
            printf("\nHasta luego.");
            return 0;

        }
    } while (sel != -1);
    
}

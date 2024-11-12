// Una agenda en C, usando estructuras.
//IMPORTANTE: Este programa está diseñado únicamente para propósitos educativos.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int agregar();
int borrar();
int modificar();
int busqueda();
int mostrar();
int guardar();

typedef struct persona
{
    char nombre[100]; 
    char apellidos[100];
    char email[100];
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

int agregar(){
    persona *nuevo = (struct persona*) malloc (sizeof(struct persona));

    printf("\nIngresa el nombre: \n");
    scanf("%s", &nuevo->nombre);
    printf("Ingrese ambos apellidos: \n");
    scanf("%s", &nuevo->apellidos);
    printf("Ingresa el número de teléfono: \n");
    scanf("%s", &nuevo->telefono);
    printf("Ingresa la dirección de email: \n");
    scanf("%s", &nuevo->email);

    nuevo -> next = head ->next;
    head -> next = nuevo;
    return 0;

}

int borrar(){
    return 0;
}

int mostrar(){
    persona *t;
    t = head -> next;
    
    printf("\n\t-- Listado de estudiantes --\n Esta es una lista de todos los estudiantes ingresados en esta agenda:\n");

    while (t->next != NULL)
    {
        printf("Nombre: %s\nApellidos: %s\nNúmero de teléfono: %s\nEmail: %s\n\n", t->nombre, t->apellidos, t->telefono, t->email);
        t= t->next;
    }
    return 0;
}

int busqueda(){
    struct persona *t;
    t = head->next;
    char palabraclave[30];

    printf("Ingresa el nombre de la persona que deseas buscar: ");
    scanf("%s", &palabraclave);

    if (strcmp(t-> nombre, palabraclave) == 0)
    {
         printf("Nombre: %s\nApellidos: %s\nNúmero de teléfono: %s\nEmail: %s\n\n", t->nombre, t->apellidos, t->telefono, t->email);
    }
    t = t->next;
    return 0;
}

int guardar(){
    return 0;
}

int modificar(){
    return 0;
}
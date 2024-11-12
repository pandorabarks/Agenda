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

    printf("\n\t-- Agregando a una nueva persona --\n");
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
    printf("\nAVISO DEL SISTEMA: Persona añadida exitosamente.\n");
    return 0;

}

int borrar(){
    return 0;
}

int mostrar(){
    persona *t;
    t = head -> next;
    
    printf("\n\t-- Listado de estudiantes --\n\nEsta es una lista de todos los estudiantes ingresados en esta agenda:\n");

    while (t->next != NULL)
    {
        printf("Nombre: %s\nApellidos: %s\nNúmero de teléfono: %s\nEmail: %s\n\n", t->nombre, t->apellidos, t->telefono, t->email);
        t= t->next;
        return 0;
    }
}

int busqueda(){
        struct persona *t;
        t=head->next;
        char nombretemp[100];

        if (head == NULL){
            printf("La lista está vacía.\n");
            return 0;
        }

        printf("Ingresa el nombre de la persona: ");
        scanf("%s", nombretemp);
        
        while (t != NULL)
        {
            if (strcmp(t->nombre, nombretemp) == 0)
            {
                printf("Nombre: %s\nApellidos: %s\nNúmero de teléfono: %s\nEmail: %s\n\n", t->nombre, t->apellidos, t->telefono, t->email);
                return 0;
            }
            t= t->next;
        }
        
        printf("Esta persona no fue encontrada, intenta nuevamente.\n");
        return 0;
    }

int guardar(){
    return 0;
}

int modificar(){
    struct persona *t = head->next;
    char nombretemp[100], apellidostemp[100], telefonotemp[30], emailtemp[100];
    char nuevonombre[100], nuevoapellido[100], nuevotelefono[30], nuevoemail[100];

    printf("\n\t-- Modificando los datos --");
    if (head == NULL)
    {
        printf("La lista es vacía.\n");
        return 0;
    }

    printf("\nIngresa el nombre de la persona para modificar su información: ");
    scanf("%s", nombretemp);

    while (t != NULL)
    {
        if (strcmp(t->nombre, nombretemp) == 0)
        {
            printf("\n\nPersona encontrada: %s %s\n\nAVISO: Se modificarán todos los registros que contengan este nombre, proceda con precaución.\n", t->nombre, t->apellidos);
            printf("\nIngresa su nuevo nombre: ");
            scanf("%s", nuevonombre);

            // Copia los strings nuevos a la categoría correspondiente en el struct.
            strcpy(t->nombre, nuevonombre);

            printf("\nTodos los registros encontrados se han modificado.\n");
            return 0;
        }
        t= t->next;
    }

    printf("Persona no encontrada.\n");
    return 0;
}
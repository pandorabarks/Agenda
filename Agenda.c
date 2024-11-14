// Una agenda en C, usando estructuras.
//IMPORTANTE: Este programa está diseñado únicamente para propósitos educativos.

// Hecho por Josué
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
    struct persona *actual;
    struct persona *prev;
    actual = head -> next;
    prev = head;
    char nombretemp[100];

    if (head == NULL)
    {
        printf("\nLa lista está vacía.");
        return 0;
    }

    printf("\n\t-- Borrar registro --\n");
    printf("\nADVERTENCIA: Todos los registros que contengan el nombre a continuación serán eliminados, proceda con precaución.\nIntroduzca el nombre del registro a eliminar: ");
    scanf("%s", nombretemp);

    while (actual->next != NULL)
    {
        if (strcmp(actual->nombre, nombretemp) == 0)
        {
            printf("\nNombres que se van a borrar: %s %s\n", actual->nombre);
            prev -> next = actual -> next;
            free(actual);
        }
        prev = actual;
        actual = actual -> next;

    }

    printf("\nEsta persona no fue encontrada, intenta nuevamente.\n");
    return 0;
}

int mostrar(){
    persona *t;
    t = head -> next;
    
    printf("\n\t-- Listado de estudiantes --\n\nEsta es una lista de todos los estudiantes ingresados en esta agenda:\n");

    if (head == NULL || head ->next == NULL)
    {
        printf("La lista de contactos está vacía.");
        return 0;
    }
    
    while (t != NULL && t != tail){
        if (t->next != NULL)
        {
            printf("Nombre: %s\nApellidos: %s\nNúmero de teléfono: %s\nEmail: %s\n\n", t->nombre, t->apellidos, t->telefono, t->email);
            t = t->next;
        }
        return 0;
    }
    return 0;
}


int busqueda(){
        struct persona *t;
        t=head->next;
        char nombretemp[100];

        if (head == NULL){
            printf("La lista está vacía.\n");
            return 0;
        }

        printf("\n\t-- Búsqueda --\n\n");
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

int guardar() {
    FILE *f = fopen("contactos.txt", "w");
    if (f == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    struct persona *t = head->next;
    while (t != NULL && t != tail) {
        fprintf(f, "Nombre: %s\n", t->nombre);
        fprintf(f, "Apellidos: %s\n", t->apellidos);
        fprintf(f, "Teléfono: %s\n", t->telefono);
        fprintf(f, "Email: %s\n\n", t->email);
        t = t->next;
    }

    fclose(f);
    printf("\nAVISO DEL SISTEMA: Contactos guardados exitosamente en contactos.txt\n");
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
            printf("\nIngresa sus nuevos apellidos: ");
            scanf("%s", nuevoapellido);
            printf("\nIngresa su nuevo teléfono: ");
            scanf("%s", nuevotelefono);
            printf("\nIngresa su nuevo email: ");
            scanf("%s", nuevoemail);
        
            // Copia los strings nuevos a la categoría correspondiente en el struct.
            strcpy(t->nombre, nuevonombre);
            strcpy(t->apellidos, nuevoapellido);
            strcpy(t->telefono, nuevotelefono);
            strcpy(t->email, nuevoemail);

            printf("\nTodos los registros encontrados se han modificado.\n");
            return 0;
        }
        t= t->next;
    }

    printf("Persona no encontrada.\n");
    return 0;
}
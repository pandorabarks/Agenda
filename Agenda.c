// Una agenda en C, usando estructuras.
// IMPORTANTE: Este programa está diseñado únicamente para propósitos educativos.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int agregar();
int borrar();
int modificar();
int busqueda();
int mostrar();
int guardar();

// Una estructura para almacenar todos los datos necesarios de cada persona en la agenda. 
typedef struct persona
{
    char nombre[100]; 
    char apellidos[100]; // A pesar de que esté en plural, solo almacenará un apellido.
    char email[100];
    char telefono[30];
    /* Todos los valores se guardan como cadenas de caracteres, esto se hace por simplicidad
    y para evitar lidiar con cosas como un número de télefono que es más grande que el entero más grande.*/
    struct persona *next;
}persona;

// head y tail para representar el inicio y el final de la lista de contactos
struct persona *head;
struct persona *tail;

int main(){
    // La función main() solo incluye la inicialización de los punteros de los structs, la reservación dinámica de memoria y el menú principal.
    int sel;

    // Se inicializa la reservación dinámica de memoria.
    head = (struct persona*)malloc(sizeof(struct persona));
    tail = (struct persona*)malloc(sizeof(struct persona));

    head -> next = tail;
    tail -> next = NULL;

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

// Agrega a una persona a la estructura y deja espacio para añadir una cantidad cualquiera en la agenda.

int agregar(){
    persona *nuevo = (struct persona*) malloc (sizeof(struct persona));

    printf("\n\t-- Agregando a una nueva persona --\n");
    printf("\nIngresa el nombre: \n");
    scanf("%s", &nuevo->nombre);
    printf("Ingresa un apellido: \n");
    scanf("%s", &nuevo->apellidos);
    printf("Ingresa el número de teléfono: \n");
    scanf("%s", &nuevo->telefono);
    printf("Ingresa la dirección de email: \n");
    scanf("%s", &nuevo->email);

    nuevo -> next = head ->next;
    head -> next = nuevo;
    printf("\nAVISO DEL SISTEMA: Persona añadida exitosamente.\n\n");
    return 0;

}


// Usa la búsqueda, compara cadenas, después libera la memoria.
int borrar(){
    struct persona *actual;
    struct persona *prev;
    actual = head -> next;
    prev = head;
    char nombretemp[100];

    // Si no hay ningún registro...
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

    // si strcmp(actual->nombre, nombretemp) == 1, es decir, si las cadenas no coinciden...
    printf("\nEsta persona no fue encontrada, intenta nuevamente.\n");
    return 0;
}


// Muestra a todas las personas de la agenda almacenadas.
int mostrar(){
    
    struct persona *t = head -> next;
    printf("\n\t-- Listado de personas --\n");

    while (t != NULL && t !=tail)
    {
        printf("\nNombre de la persona: %s %s\n", t->nombre, t->apellidos);
        printf("Email: %s\n", t->email);
        printf("Numero de telefono: %s\n", t->telefono);
        t = t->next;
    }
    return 0;
}

// Puedes realizar una búsqueda de cualquier persona en la agenda, independientemente de su posición en la estructura, todo lo que necesitas es el primer nombre.
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

// Esta función guarda la lista de contactos en un documento de texto para futuros propósitos.
int guardar() {
    // Crea un archivo llamado contactos.txt que se almacena en el mismo directorio donde se ejecute este programa.
    FILE *f = fopen("contactos.txt", "w");
    
    // Si no es posible crear el archivo, dígase por tratarse de un directorio de solo lectura...
    if (f == NULL) {
        printf("Error al crear el archivo.\n");
        return 0;
    }

    fprintf(f, "\t-- Lista de contactos --\n");
    // Cicla entre los elementos del struct para poder llenar la lista.
    struct persona *t = head->next;
     while (t != NULL && t != tail){
            fprintf(f, "Nombre: %s\n", t->nombre);
            fprintf(f, "Apellidos: %s\n", t->apellidos);
            fprintf(f, "Teléfono: %s\n", t->telefono);
            fprintf(f, "Email: %s\n\n", t->email);
            t = t->next;
    }
    fclose(f);
    printf("\nAVISO DEL SISTEMA: Contactos guardados exitosamente en contactos.txt\n\n");
    return 0;
}

// Se puede modificar los valores que contenga cualquier contacto en la estrucura, siempre y cuando se cuente con el nombre de la persona.
int modificar(){
    struct persona *t = head->next;
    char nombretemp[100], nuevonombre[100], nuevoapellido[100], nuevotelefono[30], nuevoemail[100];

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
#include <stdio.h>
#include <stdlib.h>

// Declaracion de la estructura
typedef struct Node {
  int id;
  char *name;
  // Referencia del siguiente nodo para enlazar la lista
  struct Node *next;
} list;

list *merge(list *a, list *b) {
  list* result = NULL;

  // Caso base
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

  // Recursion de cada lista dividida
    if (a->id <= b->id) {
        result = a;
        result->next = merge(a->next, b);
    }
    else {
        result = b;
        result->next = merge(a, b->next);
    }
    return (result);
  return a;
}

void split(list *head, list **a, list **b) {
  list *slow;
  list *fast;
  fast = head->next;
  slow = head;

  // Avanza dos elementos el puntero fast y avanza uno el puntero slow
   while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
  // El puntero slow queda a lal mitad  y el  puntero fast al final

  // Divide/desconecta las dos listas
  *a = head;
  *b = slow->next;
  slow->next = NULL;
}
// Funcion para ordenar la lista
// Uso del algoritmo merge sort
void sort(list **head) {
  // Variable puntero al nodo head
  list *node = *head;
  // Variables nodo de apoyo para dividir la lista
  list *a;
  list *b;

  // Caso base, si la lista es vacia o si hay un unico elemento
  if ((node == NULL) || (node->next == NULL)) {
    return;
  }

  // Divide la lista en dos listas
  split(node, &a, &b);

  // Ordena recursivamente las dos listas
  sort(&a);
  sort(&b);

  *head = merge(a, b);
}

// Funcion para añadir elementos al final  de una lista
// Toma como parrametros
// Puntero a un puntero, para poder modificar a donde apunta el puntero
// contenido *ver diagrama int id, valor que se le dará en el apartado id al
// nodo añadido char *name, nombre que se le asignara al apartado name
void add_end(list **head, int id, char *name) {
  // Valida si una lista esta vacia
  // ** Si la lista es NULL ((void*)0)
  if (*head == NULL) {
    // Llama a la funcion malloc para reservar un espacio de memoria del tamaño
    // "list", regresa un puntero a ese espacio de memoria y lo asigna al
    // puntero contenid por el puntero head *ver diagrama
    *head = malloc(sizeof(list));
    // Asigna todos los elementos pasados por la funcion a su repectivo elemento
    // dentro de la estructura
    (*head)->id = id;
    (*head)->name = name;
    (*head)->next = NULL;
    return; // Termina la ejecucion de la funcion en lugar de continuar con las
            // lineas de código de abajo
  }
  // Declara variable puntero a una list para iterar por los elementos
  // existentes de la lista
  list *current = *head;
  while (current->next != NULL) {
    // Mientras el apartado next, del elemento actual que estamos evaluando sea
    // diferente NULL/((void*)0) vamos a cambiar el elemento que estamos
    // evaluando por el siguiente Con esto conseguimos que current sea el ultimo
    // elemento de la lista
    current = current->next;
  }
  // Se reserva un espacio de memoria del tamaño list y el puntero a ese espacio
  // de memoria se asigna al siguiente elemento de la lista
  current->next = malloc(sizeof(list));
  // Se asignan todos los elementos de el nuevo nodo/persona
  current->next->id = id;
  current->next->name = name;
  current->next->next = NULL;
}

// Funcion para añadir elementos al incio de la lista
// Recibe los datos a ingresar y un puntero a un puntero de la head de la lista
void add_start(list **head, int id, char *name) {
  // Valida si la lista es nula
  if (*head == NULL) {
    // Llama a la funcion malloc para reservar un espacio de memoria del tamaño
    // "list", regresa un puntero a ese espacio de memoria y lo asigna al
    // puntero contenid por el puntero head *ver diagrama
    *head = malloc(sizeof(list));
    // Asigna todos los elementos pasados por la funcion a su repectivo elemento
    // dentro de la estructura
    (*head)->id = id;
    (*head)->name = name;
    (*head)->next = NULL;
    return; // Termina la ejecucion de la funcion en lugar de continuar con las
            // lineas de código de abajo*head =
  }
  // Se reserva espacio de memoria para el siguiente nodo de la lista
  list *new_head = malloc(sizeof(list));
  // Se asignan los valores al nuevo nodo
  new_head->name = name;
  new_head->id = id;
  // El nuevo nodo apunta a la antigua head
  new_head->next = *head;
  // El puntero a la head apunta a nuestro nuevo nodo
  *head = new_head;
}

// Funcion para borrar al inicio de una lista
void delete_start(list **head) {
  // Valida si la lista esta vacia
  if (*head == NULL) {
    // En caso de estar vacia termina la ejecucion del programa
    return;
  }
  list *remove = *head; // Guardamos la direccion de memoria
  // ocupada por el elemento que queremos eliminar
  *head = (*head)->next; // El puntero a la cabeza de la lista
  // esta apuntando al nodo que estaba después de la cabeza
  free(remove); // Liberamos el espacio de memoria
  // que ocupaba nuestra antigua cabeza
}

// Funcion para borrar al final de  la lista
// Recibe un puntero a un puntero a una lista para poder validar si la lista es
// vacia
void delete_end(list **head) {
  // Validacion de si la lista es null
  if (*head == NULL) {
    return;
  }
  // Variable para iterar a un nodo antes del final de la lista
  list *current = *head;
  // Iteracion hasta llegar a un elemento antes del final de la lista
  while (current->next->next != NULL) {
    current = current->next;
  }
  // Variable para guardar el espacio de memoria que será liberado
  list *remove = current->next;
  // Cambiamos la variable next del ahora ultimo nodo de la lista por  NULL (ya
  // que es la nueva tail)
  current->next = NULL;
  // Liberamos el espacio de memoria conteniendo el ultimo nodo
  free(remove);
}

// Impresion recursiva de la lista
void print_recursion(list **head) {
  // Si la lista es vacia o si se llega al ultimo elemento de la lista
  // Se termina la ejecucion de la funcion y no pasa nada
  if (*head == NULL) {
    return;
  } else {
    // Si el nodo actual no es NULL se ejecuta lo siguiente
    //
    // Se imprimen los datos del nodo que recibió la función
    printf("El nombre de la persona numero %d es %s\n", (*head)->id,
           (*head)->name);
    // Se vuelve a llamar la función con el siguiente elemento
    print_recursion(&(*head)->next);
  }
}

// Impresión de la lista con método iterativo
void print_list(list *head) {
  // No se requiere un puntero de puntero porque no se cambiarán valores
  // Se declara variable para iterar
  list *current = head;
  while (current != NULL) {
    // Si se cumple el requisito de no ser NULL se imprimen los datos contenidos
    // en el nodo
    printf("El nombre de la persona numero %d es %s\n", current->id,
           current->name);
    // Y se pasa al siguiente elemento del nodo
    current = current->next;
  }
}

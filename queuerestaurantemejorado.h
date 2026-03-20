#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define MAX_ORDENES 6

typedef unsigned int data;
typedef enum {FALSO, VERDERO} boolean;

struct elem {
    data d;
    struct elem *next;
};

typedef struct elem elem;

struct queue {
    int cnt;
    elem *head;
    elem *tail;
};

typedef struct queue queue;

typedef enum {
    HAMBURGUESA = 1,
    PIZZA,
    TACO,
    ENSALADA,
    REFRESCO
} platillo;

void initialize(queue *q) {
    q->cnt = 0;
    q->head = NULL;
    q->tail = NULL;
}

boolean empty(const queue *q) {
    return (q->cnt == 0) ? VERDERO : FALSO;
}

boolean full(const queue *q) {
    return (q->cnt >= MAX_ORDENES) ? VERDERO : FALSO;
}

void enqueue(data d, queue *q) {
    if (full(q)) {
        printf("Limite de ordenes alcanzado\n");
        return;
    }
    elem *nuevo = (elem*) malloc(sizeof(elem));
    nuevo->d = d;
    nuevo->next = NULL;

    if (empty(q)) {
        q->head = nuevo;
    } else {
        q->tail->next = nuevo;
    }

    q->tail = nuevo;
    q->cnt++;
}

data deque(queue *q) {
    if (empty(q)) return EMPTY;
    elem *temp = q->head;
    data d = temp->d;
    q->head = q->head->next;
    free(temp);
    q->cnt--;
    if (q->cnt == 0) q->tail = NULL;
    return d;
}

data head(const queue *q) {
    if (empty(q)) return EMPTY;
    return q->head->d;
}

data tail(const queue *q) {
    if (empty(q)) return EMPTY;
    return q->tail->d;
}

const char* nombre_platillo(data d) {
    switch(d) {
        case HAMBURGUESA: return "Hamburguesa";
        case PIZZA: return "Pizza";
        case TACO: return "Taco";
        case ENSALADA: return "Ensalada";
        case REFRESCO: return "Refresco";
        default: return "Desconocido";
    }
}

int main() {
    queue q;
    initialize(&q);
    int opcion, plat;

    do {
        printf("\n1. Recibir comanda\n2. Servir platillo\n3. Ver siguiente\n4. Ver ultimo\n0. Salir\nOpcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("1.Hamburguesa 2.Pizza 3.Taco 4.Ensalada 5.Refresco\n");
                scanf("%d", &plat);
                enqueue(plat, &q);
                break;
            case 2:
                if (!empty(&q)) printf("%s\n", nombre_platillo(deque(&q)));
                else printf("No hay ordenes\n");
                break;
            case 3:
                if (!empty(&q)) printf("%s\n", nombre_platillo(head(&q)));
                else printf("Cola vacia\n");
                break;
            case 4:
                if (!empty(&q)) printf("%s\n", nombre_platillo(tail(&q)));
                else printf("Cola vacia\n");
                break;
        }

    } while(opcion != 0);

    /* 
    Pregunta: ¿Cómo limitar la cola a 6 órdenes en espera?
    Respuesta: Se define MAX_ORDENES = 6 y en la función enqueue se verifica con full(q) que no se agreguen más elementos cuando la cola ya tiene 6 órdenes.
    */

    return 0;
}

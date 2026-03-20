#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 6   //

typedef unsigned int data;
typedef enum {FALSO, VERDADERO} boolean;

/* ===== ESTRUCTURAS ===== */
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

/* ===== FUNCIONES DE COLA ===== */
void initialize(queue *q) {
    q->cnt = 0;
    q->head = NULL;
    q->tail = NULL;
}

boolean empty(const queue *q) {
    return q->cnt == EMPTY;
}

boolean full(const queue *q) {
    return q->cnt == FULL;
}

void enqueue(data d, queue *q) {
    if (full(q)) {
        printf(" La cola esta llena (max 6 comandas)\n");
        return;
    }

    elem *e = (elem*) malloc(sizeof(elem));
    e->d = d;
    e->next = NULL;

    if (empty(q)) {
        q->head = e;
    } else {
        q->tail->next = e;
    }

    q->tail = e;
    q->cnt++;
}

data deque(queue *q) {
    if (empty(q)) {
        printf(" No hay comandas\n");
        return 0;
    }

    elem *e = q->head;
    data d = e->d;

    q->head = e->next;
    free(e);

    q->cnt--;

    if (q->cnt == 0) {
        q->tail = NULL;
    }

    return d;
}

data head(const queue *q) {
    if (empty(q)) return 0;
    return q->head->d;
}

data tail(const queue *q) {
    if (empty(q)) return 0;
    return q->tail->d;
}

/* ===== PLATILLOS ===== */
typedef enum {
    HAMBURGUESA = 1,
    PIZZA,
    TACOS,
    ENSALADA,
    REFRESCO
} platillo;

void mostrarMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Hamburguesa\n");
    printf("2. Pizza\n");
    printf("3. Tacos\n");
    printf("4. Ensalada\n");
    printf("5. Refresco\n");
}

void imprimirPlatillo(data d) {
    switch(d) {
        case HAMBURGUESA: printf("Hamburguesa"); break;
        case PIZZA: printf("Pizza"); break;
        case TACOS: printf("Tacos"); break;
        case ENSALADA: printf("Ensalada"); break;
        case REFRESCO: printf("Refresco"); break;
        default: printf("Desconocido");
    }
}

/* ===== MAIN ===== */
int main() {
    queue q;
    initialize(&q);

    int opcion, pedido;

    do {
        printf("\n===== SISTEMA DE COMANDAS =====\n");
        printf("1. Recibir comanda (enqueue)\n");
        printf("2. Servir platillo (dequeue)\n");
        printf("3. Ver siguiente platillo\n");
        printf("4. Ver ultimo platillo\n");
        printf("5. Ver total de ordenes\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                mostrarMenu();
                printf("Seleccione platillo: ");
                scanf("%d", &pedido);
                enqueue(pedido, &q);
                break;

            case 2:
                if (!empty(&q)) {
                    data servido = deque(&q);
                    printf("🍽 Sirviendo: ");
                    imprimirPlatillo(servido);
                    printf("\n");
                } else {
                    printf("No hay comandas\n");
                }
                break;

            case 3:
                if (!empty(&q)) {
                    printf("Siguiente: ");
                    imprimirPlatillo(head(&q));
                    printf("\n");
                } else {
                    printf("No hay comandas\n");
                }
                break;

            case 4:
                if (!empty(&q)) {
                    printf("Ultimo: ");
                    imprimirPlatillo(tail(&q));
                    printf("\n");
                } else {
                    printf("No hay comandas\n");
                }
                break;

            case 5:
                printf("Ordenes en espera: %d\n", q.cnt);
                break;
        }

    } while(opcion != 6);

    return 0;
}

/* Rutinas básicas */
#include "queue.h"

void initialize(queue *q)
{
    q -> cnt = 0;  // La cuenta de una cola comienza en 0.
    q -> head = NULL; // La cabeza de la cola comienza en Nulo.
    q -> tail = NULL; // La parte trasera de la cola comienza en Nulo.
}

data dequeue(queue *q)
{
    data d;
    elem *p;

    d = q -> head -> d; // El dato es el que está almacenado en la cabeza de la cola.
    p = q -> head; // El elemento p es la cabeza de la cola.
    q -> head = q -> head -> next; //Cuando desencolamos la cabeza, la nueva cabeza debe ser el siguiente elemento en la cola al que apuntaba la cabeza que desencolamos.
    q -> cnt--; //Bajamos el contador de la cola una unidad.
    free(p); //Liberamos el espacio ocupado por la cabeza desencolada.
    return d; //Vamos a ver lo que estaba guardado en la cabeza desencolada.
}

void enqueue(data d, queue *q)
{
    elem *p;    // Declaramos un apuntador a un espacio donde reservar un objeto de tipo "elem" (elemento de una cola)

    p = malloc(sizeof(elem)); // Encontramos una ubicación en la memoria con suficiente espacio para almacenar un objeto de tipo "elemento" y se la pasamos al apuntador p.

    p -> d = d; // El dato d (una de las componentes del elemento apuntado por p) lo rellenamos con el dato que tenemos en los argumentos de la función "enqueue".

    p -> next = NULL; // El apuntador al "siguiente elemento de la cola" lo iniciamos en nulo, porque en este momento no sabemos si la cola está vacía o no.

    if (!empty(q)) {
        q -> tail -> next = p; // Si la cola no estaba vacía, entonces hacemos que su último elemento antes de encolar ahora apunte como "siguiente" al nuevo elemento que estamos encolando.

        q -> tail = p; // Actualizamos el apuntador al último elemento de la cola.
    } 
    else {
        q -> head = q -> tail = p; // Si la cola está vacía, ambos apuntadores head y tail adoptan lo que el apuntador p contiene.
    }
    q -> cnt++; //Aumentamos la cuenta del apuntador
}

data head(const queue *q)
{
 assert(!empty(q));  // Aseguramos que la cola no esté vacía
    return q->head->d;  // Devolvemos el dato que está en la cabeza
}

boolean empty(const queue *q)
{
    return ((boolean) (q -> cnt == EMPTY));
}

boolean full(const queue *q)
{
   return FALSE; // Nunca estará llena porque usamos memoria dinámica
}

int main(void)
{
    int c;
    int cnt_a = 0;
    int cnt_b = 0;
    data pid;   //  Process ID (id de un proceso)
    queue a, b;

    initialize(&a); // Inicializamos la cola a.
    initialize(&b); // Inicializamos la cola b.

    /* Encolamos las peticiones */
    while ((c = getchar()) != EOF) {
        switch (c) {
            case 'a':   // Si el carácter leído es 'a', entonces encolamos
            assert(scanf("%u", &pid) == 1); // Leemos el id del proceso que hizo la petición y lo guardamos en pid.
            if (!full(&a)) {
                enqueue(pid, &a); // Encolamos el id del proceso en la cola a.
            }
            break;
            case 'b':   // Si el carácter leído es 'b', entonces encolamos
            assert(scanf("%u", &pid) == 1); // Leemos el id
            if (!full(&b)) {
                enqueue(pid, &b); // Encolamos el id del proceso en la cola b.
            }
        }    
    }

    /* Desencolamos las peticiones */
    printf("Procesando peticiones de la cola a:\n");
    while (!empty(&a)) {
        pid = dequeue(&a); // Desencolamos un id de proceso de la cola a y lo guardamos en pid.
        printf(" La  TAREA %u es %d\n", ++cnt_a, pid); // Imprimimos el id del proceso desencolado
    }
    printf("Procesando peticiones de la cola b:\n");
    while (!empty(&b)) {
        pid = dequeue(&b); // Desencolamos un id de proceso de la cola b y lo guardamos en pid.
        printf(" La  TAREA %u es %u\n", ++cnt_b, pid); // Imprimimos el id del proceso desencolado
    }
    return 0;
}

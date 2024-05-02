#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Definisikan tipe data queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Fungsi untuk membuat queue baru
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Fungsi untuk memeriksa apakah queue kosong
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Fungsi untuk memeriksa apakah queue penuh
int isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Fungsi untuk menambahkan elemen ke queue (enqueue)
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Error: Queue penuh, enqueue gagal.\n");
        return;
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    printf("Enqueue: %d\n", value);
}

// Fungsi untuk menghapus elemen dari queue (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue kosong, dequeue gagal.\n");
        return -1;
    }
    int removedValue = queue->items[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
    printf("Dequeue: %d\n", removedValue);
    return removedValue;
}

// Fungsi utama
int main() {
    Queue* queue = createQueue(); // Buat queue baru

    // Tes operasi enqueue dan dequeue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6); // Queue penuh, enqueue gagal
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue); // Kondisi queue kosong

    free(queue); // Bebaskan memori yang dialokasikan untuk queue
    return 0;
}


#include <stddef.h>
#include <malloc.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct {
	int* array;
	size_t size;
	size_t start;
	size_t end;
	bool full;
} buffer;

void buffer_init(buffer *buffer, size_t size) {
	buffer->array = malloc(sizeof(size_t) * size);
	buffer->size = size;
	buffer->start = 0;
	buffer->end = 0;
	buffer->full = false;
}

// Adds item to buffer, unless buffer is full.
void buffer_push (buffer *buffer, int item) {
	if (buffer->full) {
		return;
	}

	buffer->array[buffer->end] = item;
	buffer->end = (buffer->end + 1) % buffer->size;
	buffer->full = buffer->end == buffer->start;
}

int buffer_pop(buffer *buffer) {
	int item = buffer->array[buffer->start];
	buffer->start = (buffer->start + 1) % buffer->size;
	buffer->full = false;
	return item;
}

void buffer_free(buffer *buffer) {
	free(buffer->array);
}

typedef struct {
	buffer* conn_buffer;
	pthread_mutex_t conn_buffer_lock;
	pthread_cond_t conn_available;
} thread_pool;

int thread_pool_init(thread_pool* pool, long thread_count, size_t buffer_size) {
	thread_count;
	buffer_init(pool->conn_buffer, buffer_size);
	pthread_mutex_init(&pool->conn_buffer_lock,NULL);
	pthread_cond_init(&pool->conn_available, NULL);
	return 0;
}

void thread_pool_free(thread_pool* pool) {
	free(pool->conn_buffer);
}
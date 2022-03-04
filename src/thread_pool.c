#include <stddef.h>
#include <bits/pthreadtypes.h>
#include <malloc.h>
#include <pthread.h>

typedef struct {
	int* conn_buffer;
	size_t conn_buffer_size;
	pthread_mutex_t conn_buffer_lock;
	pthread_cond_t conn_available;
} thread_pool;

int thread_pool_init(thread_pool* pool, long thread_count, size_t buffer_size) {
	pool->conn_buffer = malloc(sizeof(size_t) * buffer_size);
	pool->conn_buffer_size = buffer_size;
	pthread_mutex_init(&pool->conn_buffer_lock,NULL);
	pthread_cond_init(&pool->conn_available, NULL);
	return 0;
}

void thread_pool_free(thread_pool* pool) {

}
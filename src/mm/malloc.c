// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void* result = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (result == MAP_FAILED) {
        return NULL;
    }
    mem_list_add(result, size);
    return result;

    /* TODO: Implement malloc(). */
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
    void *allocated = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (allocated != NULL) {
        memset(allocated, 0, total_size);
    }
    return allocated;
	/* TODO: Implement calloc(). */
}

void free(void *ptr)
{
    struct mem_list *list = mem_list_find(ptr);
	munmap(list->start, list->len);
    mem_list_del(ptr);
    /* TODO: Implement free(). */
}

void *realloc(void *ptr, size_t size)
{
	void *new_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    struct mem_list *list = mem_list_find(ptr);
    if (new_ptr != NULL && ptr != NULL) {
        memcpy(new_ptr, ptr, size);
        munmap(ptr, list->len);
    }
    mem_list_del(ptr);
    mem_list_add(ptr, size);
    return new_ptr;
	/* TODO: Implement realloc(). */
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t total_size = nmemb * size;
    return realloc(ptr, total_size);
}

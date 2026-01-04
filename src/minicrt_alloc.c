#include <stddef.h>
#include <stdint.h>
#include <windows.h>

static HANDLE minicrt_heap_handle(void)
{
	static HANDLE heap = NULL;
	if (!heap) {
		heap = HeapCreate(0, 0, 0);
		if (!heap) {
			heap = GetProcessHeap();
		}
	}
	return heap;
}

void *malloc(size_t size)
{
	if (size == 0) {
		size = 1;
	}
	return HeapAlloc(minicrt_heap_handle(), 0, size);
}

void *calloc(size_t count, size_t size)
{
	size_t total = count * size;
	if (count != 0 && total / count != size) {
		return NULL;
	}
	if (total == 0) {
		total = 1;
	}
	return HeapAlloc(minicrt_heap_handle(), HEAP_ZERO_MEMORY, total);
}

void *realloc(void *ptr, size_t size)
{
	if (!ptr) {
		return malloc(size);
	}
	if (size == 0) {
		HeapFree(minicrt_heap_handle(), 0, ptr);
		return NULL;
	}
	return HeapReAlloc(minicrt_heap_handle(), 0, ptr, size);
}

void free(void *ptr)
{
	if (!ptr) {
		return;
	}
	HeapFree(minicrt_heap_handle(), 0, ptr);
}

void *_aligned_malloc(size_t size, size_t alignment)
{
	uintptr_t raw;
	uintptr_t aligned;
	void *base;
	size_t total;

	if (alignment < sizeof(void *)) {
		alignment = sizeof(void *);
	}
	if ((alignment & (alignment - 1)) != 0) {
		return NULL;
	}

	total = size + alignment - 1 + sizeof(void *);
	base = malloc(total);
	if (!base) {
		return NULL;
	}

	raw = (uintptr_t)base + sizeof(void *);
	aligned = (raw + (alignment - 1)) & ~(uintptr_t)(alignment - 1);
	((void **)aligned)[-1] = base;
	return (void *)aligned;
}

void _aligned_free(void *ptr)
{
	if (!ptr) {
		return;
	}
	free(((void **)ptr)[-1]);
}

void *aligned_alloc(size_t alignment, size_t size)
{
	if (alignment == 0 || (size % alignment) != 0) {
		return NULL;
	}
	return _aligned_malloc(size, alignment);
}

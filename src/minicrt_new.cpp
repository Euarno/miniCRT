#include <new>
#include <stddef.h>

extern "C" void *malloc(size_t size);
extern "C" void free(void *ptr);

void *operator new(size_t size) noexcept
{
	return malloc(size);
}

void *operator new[](size_t size) noexcept
{
	return malloc(size);
}

void operator delete(void *ptr) noexcept
{
	free(ptr);
}

void operator delete[](void *ptr) noexcept
{
	free(ptr);
}

void *operator new(size_t size, const std::nothrow_t &) noexcept
{
	return malloc(size);
}

void *operator new[](size_t size, const std::nothrow_t &) noexcept
{
	return malloc(size);
}

void operator delete(void *ptr, const std::nothrow_t &) noexcept
{
	free(ptr);
}

void operator delete[](void *ptr, const std::nothrow_t &) noexcept
{
	free(ptr);
}

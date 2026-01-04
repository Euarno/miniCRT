#include <stddef.h>
#include <stdint.h>

#ifdef _MSC_VER
#include <intrin.h>
#endif

void *memcpy(void *dest, const void *src, size_t count)
{
#ifdef _MSC_VER
	if (count) {
		__movsb((unsigned char *)dest, (const unsigned char *)src, count);
	}
	return dest;
#else
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;
	for (size_t i = 0; i < count; ++i) {
		d[i] = s[i];
	}
	return dest;
#endif
}

void *memmove(void *dest, const void *src, size_t count)
{
	if (dest == src || count == 0) {
		return dest;
	}
	if (dest < src) {
		return memcpy(dest, src, count);
	}

	unsigned char *d = (unsigned char *)dest + count;
	const unsigned char *s = (const unsigned char *)src + count;
	while (count--) {
		*--d = *--s;
	}
	return dest;
}

void *memset(void *dest, int c, size_t count)
{
#ifdef _MSC_VER
	if (count) {
		__stosb((unsigned char *)dest, (unsigned char)c, count);
	}
	return dest;
#else
	unsigned char *d = (unsigned char *)dest;
	for (size_t i = 0; i < count; ++i) {
		d[i] = (unsigned char)c;
	}
	return dest;
#endif
}

int memcmp(const void *buf1, const void *buf2, size_t count)
{
	const unsigned char *a = (const unsigned char *)buf1;
	const unsigned char *b = (const unsigned char *)buf2;
	for (size_t i = 0; i < count; ++i) {
		if (a[i] != b[i]) {
			return (int)a[i] - (int)b[i];
		}
	}
	return 0;
}

#include <stddef.h>

static int minicrt_tolower(int c)
{
	if (c >= 'A' && c <= 'Z') {
		return c + ('a' - 'A');
	}
	return c;
}

size_t strlen(const char *str)
{
	const char *s = str;
	while (*s) {
		++s;
	}
	return (size_t)(s - str);
}

int strcmp(const char *a, const char *b)
{
	while (*a && (*a == *b)) {
		++a;
		++b;
	}
	return (unsigned char)*a - (unsigned char)*b;
}

int strncmp(const char *a, const char *b, size_t n)
{
	while (n && *a && (*a == *b)) {
		++a;
		++b;
		--n;
	}
	if (n == 0) {
		return 0;
	}
	return (unsigned char)*a - (unsigned char)*b;
}

char *strcpy(char *dest, const char *src)
{
	char *out = dest;
	while ((*out++ = *src++) != '\0') {
	}
	return dest;
}

char *strncpy(char *dest, const char *src, size_t n)
{
	size_t i = 0;
	for (; i < n && src[i]; ++i) {
		dest[i] = src[i];
	}
	for (; i < n; ++i) {
		dest[i] = '\0';
	}
	return dest;
}

char *strcat(char *dest, const char *src)
{
	char *out = dest + strlen(dest);
	while ((*out++ = *src++) != '\0') {
	}
	return dest;
}

char *strncat(char *dest, const char *src, size_t n)
{
	char *out = dest + strlen(dest);
	while (n && *src) {
		*out++ = *src++;
		--n;
	}
	*out = '\0';
	return dest;
}

char *strchr(const char *str, int c)
{
	char ch = (char)c;
	while (*str) {
		if (*str == ch) {
			return (char *)str;
		}
		++str;
	}
	return ch == '\0' ? (char *)str : NULL;
}

char *strrchr(const char *str, int c)
{
	char ch = (char)c;
	const char *last = NULL;
	while (*str) {
		if (*str == ch) {
			last = str;
		}
		++str;
	}
	if (ch == '\0') {
		return (char *)str;
	}
	return (char *)last;
}

char *strstr(const char *haystack, const char *needle)
{
	size_t needle_len = strlen(needle);
	if (needle_len == 0) {
		return (char *)haystack;
	}
	for (; *haystack; ++haystack) {
		if (*haystack == *needle && strncmp(haystack, needle, needle_len) == 0) {
			return (char *)haystack;
		}
	}
	return NULL;
}

int _stricmp(const char *a, const char *b)
{
	while (*a && *b) {
		int ca = minicrt_tolower((unsigned char)*a);
		int cb = minicrt_tolower((unsigned char)*b);
		if (ca != cb) {
			return ca - cb;
		}
		++a;
		++b;
	}
	return minicrt_tolower((unsigned char)*a) - minicrt_tolower((unsigned char)*b);
}

int _strnicmp(const char *a, const char *b, size_t n)
{
	while (n && *a && *b) {
		int ca = minicrt_tolower((unsigned char)*a);
		int cb = minicrt_tolower((unsigned char)*b);
		if (ca != cb) {
			return ca - cb;
		}
		++a;
		++b;
		--n;
	}
	if (n == 0) {
		return 0;
	}
	return minicrt_tolower((unsigned char)*a) - minicrt_tolower((unsigned char)*b);
}

int stricmp(const char *a, const char *b)
{
	return _stricmp(a, b);
}

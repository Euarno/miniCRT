#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

#define STB_SPRINTF_IMPLEMENTATION
#include "vendor/stb/stb_sprintf.h"

static int minicrt_clamp_count(size_t count)
{
	if (count > (size_t)INT_MAX) {
		return INT_MAX;
	}
	return (int)count;
}

int vsnprintf(char *buf, size_t count, const char *fmt, va_list va)
{
	return stbsp_vsnprintf(buf, minicrt_clamp_count(count), fmt, va);
}

int snprintf(char *buf, size_t count, const char *fmt, ...)
{
	int ret;
	va_list va;
	va_start(va, fmt);
	ret = vsnprintf(buf, count, fmt, va);
	va_end(va);
	return ret;
}

int vsprintf(char *buf, const char *fmt, va_list va)
{
	return stbsp_vsprintf(buf, fmt, va);
}

int sprintf(char *buf, const char *fmt, ...)
{
	int ret;
	va_list va;
	va_start(va, fmt);
	ret = vsprintf(buf, fmt, va);
	va_end(va);
	return ret;
}

int _snprintf(char *buf, size_t count, const char *fmt, ...)
{
	int ret;
	va_list va;
	va_start(va, fmt);
	ret = vsnprintf(buf, count, fmt, va);
	va_end(va);
	return ret;
}

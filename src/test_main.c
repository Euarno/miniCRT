#include <stddef.h>
#include <windows.h>

void *memcpy(void *dest, const void *src, size_t count);
int sprintf(char *buf, const char *fmt, ...);
float sinf(float x);
float cosf(float x);

static int test_mem(void)
{
	char src[16] = "minicrt";
	char dst[16] = {0};
	memcpy(dst, src, 8);
	return dst[0] == 'm' && dst[6] == 't';
}

static int test_printf(void)
{
	char buf[64];
	int n = sprintf(buf, "pow:%d", 7);
	return n > 0 && buf[0] == 'p';
}

static int test_math(void)
{
	float v = sinf(0.5f) + cosf(0.5f);
	return v != 0.0f;
}

int main(void)
{
	int ok = 1;
	ok &= test_mem();
	ok &= test_printf();
	ok &= test_math();

	MessageBoxA(NULL, ok ? "minicrt_test: OK" : "minicrt_test: FAIL", "minicrt_test", MB_OK | (ok ? MB_ICONINFORMATION : MB_ICONERROR));
	ExitProcess(ok ? 0 : 1);
	return 0;
}

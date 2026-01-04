#include <errno.h>

static int minicrt_errno_storage = 0;

int *_errno(void)
{
	return &minicrt_errno_storage;
}

void __set_errno(int value)
{
	minicrt_errno_storage = value;
}

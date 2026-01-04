#include <stdint.h>

#include "vendor/fdlibm/fdlibm.h"

struct exception;

double minicrt_nan(void)
{
	union {
		uint64_t u;
		double d;
	} v;
	v.u = 0x7ff8000000000000ULL;
	return v.d;
}

float minicrt_nanf(void)
{
	union {
		uint32_t u;
		float f;
	} v;
	v.u = 0x7fc00000u;
	return v.f;
}

int minicrt_isnan_double(double x)
{
	union {
		double d;
		uint64_t u;
	} v;
	v.d = x;
	return ((v.u & 0x7ff0000000000000ULL) == 0x7ff0000000000000ULL) &&
		((v.u & 0x000fffffffffffffULL) != 0);
}

int minicrt_isnan_float(float x)
{
	union {
		float f;
		uint32_t u;
	} v;
	v.f = x;
	return ((v.u & 0x7f800000u) == 0x7f800000u) &&
		((v.u & 0x007fffffu) != 0);
}

int minicrt_signbit_double(double x)
{
	union {
		double d;
		uint64_t u;
	} v;
	v.d = x;
	return (int)(v.u >> 63);
}

int minicrt_signbit_float(float x)
{
	union {
		float f;
		uint32_t u;
	} v;
	v.f = x;
	return (int)(v.u >> 31);
}

int minicrt_isfinite_double(double x)
{
	return !minicrt_isnan_double(x) && !minicrt_isinf_double(x);
}

int minicrt_isfinite_float(float x)
{
	return !minicrt_isnan_float(x) && !minicrt_isinf_float(x);
}

int minicrt_isinf_double(double x)
{
	union {
		double d;
		uint64_t u;
	} v;
	v.d = x;
	return (v.u & 0x7fffffffffffffffULL) == 0x7ff0000000000000ULL;
}

int minicrt_isinf_float(float x)
{
	union {
		float f;
		uint32_t u;
	} v;
	v.f = x;
	return (v.u & 0x7fffffffU) == 0x7f800000U;
}

int minicrt_isunordered_double(double x, double y)
{
	return minicrt_isnan_double(x) || minicrt_isnan_double(y);
}

int minicrt_isunordered_float(float x, float y)
{
	return minicrt_isnan_float(x) || minicrt_isnan_float(y);
}

int minicrt_isless_double(double x, double y)
{
	if (minicrt_isunordered_double(x, y)) {
		return 0;
	}
	return x < y;
}

int minicrt_isless_float(float x, float y)
{
	if (minicrt_isunordered_float(x, y)) {
		return 0;
	}
	return x < y;
}

int minicrt_islessequal_double(double x, double y)
{
	if (minicrt_isunordered_double(x, y)) {
		return 0;
	}
	return x <= y;
}

int minicrt_islessequal_float(float x, float y)
{
	if (minicrt_isunordered_float(x, y)) {
		return 0;
	}
	return x <= y;
}

int _dpcomp(double x, double y)
{
	if (minicrt_isunordered_double(x, y)) {
		return 0;
	}
	if (x < y) {
		return 1;
	}
	if (x > y) {
		return 4;
	}
	return 2;
}

int _fdpcomp(float x, float y)
{
	if (minicrt_isunordered_float(x, y)) {
		return 0;
	}
	if (x < y) {
		return 1;
	}
	if (x > y) {
		return 4;
	}
	return 2;
}

int __finite(double x)
{
	return minicrt_isfinite_double(x);
}

int __finitef(float x)
{
	return minicrt_isfinite_float(x);
}

int __isinf(double x)
{
	return minicrt_isinf_double(x);
}

int __isinff(float x)
{
	return minicrt_isinf_float(x);
}

#ifdef issignaling
#undef issignaling
#endif
#ifdef issignalingf
#undef issignalingf
#endif

int issignalingf(float x)
{
	(void)x;
	return 0;
}

int issignaling(double x)
{
	(void)x;
	return 0;
}

int __issignalingf(float x)
{
	(void)x;
	return 0;
}

int __issignaling(double x)
{
	(void)x;
	return 0;
}

int fegetround(void)
{
	return 0;
}

int fesetround(int mode)
{
	(void)mode;
	return 0;
}

double __kernel_standard(double x, double y, double retval, enum matherr type)
{
	(void)x;
	(void)y;
	(void)type;
	return retval;
}

float __kernel_standard_f(float x, float y, float retval, enum matherr type)
{
	(void)x;
	(void)y;
	(void)type;
	return retval;
}

int minicrt_matherr(struct exception *exc)
{
	(void)exc;
	return 0;
}

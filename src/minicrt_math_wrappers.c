#include <stddef.h>

double __sin(double x);
double __cos(double x);
double __tan(double x);
double __atan2(double y, double x);
double __sqrt(double x);
double __fabs(double x);
double fdlibm__floor(double x);
double fdlibm__ceil(double x);
double __fmod(double x, double y);
double __pow(double x, double y);
double __exp(double x);
double __log(double x);
double fdlibm__copysign(double x, double y);

float __sinf(float x);
float __cosf(float x);
float __tanf(float x);
float __atan2f(float y, float x);
float __sqrtf(float x);
float __fabsf(float x);
float fdlibm__floorf(float x);
float fdlibm__ceilf(float x);
float __fmodf(float x, float y);
float __powf(float x, float y);
float __expf(float x);
float __logf(float x);
float fdlibm__copysignf(float x, float y);

double sin(double x)
{
	return __sin(x);
}

double cos(double x)
{
	return __cos(x);
}

double tan(double x)
{
	return __tan(x);
}

double atan2(double y, double x)
{
	return __atan2(y, x);
}

double sqrt(double x)
{
	return __sqrt(x);
}

double fabs(double x)
{
	return __fabs(x);
}

double floor(double x)
{
	return fdlibm__floor(x);
}

double ceil(double x)
{
	return fdlibm__ceil(x);
}

double fmod(double x, double y)
{
	return __fmod(x, y);
}

double pow(double x, double y)
{
	return __pow(x, y);
}

double exp(double x)
{
	return __exp(x);
}

double log(double x)
{
	return __log(x);
}

double copysign(double x, double y)
{
	return fdlibm__copysign(x, y);
}

double _copysign(double x, double y)
{
	return fdlibm__copysign(x, y);
}

float sinf(float x)
{
	return __sinf(x);
}

float cosf(float x)
{
	return __cosf(x);
}

float tanf(float x)
{
	return __tanf(x);
}

float atan2f(float y, float x)
{
	return __atan2f(y, x);
}

float sqrtf(float x)
{
	return __sqrtf(x);
}

float fabsf(float x)
{
	return __fabsf(x);
}

float floorf(float x)
{
	return fdlibm__floorf(x);
}

float ceilf(float x)
{
	return fdlibm__ceilf(x);
}

float fmodf(float x, float y)
{
	return __fmodf(x, y);
}

float powf(float x, float y)
{
	return __powf(x, y);
}

float expf(float x)
{
	return __expf(x);
}

float logf(float x)
{
	return __logf(x);
}

float copysignf(float x, float y)
{
	return fdlibm__copysignf(x, y);
}

float _copysignf(float x, float y)
{
	return fdlibm__copysignf(x, y);
}

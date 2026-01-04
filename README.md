# miniCRT

Lightweight Windows CRT replacement focused on reverse-engineering tools and minimal GUI usage.  
This project implements a small C runtime layer, a minimal math stack, and fast string/memory routines without linking against the default CRT.

## Overview
- Custom memory allocation and `new/delete`
- Minimal libc string/memory utilities
- Lightweight `printf`/`snprintf` formatting
- Math functions backed by fdlibm (subset)
- Windows-only build, optimized for small runtime dependencies

## Project Layout
```
miniCRT/
  CMakeLists.txt
  src/
    CMakeLists.txt
    minicrt_alloc.c
    minicrt_errno.c
    minicrt_fltused.c
    minicrt_math_support.c
    minicrt_math_wrappers.c
    minicrt_mem.c
    minicrt_new.cpp
    minicrt_printf.c
    minicrt_string.c
    test_main.c
    vendor/
      fdlibm/
      musl/
      stb/
```

## Build & Test
```powershell
cmake -S C:\Users\Euarno\Desktop\miniCRT -B C:\Users\Euarno\Desktop\miniCRT\build
cmake --build C:\Users\Euarno\Desktop\miniCRT\build --config Release --target minicrt_test
```

Run the test executable:
```powershell
C:\Users\Euarno\Desktop\miniCRT\build\src\Release\minicrt_test.exe
```
It shows a MessageBox with OK/FAIL and returns 0 on success.

## Third-Party Code (Copied In-Tree)
- **stb_sprintf** (formatting): `src/vendor/stb/stb_sprintf.h`
- **fdlibm** (math subset): `src/vendor/fdlibm/`
- **musl** (memcpy/memmove/memset/memcmp): `src/vendor/musl/`

Licenses are included in the original upstream repositories; keep notice blocks in the copied files.

set(MINICRT_SOURCES
    minicrt_alloc.c
    minicrt_errno.c
    minicrt_fltused.c
    minicrt_math_support.c
    minicrt_math_wrappers.c
    minicrt_printf.c
    minicrt_string.c
    minicrt_new.cpp
    vendor/fdlibm/e_atan2.c
    vendor/fdlibm/e_atan2f.c
    vendor/fdlibm/e_exp.c
    vendor/fdlibm/e_expf.c
    vendor/fdlibm/e_fmod.c
    vendor/fdlibm/e_fmodf.c
    vendor/fdlibm/e_log.c
    vendor/fdlibm/e_logf.c
    vendor/fdlibm/e_pow.c
    vendor/fdlibm/e_powf.c
    vendor/fdlibm/e_rem_pio2.c
    vendor/fdlibm/e_rem_pio2f.c
    vendor/fdlibm/e_sqrt.c
    vendor/fdlibm/e_sqrtf.c
    vendor/fdlibm/k_cos.c
    vendor/fdlibm/k_cosf.c
    vendor/fdlibm/k_rem_pio2.c
    vendor/fdlibm/k_rem_pio2f.c
    vendor/fdlibm/k_sin.c
    vendor/fdlibm/k_sinf.c
    vendor/fdlibm/k_tan.c
    vendor/fdlibm/k_tanf.c
    vendor/fdlibm/s_atan.c
    vendor/fdlibm/s_atanf.c
    vendor/fdlibm/s_ceil.c
    vendor/fdlibm/s_ceilf.c
    vendor/fdlibm/s_copysign.c
    vendor/fdlibm/s_copysignf.c
    vendor/fdlibm/s_cos.c
    vendor/fdlibm/s_cosf.c
    vendor/fdlibm/s_fabs.c
    vendor/fdlibm/s_fabsf.c
    vendor/fdlibm/s_floor.c
    vendor/fdlibm/s_floorf.c
    vendor/fdlibm/s_scalbn.c
    vendor/fdlibm/s_scalbnf.c
    vendor/fdlibm/s_sin.c
    vendor/fdlibm/s_sinf.c
    vendor/fdlibm/s_tan.c
    vendor/fdlibm/s_tanf.c
    vendor/musl/memcpy.c
    vendor/musl/memmove.c
    vendor/musl/memset.c
    vendor/musl/memcmp.c
)

add_library(minicrt STATIC ${MINICRT_SOURCES})

target_include_directories(minicrt PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/fdlibm
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/musl
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb
)

if (MSVC)
    set_property(TARGET minicrt PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    target_compile_definitions(minicrt PRIVATE
        WIN32_LEAN_AND_MEAN
        UNICODE
        NOMINMAX
        _CRT_SECURE_NO_WARNINGS
    )
    target_compile_options(minicrt PRIVATE
        /EHsc
        /O1
        /GR-
        /Gw
        /Gy
        /fp:fast
        /permissive-
        /MP
        /sdl-
        /GS-
        /Zc:threadSafeInit-
    )
endif()

add_executable(minicrt_test
    test_main.c
)

target_link_libraries(minicrt_test PRIVATE minicrt)
if (MSVC)
    target_link_libraries(minicrt_test PRIVATE kernel32)
endif()

if (MSVC)
    set_property(TARGET minicrt_test PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    target_compile_definitions(minicrt_test PRIVATE
        WIN32_LEAN_AND_MEAN
        UNICODE
        NOMINMAX
        _CRT_SECURE_NO_WARNINGS
    )
    target_compile_options(minicrt_test PRIVATE
        /EHsc
        /O1
        /GR-
        /Gw
        /Gy
        /fp:fast
        /permissive-
        /MP
        /sdl-
        /GS-
        /Zc:threadSafeInit-
    )

    set(MINICRT_ENTRY "main" CACHE STRING "Entry point symbol for test executable")
    target_link_options(minicrt_test PRIVATE
        /NODEFAULTLIB
        "/ENTRY:${MINICRT_ENTRY}"
        $<$<CONFIG:Debug>:/DEBUG:FASTLINK>
        $<$<CONFIG:Release>:/DEBUG:NONE>
        /LTCG
        /OPT:REF
        /OPT:ICF
        /INCREMENTAL:NO
    )
endif()

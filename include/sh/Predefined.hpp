#pragma once

#ifdef _WIN32
#	define SH_WINDOWS
#endif

#if defined(_M_IX86) || defined(__i386) || defined(_X86_) || defined(__X86__) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386)
#	define SH_X86
#endif

#if defined(_M_X64) || defined(__amd64)
#	ifndef SH_X86
#		define SH_X86
#	endif
#	define SH_X64
#endif

#if defined(SH_WINDOWS) || defined(SH_X86)
#	define SH_LITTLE
#endif

#if defined(_MSC_VER)
#	define SH_MSVC
#elif defined(__GNUC__)
#	define SH_GCC
#elif defined(__clang__)
#	define SH_CLANG
#endif
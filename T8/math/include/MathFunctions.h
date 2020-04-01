#ifndef __MATHFUNCTIONS_H__
#define __MATHFUNCTIONS_H__

/**
 *  on Windows you have to tell the compiler/linker, which symbols
 *  should be exported from a DLL. There is a Microsoft extension to C++ 
 *  using a declspec(export) and declspec(import) prefix for DLL functions.
 *  There's another possibility to use a so-called .def-file to tell the 
 *  compiler, which symbols to export. If you have not told the compiler 
 *  using one of the two ways, no symbols are exported and thus no .lib
 *  file generated.  What I did looks roughly as follows:
 */

#ifdef WIN32
#ifdef Base_EXPORTS
#define SPCK_BASE_EXPORT __declspec(dllexport)
#else
#define SPCK_BASE_EXPORT __declspec(dllimport)
#endif
#else
#define SPCK_BASE_EXPORT
#endif

/**
 * class SPCK_BASE_EXPORT Transformer
 * {
 * };
 */

/**
 * power - Calculate the power of number.
 * @param base: Base value.
 * @param exponent: Exponent value.
 *
 * @return base raised to the power exponent.
 */
SPCK_BASE_EXPORT double power(double base, int exponent);

#endif
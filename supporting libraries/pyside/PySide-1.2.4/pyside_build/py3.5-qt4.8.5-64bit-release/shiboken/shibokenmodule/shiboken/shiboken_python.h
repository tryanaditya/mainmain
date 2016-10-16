

#ifndef SBK_SHIBOKEN_PYTHON_H
#define SBK_SHIBOKEN_PYTHON_H

#include <sbkpython.h>
#include <conversions.h>
#include <sbkenum.h>
#include <basewrapper.h>
#include <bindingmanager.h>
#include <memory>

// Binded library includes
// Conversion Includes - Primitive Types

// Type indices
#define                                       SBK_shiboken_IDX_COUNT 0

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkshibokenTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkshibokenTypeConverters;

// Converter indices
#define                            SBK_shiboken_CONVERTERS_IDX_COUNT 1

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T

} // namespace Shiboken

#endif // SBK_SHIBOKEN_PYTHON_H


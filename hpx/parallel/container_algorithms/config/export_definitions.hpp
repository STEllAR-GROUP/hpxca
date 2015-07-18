//  Copyright (c) 2015 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPXCA_CONFIG_EXPORT_DEFINITIONS)
#define HPXCA_CONFIG_EXPORT_DEFINITIONS

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
# define HPXCA_SYMBOL_EXPORT      __declspec(dllexport)
# define HPXCA_SYMBOL_IMPORT      __declspec(dllimport)
# define HPXCA_SYMBOL_INTERNAL    /* empty */
# define HPXCA_APISYMBOL_EXPORT   __declspec(dllexport)
# define HPXCA_APISYMBOL_IMPORT   __declspec(dllimport)
#else
# define HPXCA_SYMBOL_EXPORT      __attribute__((visibility("default")))
# define HPXCA_SYMBOL_IMPORT      __attribute__((visibility("default")))
# define HPXCA_SYMBOL_INTERNAL    __attribute__((visibility("hidden")))
# define HPXCA_APISYMBOL_EXPORT   __attribute__((visibility("default")))
# define HPXCA_APISYMBOL_IMPORT   __attribute__((visibility("default")))
#endif

// make sure we have reasonable defaults
#if !defined(HPXCA_SYMBOL_EXPORT)
# define HPXCA_SYMBOL_EXPORT      /* empty */
#endif
#if !defined(HPXCA_SYMBOL_IMPORT)
# define HPXCA_SYMBOL_IMPORT      /* empty */
#endif
#if !defined(HPXCA_SYMBOL_INTERNAL)
# define HPXCA_SYMBOL_INTERNAL    /* empty */
#endif
#if !defined(HPXCA_APISYMBOL_EXPORT)
# define HPXCA_APISYMBOL_EXPORT   /* empty */
#endif
#if !defined(HPXCA_APISYMBOL_IMPORT)
# define HPXCA_APISYMBOL_IMPORT   /* empty */
#endif

///////////////////////////////////////////////////////////////////////////////
// define the export/import helper macros used by the core library
#if defined(HPXCA_EXPORTS)
# define  HPXCA_EXPORT             HPXCA_SYMBOL_EXPORT
# define  HPXCA_EXCEPTION_EXPORT   HPXCA_SYMBOL_EXPORT
# define  HPXCA_API_EXPORT         HPXCA_APISYMBOL_EXPORT
#else
# define  HPXCA_EXPORT             HPXCA_SYMBOL_IMPORT
# define  HPXCA_EXCEPTION_EXPORT   HPXCA_SYMBOL_IMPORT
# define  HPXCA_API_EXPORT         HPXCA_APISYMBOL_IMPORT
#endif

///////////////////////////////////////////////////////////////////////////////
// define the export/import helper macros used by applications
#if defined(HPXCA_APPLICATION_EXPORTS)
# define  HPXCA_APPLICATION_EXPORT HPXCA_SYMBOL_EXPORT
#else
# define  HPXCA_APPLICATION_EXPORT HPXCA_SYMBOL_IMPORT
#endif

///////////////////////////////////////////////////////////////////////////////
// define the export/import helper macros for exceptions
#if defined(HPXCA_EXPORTS)
# define HPXCA_ALWAYS_EXPORT       HPXCA_SYMBOL_EXPORT
#else
# define HPXCA_ALWAYS_EXPORT       HPXCA_SYMBOL_IMPORT
#endif

#endif

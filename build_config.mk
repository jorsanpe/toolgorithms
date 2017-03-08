TARGET := bin/toolgos.a

# non-recursive list of source paths
SOURCE_PATHS += src

# non-recursive list of include paths
INCLUDE_PATHS += include

# External libraries to be linked
LIBRARIES +=

# Library search paths
LIBRARY_PATHS +=

# Symbols to be defined
SYMBOLS += _XOPEN_SOURCE _GNU_SOURCE NOOPT

# Files to be excluded from the compilation
EXCLUDED_FILES +=

# Compiler flags for specific files
# <filename> = flags

CFLAGS += -Wno-deprecated-declarations --include stdbool.h

LDFLAGS +=


# In a project file, variables are used to hold lists of strings. In the simplest projects, these variables inform qmake about the configuration options to use, or supply filenames and paths to use in the build process.
# qmake looks for certain variables in each project file, and it uses the contents of these to determine what it should write to a Makefile.
# The contents of a variable can be read by prepending the variable name with $$. This can be used to assign the contents of one variable to another.
# Normally, variables are used to contain whitespace-separated lists of values. However, it is sometimes necessary to specify values containing spaces. These must be quoted by using double quotes.
# The quoted text is treated as a single item in the list of values held by the variable. A similar approach is used to deal with paths that contain spaces.
# To include the # character in variable assignments, it is necessary to use the contents of the built-in LITERAL_HASH variable.

# The = operator assigns a value to a variable, replacing its previous value (if existing)
# The += operator appends a new value to the list of values in a variable
# The *= operator adds a value to the list of values in a variable, but only if it is not already present. This prevents values from being included many times in a variable.
# The ~= operator replaces any values that match a regular expression with the specified value
# The -= operator removes a value from the list of values in a variable


# Increase compilation speed (needs ccache installed)
QMAKE_CXX = ccache g++

# Determines whether the output of the build process will be an application, a library, or a plugin
TEMPLATE = app

# General project configuration options
CONFIG *= qt console thread exceptions c++11

# Qt-specific configuration options : required modules
QT *= core gui quick qml sql widgets printsupport

# QStringBuilder uses expression templates and reimplements the '%' operator so that when you use '%' for string concatenation instead of '+', multiple substring concatenations will be postponed until the final result is about to be assigned to a QString. Let '+' automatically be performed as the QStringBuilder '%' everywhere.
DEFINES *= QT_USE_QSTRINGBUILDER
# Allows macro "DEBUG" when in debug mode (allowing conditional code)
Debug:DEFINES*=DEBUG

# Installation
# Installation path
#target.path =
# Name of the target (executable) file
#TARGET = PreCheck
# List of resources that will be installed when make install or a similar installation procedure is executed. Each item in the list is typically defined with attributes that provide information about where it will be installed.
# Note that qmake will skip files that are executable. If you need to install executable files, you can unset the files' executable flags.
#INSTALLS+=
# Directory in which the executable or binary file will be placed
#DESTDIR =
# App version
#VERSION


#DEFINES += QS_LOG_LINE_NUMBERS    # automatically writes the file and line for each log message
#DEFINES += QS_LOG_DISABLE         # logging code is replaced with a no-op
#DEFINES += QS_LOG_SEPARATE_THREAD # messages are queued and written from a separate thread

include(PreCheck.pri)

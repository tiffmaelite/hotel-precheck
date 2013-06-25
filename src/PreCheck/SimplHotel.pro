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
CONFIG *= qt testlib console thread exceptions c++11

# Qt-specific configuration options : required modules
QT *= core gui quick qml sql widgets printsupport concurrent

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

include(PreCheck.pri)
#include(../../libs/QsLog_2.0.b1/QsLog.pri)
include(../../libs/tgrinwis-QsLog/QsLog/QsLog.pri)
include(../../libs/razvanpetruQs/QsLog/QsLog.pri)
include(../../libs/QtSignalsTools.pri)
include(../../libs/QsTools.pri)
include(../../libs/QsWidgets.pri)
include(../../libs/QtSignalGuard.pri)
include(../../libs/QtTestUtils.pri)


OTHER_FILES *= \
	../Database/PreCheckDB.fbd \
	../Database/dbInitScript.sql \
	../Database/4_dbCrea_procedures.sql \
	../Database/3_dbCrea_View_ServicesInfos.sql \
	../Database/3_dbCrea_View_RoomsInfos.sql \
	../Database/3_dbCrea_View_BillingsInfos.sql \
	../Database/2_dbCrea_constraints.sql \
	../Database/1_dbCrea_Users.sql \
	../Database/1_dbCrea_Trainees.sql \
	../Database/1_dbCrea_Taxes.sql \
	../Database/1_dbCrea_ServicesTypes.sql \
	../Database/1_dbCrea_ServicesFields.sql \
	../Database/1_dbCrea_ServicesFamilies.sql \
	../Database/1_dbCrea_ServicesDetails.sql \
	../Database/1_dbCrea_Services.sql \
	../Database/1_dbCrea_RoomsTypes.sql \
	../Database/1_dbCrea_Rooms.sql \
	../Database/1_dbCrea_Reports.sql \
	../Database/1_dbCrea_Nationalities.sql \
	../Database/1_dbCrea_Groups.sql \
	../Database/1_dbCrea_Clients.sql \
	../Database/1_dbCrea_ChargedServices.sql \
	../Database/1_dbCrea_Bookings.sql \
	../Database/1_dbCrea_BillsTypes.sql \
	../Database/1_dbCrea_Bills.sql \
	../Database/1_dbCrea_BillingsTypes.sql \
	../Database/1_dbCrea_BillingsGroups.sql \
	../Database/1_dbCrea_BillingsClients.sql \
	../Database/1_dbCrea_Billings.sql \
	../Database/1_dbCrea_BalanceLog.sql \
	../Database/1_dbCrea_Addresses.sql \
	../Database/0_dbCrea_general.sql \
	../Database/install_script.sh \
	../Database/PreCheckCreaError.log \
	../Database/PreCheckCrea.log

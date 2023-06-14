#############################################################################
# Makefile for building: http_req
# Generated by qmake (2.01a) (Qt 4.7.4) on: Wed Jun 14 19:32:31 2023
# Project:  http_req.pro
# Template: app
# Command: /home/mpw/QtSDK/Simulator/Qt/gcc/bin/qmake -spec ../../../../QtSDK/Simulator/Qt/gcc/mkspecs/linux-g++ -o Makefile http_req.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_DECLARATIVE_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../../../QtSDK/Simulator/Qt/gcc/mkspecs/linux-g++ -I. -I../../../../QtSDK/Simulator/Qt/gcc/include/QtCore -I../../../../QtSDK/Simulator/Qt/gcc/include/QtNetwork -I../../../../QtSDK/Simulator/Qt/gcc/include/QtGui -I../../../../QtSDK/Simulator/Qt/gcc/include/QtDeclarative -I../../../../QtSDK/Simulator/Qt/gcc/include -Isrc/qmlapplicationviewer -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/home/mpw/QtSDK/Simulator/Qt/gcc/lib
LIBS          = $(SUBLIBS)  -L/home/mpw/QtSDK/Simulator/Qt/gcc/lib -lQtDeclarative -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/mpw/QtSDK/Simulator/Qt/gcc/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/main.cpp \
		src/networkmanager.cpp \
		src/buttonmanager.cpp \
		src/qmlapplicationviewer/qmlapplicationviewer.cpp moc_qmlapplicationviewer.cpp \
		moc_networkmanager.cpp \
		moc_buttonmanager.cpp
OBJECTS       = main.o \
		networkmanager.o \
		buttonmanager.o \
		qmlapplicationviewer.o \
		moc_qmlapplicationviewer.o \
		moc_networkmanager.o \
		moc_buttonmanager.o
DIST          = ../../../../QtSDK/Simulator/Qt/gcc/mkspecs/common/g++.conf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/common/unix.conf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/common/linux.conf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/qconfig.pri \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/qt_functions.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/qt_config.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/exclusive_builds.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/default_pre.prf \
		src/qmlapplicationviewer/qmlapplicationviewer.pri \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/release.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/default_post.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/warn_on.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/qt.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/unix/thread.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/moc.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/resources.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/uic.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/yacc.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/lex.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/include_source_dir.prf \
		http_req.pro
QMAKE_TARGET  = http_req
DESTDIR       = 
TARGET        = http_req

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: http_req.pro  ../../../../QtSDK/Simulator/Qt/gcc/mkspecs/linux-g++/qmake.conf ../../../../QtSDK/Simulator/Qt/gcc/mkspecs/common/g++.conf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/common/unix.conf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/common/linux.conf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/qconfig.pri \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/qt_functions.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/qt_config.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/exclusive_builds.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/default_pre.prf \
		src/qmlapplicationviewer/qmlapplicationviewer.pri \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/release.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/default_post.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/warn_on.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/qt.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/unix/thread.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/moc.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/resources.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/uic.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/yacc.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/lex.prf \
		../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/include_source_dir.prf
	$(QMAKE) -spec ../../../../QtSDK/Simulator/Qt/gcc/mkspecs/linux-g++ -o Makefile http_req.pro
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/common/g++.conf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/common/unix.conf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/common/linux.conf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/qconfig.pri:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/modules/qt_webkit_version.pri:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/qt_functions.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/qt_config.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/exclusive_builds.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/default_pre.prf:
src/qmlapplicationviewer/qmlapplicationviewer.pri:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/release.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/default_post.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/warn_on.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/qt.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/unix/thread.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/moc.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/resources.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/uic.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/yacc.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/lex.prf:
../../../../QtSDK/Simulator/Qt/gcc/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -spec ../../../../QtSDK/Simulator/Qt/gcc/mkspecs/linux-g++ -o Makefile http_req.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/http_req1.0.0 || $(MKDIR) .tmp/http_req1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/http_req1.0.0/ && $(COPY_FILE) --parents src/qmlapplicationviewer/qmlapplicationviewer.h src/networkmanager.h src/buttonmanager.h .tmp/http_req1.0.0/ && $(COPY_FILE) --parents src/main.cpp src/networkmanager.cpp src/buttonmanager.cpp src/qmlapplicationviewer/qmlapplicationviewer.cpp .tmp/http_req1.0.0/ && (cd `dirname .tmp/http_req1.0.0` && $(TAR) http_req1.0.0.tar http_req1.0.0 && $(COMPRESS) http_req1.0.0.tar) && $(MOVE) `dirname .tmp/http_req1.0.0`/http_req1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/http_req1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


first: $(first) copydeploymentfolders

copydeploymentfolders:
	@echo Copying application data... && $(MKDIR) "/home/mpw/projects/nokian9/apps/http-req/qml" && $(COPY_DIR) "/home/mpw/projects/nokian9/apps/http-req/src/qml/http_req" "/home/mpw/projects/nokian9/apps/http-req/qml"

check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_qmlapplicationviewer.cpp moc_networkmanager.cpp moc_buttonmanager.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_qmlapplicationviewer.cpp moc_networkmanager.cpp moc_buttonmanager.cpp
moc_qmlapplicationviewer.cpp: src/qmlapplicationviewer/qmlapplicationviewer.h
	/home/mpw/QtSDK/Simulator/Qt/gcc/bin/moc $(DEFINES) $(INCPATH) src/qmlapplicationviewer/qmlapplicationviewer.h -o moc_qmlapplicationviewer.cpp

moc_networkmanager.cpp: src/networkmanager.h
	/home/mpw/QtSDK/Simulator/Qt/gcc/bin/moc $(DEFINES) $(INCPATH) src/networkmanager.h -o moc_networkmanager.cpp

moc_buttonmanager.cpp: src/buttonmanager.h
	/home/mpw/QtSDK/Simulator/Qt/gcc/bin/moc $(DEFINES) $(INCPATH) src/buttonmanager.h -o moc_buttonmanager.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: src/main.cpp src/networkmanager.h \
		src/buttonmanager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o src/main.cpp

networkmanager.o: src/networkmanager.cpp src/networkmanager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o networkmanager.o src/networkmanager.cpp

buttonmanager.o: src/buttonmanager.cpp src/buttonmanager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o buttonmanager.o src/buttonmanager.cpp

qmlapplicationviewer.o: src/qmlapplicationviewer/qmlapplicationviewer.cpp src/qmlapplicationviewer/qmlapplicationviewer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qmlapplicationviewer.o src/qmlapplicationviewer/qmlapplicationviewer.cpp

moc_qmlapplicationviewer.o: moc_qmlapplicationviewer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qmlapplicationviewer.o moc_qmlapplicationviewer.cpp

moc_networkmanager.o: moc_networkmanager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_networkmanager.o moc_networkmanager.cpp

moc_buttonmanager.o: moc_buttonmanager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_buttonmanager.o moc_buttonmanager.cpp

####### Install

install_itemfolder_01: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/opt/http_req/qml/ || $(MKDIR) $(INSTALL_ROOT)/opt/http_req/qml/ 
	-$(INSTALL_DIR) /home/mpw/projects/nokian9/apps/http-req/src/qml/http_req $(INSTALL_ROOT)/opt/http_req/qml/


uninstall_itemfolder_01:  FORCE
	-$(DEL_FILE) -r $(INSTALL_ROOT)/opt/http_req/qml/http_req
	-$(DEL_DIR) $(INSTALL_ROOT)/opt/http_req/qml/ 


install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/opt/http_req/bin/ || $(MKDIR) $(INSTALL_ROOT)/opt/http_req/bin/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/opt/http_req/bin/$(QMAKE_TARGET)"
	-$(STRIP) "$(INSTALL_ROOT)/opt/http_req/bin/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/opt/http_req/bin/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/opt/http_req/bin/ 


install:  install_itemfolder_01 install_target  FORCE

uninstall: uninstall_itemfolder_01 uninstall_target   FORCE

FORCE:


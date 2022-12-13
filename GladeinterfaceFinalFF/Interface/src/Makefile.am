## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = interface

interface_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	connexion.c connexion.h \
	election.c election.h \
	lelectorale.c lelectorale.h \
	utilisateur.c utilisateur.h \
	bureauV.c bureauV.h \
	observateur.c observateur.h

interface_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)


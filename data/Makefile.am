AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(includedir) -I$(OFFLINE_MAIN)/include -I$(ROOTSYS)/include

SUBDIRS = 

lib_LTLIBRARIES = \
  libPHphnx.la

noinst_HEADERS = \
  PHphnxLinkDef.h

include_HEADERS = \
  phSubsysReco.h

libMXphnx_la_SOURCES = \
  phSubsysReco.cxx \
  PHphnx_Dict.C

libMXphnx_la_LIBADD = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib

# Rule for generating CINT dictionaries from class headers.
PHphnx_Dict.C: \
  phSubsysReco.h \
  PHphnxLinkDef.h
	rootcint -f $@ -c $(DEFAULT_INCLUDES) $(INCLUDES) $^

clean-local:
	rm -f *Dict*

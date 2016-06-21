all:	libPH.so

clean:
	rm libPH.so

libPH.so: PhotonEvent.o CNTE.o CNTDE.o EMCC.o PH_Dict.C
	 `root-config --cxx` -shared -WL,-soname,libPH.so `root-config --cflags --libs` $^ -o libPH.so 
	rm $^
	rm PH_Dict_rdict.pcm

PhotonEvent.o: PhotonEvent.cxx
	`root-config --cxx` `root-config --cflags --libs` -c $^

CNTE.o: CNTE.cxx
	`root-config --cxx` `root-config --cflags --libs` -c $^

CNTDE.o: CNTDE.cxx
	`root-config --cxx` `root-config --cflags --libs` -c $^

EMCC.o: EMCC.cxx
	`root-config --cxx` `root-config --cflags --libs` -c $^

PH_Dict.C: \
  PhotonEvent.h \
  CNTE.h \
  CNTDE.h \
  EMCC.h
	rootcint -f $@ -c `root-config --cflags` $^

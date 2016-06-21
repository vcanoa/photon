all:	libPH.so

clean:
	rm libPH.so

libPH.so: PhotonEvent.o CNTE.o CNTDE.o EMCC.o
	 `root-config --cxx` -shared -WL,-soname,libMX.so `root-config --cflags --libs` $^ -o libPH.so 
	rm $^

PhotonEvent.o: PhotonEvent.cxx
	`root-config --cxx` `root-config --cflags --libs` -c $^

CNTE.o: CNTE.cxx
	`root-config --cxx` `root-config --cflags --libs` -c $^

CNTDE.o: CNTDE.cxx
	`root-config --cxx` `root-config --cflags --libs` -c $^

EMCC.o: EMCC.cxx
	`root-config --cxx` `root-config --cflags --libs` -c $^

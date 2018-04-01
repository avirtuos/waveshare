CC=g++
DLIBS=-lwiringPi
epd:main.o epd7in5b.o imagedata.o epdif.o font8.o font12.o font16.o font20.o font24.o epd7in5bpaint.o
	$(CC) -Wall -o epd main.o epd7in5b.o imagedata.o epdif.o font8.o font12.o font16.o font20.o font24.o epd7in5bpaint.o $(DLIBS)
imagedata.o:imagedata.cpp imagedata.h 
	$(CC) -Wall -c imagedata.cpp $(DLIBS)
epd7in5b.o:epd7in5b.cpp epd7in5b.h
	$(CC) -Wall -c epd7in5b.cpp $(DLIBS)
epdif.o:epdif.cpp epdif.h
	$(CC) -Wall -c epdif.cpp $(DLIBS)
font8.o:fonts.h font8.c
	$(CC) -Wall -c font8.c
font12.o:fonts.h font12.c
	$(CC) -Wall -c font12.c
font16.o:fonts.h font16.c
	$(CC) -Wall -c font16.c
font20.o:fonts.h font20.c
	$(CC) -Wall -c font20.c
font24.o:fonts.h font24.c
	$(CC) -Wall -c font24.c
epd7in5bpaint.o:epd7in5bpaint.cpp epd7in5bpaint.h
	$(CC) -Wall -c epd7in5bpaint.cpp $(DLIBS)
main.o:main.cpp epd7in5b.h imagedata.h epd7in5bpaint.h
	$(CC) -Wall -c main.cpp $(DLIBS)
clean:
	rm imagedata.o main.o epd7in5b.o epdif.o font8.o font12.o font16.o font20.o font24.o epd7in5bpaint.o epd


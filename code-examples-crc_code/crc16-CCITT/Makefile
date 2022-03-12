# See README.txt.
objs_o = crc.o
objs_c = crc.c
flags = -std=gnu99 -Wall -s -D_WIN32_

all: test

clean:
	rm -f testcrc 
	rm -f *.o *.exe* *.exe*

objs: $(objs_c)
	gcc $(flags) -c $(objs_c)

test: testcrc.c objs
	gcc $(flags) $(objs_o) testcrc.c -o testcrc

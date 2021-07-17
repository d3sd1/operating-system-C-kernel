#,------.                    ,--.   ,--.       ,--.                           ,--.      |   | 
#|  .-.  \   ,---.  ,--,--,  |  | ,-'  '-.   ,-'  '-.  ,---.  ,--.,--.  ,---. |  ,---.  |  .' 
#|  |  \  : | .-. | |      \ `-'  '-.  .-'   '-.  .-' | .-. | |  ||  | | .--' |  .-.  | |  |  
#|  '--'  / ' '-' ' |  ||  |        |  |       |  |   ' '-' ' '  ''  ' \ `--. |  | |  | `--'  
#`-------'   `---'  `--''--'        `--'       `--'    `---'   `----'   `---' `--' `--' .--.  
# DON'T TOUCH ME NOW
# WOHOHOHOHOHOHOHOHO
# DON'T STOP ME NOW >> https://www.youtube.com/watch?v=HgzGwKwLmgM

CC=gcc

CFLAGS=-Wall -Werror


%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)


all:	cat size ls

	
cat:	mycat.o
	$(CC) $(CFLAGS) -o mycat  mycat.o 

size:	mysize.o
	$(CC) $(CFLAGS)  -o mysize  mysize.o

ls: 	myls.o
	$(CC) $(CFLAGS)  -o myls myls.o


clean:
	rm -f mycat myls mysize
	rm *.o

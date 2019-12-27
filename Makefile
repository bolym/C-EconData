

CC=g++
EXE_FILE=econData


$(EXE_FILE): econData.o econData.hpp browseEconData.cpp
	$(CC) econData.o browseEconData.cpp -std=c++11 -o $(EXE_FILE)

econData.o: econData.hpp econData.cpp
	$(CC) -c econData.cpp -std=c++11

clean:
	rm -f *.o $(EXE_FILE)


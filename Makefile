CC=g++
CFLAGS = -lcrypto  --std=c++11 -Wno-deprecated-declarations
EXEC=run
MAIN=src/main.cpp

main:src/main.cpp
	$(CC) $? $(CFLAGS) -o build/$(EXEC) 
run:
	build/$(EXEC)

clear:
	rm build/* 
CC=clang++
CFLAGS =-fopenmp -lcrypto -stdlib=libc++ --std=c++11 -Wno-deprecated-declarations -I/opt/homebrew/opt/openssl@3/include -L/opt/homebrew/opt/openssl@3/lib
EXEC=run
MAIN=src/main.cpp

main:src/main.cpp
	export LDFLAGS="-L/opt/homebrew/opt/libomp/lib"
	export CPPFLAGS="-I/opt/homebrew/opt/libomp/include"
	export LDFLAGS="-L/opt/homebrew/opt/llvm/lib"
	export CPPFLAGS="-I/opt/homebrew/opt/llvm/include"
	$(CC) $? $(CFLAGS) -o build/$(EXEC) 
run:
	build/$(EXEC)

clear:
	rm build/* 
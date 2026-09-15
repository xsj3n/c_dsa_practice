g++ -g -O0 -Wall -Wextra -fsanitize=address,undefined,signed-integer-overflow -fno-omit-frame-pointer -fpermissive main.c
./a.out

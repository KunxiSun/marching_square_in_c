#!/bin/bash

gcc -pthread ./src/test/multi-thread-test.c ./src/src/marching.c -o multi_thread_test -O0 -Wall -Werror -Werror=vla -g -std=gnu11 -lm -lpthread -fsanitize=address

./multi_thread_test
rm multi_thread_test
#!/bin/bash

gcc -pthread ./src/test/single-thread-test.c ./src/src/marching.c -o single_thread_test -O0 -Wall -Werror -Werror=vla -g -std=gnu11 -lm -lpthread -fsanitize=address

./single_thread_test
rm single_thread_test
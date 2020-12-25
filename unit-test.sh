#!/bin/bash

gcc ./src/test/unit-tests.c ./src/src/marching.c -o run_test

./run_test
rm run_test

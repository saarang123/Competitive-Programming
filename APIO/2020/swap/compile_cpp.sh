#!/bin/bash

problem=swap

g++ -std=c++17 -o "${problem}" "grader.cpp" "${problem}.cpp" -O2 -lm

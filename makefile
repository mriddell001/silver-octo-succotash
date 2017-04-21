# Makefile for captsone
#
# If this file is in the directory with your program, you can compile your
# program using the following command:
#
#   $ make
#
# When you are done with this assignment, delete all the files generated
# by the compiler (you can always recreate them if you need them)
#
#   $ make clean
#
# It is a good idea to understand how make works
#
# Commands all have the following format:
#    file_to_be_created: list_of_files_the_file_to_left_is_create_from
#    <tab>the command that generates this file
#
# Compiler options
#    the arguments after g++ specify specific options for the compiler
#    -Wall        ==> print all warnings
#    -pedantic    ==> print warnings when non-standard C++ is used
#    -g           ==> keep additional information to aid in debugging
#    -o           ==> specify the output filename
#    -c           ==> compile only (create a .o file)
sge: serial_gaussian_elimination.o
	gcc -std=c99 -Wall -pedantic -g -o sge serial_gaussian_elimination.o -lm

serial_gaussian_elimination.o: serial_gaussian_elimination.c
	gcc -std=c99 -Wall -pedantic -g -c serial_gaussian_elimination.c -lm

clean:
	rm -f sge sge.exe serial_gaussian_elimination.o

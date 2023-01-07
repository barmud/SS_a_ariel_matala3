C =gcc
AR = ar
FLAGS = -Wall -g

all: txtfind isort

txtfind: txtfind.c
	$(C) $(FLAGS) txtfind.c -o txtfind
	
isort: isort.c main.c
	$(C) $(FLAGS) isort.c main.c -o isort
clean:rm -rf *.o main txtfind isort

.phony: clean,all 
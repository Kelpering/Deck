.PHONY: all run compile clean

FILES := $(wildcard *.c)
SRC   := $(FILES:%.c=%)
EXEC  := $(wildcard *.out)

current_dir := $(notdir $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST))))))

all: quiet_compile run

run:
	@./${EXEC}
#	@echo Program ran successfully

quiet_compile:
	@gcc -o ${current_dir}.out ${FILES}

compile:
	@echo Compiling Source Files...
	@echo ${FILES}
	gcc -o ${current_dir}.out ${FILES}
#	@rm -rf ${SRC}.o

clean:
	@echo Removing Object and Executable files...
	@echo ${SRC}
	@rm -rvf *.out
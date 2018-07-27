all: hello unit-test

hello: hello.c
	gcc hello.c -o hello

unit-test:
	gcc unit_test.c -o unit-test

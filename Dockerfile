FROM gcc:4.9
COPY . /usr/src/hello
WORKDIR /usr/src/hello
RUN gcc -o hello hello.c
CMD ["./hello"]

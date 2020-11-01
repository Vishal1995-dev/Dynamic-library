# Dynamic-library
Creating shared object and using it dynamically

Run following commands:

1.gcc -c -fpic Library.c

2.gcc -shared -o Library.so Library.o

3.gcc Main.c -ldl

4../a.out

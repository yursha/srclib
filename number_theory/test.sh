set -e
clang -std=gnu17 test/*.c lib/*.c -o test.out && ./test.out


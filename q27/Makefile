CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99
PERF ?= perf stat --repeat 5 -e cache-misses,cache-references,instructions,cycles

EXEC = main
all: $(EXEC)

main: main.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

perf:
	$(PERF) ./main 2>&1 >/dev/null | grep "misses\|second" | awk '{print $$1}'

clean:
	$(RM) $(EXEC) *.o perf.*

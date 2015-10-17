CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99
PERF ?= perf stat --repeat 5 -e cache-misses,cache-references,instructions,cycles
CLEAN_CACHE ?= echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
INPUT ?= input.txt
CACHEMISSDATA ?= cachemiss.txt
CACHEMISSGRAPH ?= cachemiss.png
CACHEMISSTITLE ?= CacheMiss
TIMEDATA ?= time.txt
TIMEGRAPH ?= time.png
TIMETITLE ?= TimeElapse

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

gen: gen.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

plot: plot.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

runi:
	./iterative $(INPUT)

runr:
	./recursive $(INPUT)

rung:
	./gen > input.txt

runp:
	./plot $(CACHEMISSDATA) $(CACHEMISSGRAPH) $(CACHEMISSTITLE)
	./plot $(TIMEDATA) $(TIMEGRAPH) $(TIMETITLE)

perfi:
	$(PERF) ./iterative $(INPUT) >/dev/null

perfr:
	$(PERF) ./recursive $(INPUT) >/dev/null

ccache:
	$(CLEAN_CACHE)

clean:
	$(RM) $(EXEC) *.o perf.*

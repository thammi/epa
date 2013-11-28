# setup

BUILD_DIR=build
EXECUTABLE=graphstuff

CFLAGS=-c -Wall --std=c11 -g
LDFLAGS=

# find and calc some paths

SOURCES=$(wildcard src/*.c)
HEADERS=$(wildcard src/*.h)

OBJECTS=${SOURCES:src/%.c=${BUILD_DIR}/%.o}
EXEC_FILE=${EXECUTABLE:%=${BUILD_DIR}/%}

CSV=${BUILD_DIR}/benchmark.csv
PNG=${BUILD_DIR}/benchmark.png

# phony

all: plot

compile: ${OBJECT}

link: ${EXEC_FILE}

plot: ${PNG}

# actual work

clean:
	rm -rf ${BUILD_DIR}

${PNG}: ${CSV} benchmark.pg
	gnuplot benchmark.pg < $< > $@

${CSV}: ${EXEC_FILE}
	${EXEC_FILE} > $@

${EXEC_FILE}: ${OBJECTS}
	@mkdir -p `dirname $@`
	${CC} -o $@ ${OBJECTS} ${LDFLAGS}

${BUILD_DIR}/%.o: src/%.c ${HEADERS}
	@mkdir -p `dirname $@`
	${CC} ${CFLAGS} -o $@ $<


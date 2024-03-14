

OUT_DIR = build-local
DEFS = -DTEST -DBUILD_LOCAL
CFLAGS = -Wall -I. $(DEFS) -Ilibs/Unity/src -Isrc/mock-pico-stdlib
SRC = src

all: $(OUT_DIR)/leddriver-test 

test-leddriver: $(OUT_DIR)/leddriver-test
	$(OUT_DIR)/leddriver-test

test-interrupt: $(OUT_DIR)/interrupt-test
	$(OUT_DIR)/interrupt-test

test-all: test-leddriver test-interrupt

$(OUT_DIR)/leddriver-test: $(OUT_DIR)/unity.o $(OUT_DIR)/leddriver.o
	gcc $(CFLAGS) -o $@ $^ $(SRC)/leddriver/leddriver_test.c

$(OUT_DIR)/interrupt-test: $(OUT_DIR)/unity.o $(OUT_DIR)/interrupt.o
	gcc $(CFLAGS) -o $@ $^ $(SRC)/interrupt/interrupt_test.c

$(OUT_DIR)/leddriver.o: $(SRC)/leddriver/leddriver.c
	gcc $(CFLAGS) -c -o $@ $^

# $(OUT_DIR)/interrupt.o: $(SRC)/interrupt/interrupt.c
# 	gcc $(CFLAGS) -c -o $@ $^

$(OUT_DIR)/unity.o: $(OUT_DIR)
	gcc $(CFLAGS) -c -o $@ libs/Unity/src/unity.c

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR)

.PHONY: clean test-leddriver test-interrupt test-all
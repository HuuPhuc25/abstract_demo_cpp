CXX = g++
CFLAGS += -g -I/. -L/.

BIN=interface
SRCS=field.o tiny_int_field.o int_field.o big_int_field.o float_field.o date_field.o text_field.o nvar_char_field.o test_row.o main.o

%.o : %.cpp
	$(CXX) $< $(CFLAGS) -c -o $@

OBJS   = $(patsubst %.cpp,%.o,$(SRCS))

$(BIN): $(OBJS)
	$(CXX) $(OBJS) $(CFLAGS) -o $(BIN)

clean:
	@ rm $(SRCS) $(BIN)

all: $(BIN)
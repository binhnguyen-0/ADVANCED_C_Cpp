CC = gcc
CFLAGS = -std=c99 -Wall -Wextra
TARGET = main

# Danh sách các file nguồn
SRCS = main.c  csv_lib.c

# Tạo danh sách object từ SRCS
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Quy tắc chung để build .o từ .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

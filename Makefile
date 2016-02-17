TARGET = sampleFp16
SRCS   = main.cpp
OBJS   = $(SRCS:.cpp=.o)
CC     = g++

.PHONY: all clean
all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "LD    : " $@
	@$(CC) $(CLFAGS) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	@echo "CC    : " $<
	@$(CC) $(CFLAGS) -c $<

clean:
	@$(RM) $(OBJS) $(TARGET)

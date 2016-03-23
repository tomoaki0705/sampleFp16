TARGET = sampleFp16
SRC00  = main.c
SRCS   = $(SRC00)
OBJS   = $(SRCS:.c=.o)
ASM00  = main.c.none.s
ASM01  = main.c.vfp3.s
ASM02  = main.c.neon.s
ASM03  = main.c.neon-fp16.s 
ASM04  = main.c.vfp4.s
ASM05  = main.c.vfp3-fp16.s
ASM06  = main.c.vfp3xd-fp16.s
ASMS   = $(ASM00) $(ASM01) $(ASM02) $(ASM03) $(ASM04) $(ASM05) $(ASM06)
CC     = gcc
CFLAGS = -mfp16-format=ieee -std=c99

.PHONY: all clean dump
all: $(TARGET)
dump: $(ASMS)

$(TARGET): $(OBJS)
	@echo "Link               : " $@
	@$(CC) $(CLFAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	@echo "CC                 : " $<
	@$(CC) $(CFLAGS) -c $<

$(ASM00): $(SRC00)
	@echo "dump (no fpu)      : " $<
	@$(CC) -S $(CFLAGS) -o $@ $<

$(ASM01): $(SRC00)
	@echo "dump (vfpv3)       : " $<
	@$(CC) -S $(CFLAGS) -mfpu=vfpv3 -o $@ $<

$(ASM02): $(SRC00)
	@echo "dump (neon)        : " $<
	@$(CC) -S $(CFLAGS) -mfpu=neon -o $@ $<

$(ASM03): $(SRC00)
	@echo "dump (neon-fp16)   : " $<
	@$(CC) -S $(CFLAGS) -mfpu=neon-fp16 -o $@ $<

$(ASM04): $(SRC00)
	@echo "dump (vfpv4)       : " $<
	@$(CC) -S $(CFLAGS) -mfpu=vfpv4 -o $@ $<

$(ASM05): $(SRC00)
	@echo "dump (vfpv3-fp16)  : " $<
	@$(CC) -S $(CFLAGS) -mfpu=vfpv3-fp16 -o $@ $<

$(ASM06): $(SRC00)
	@echo "dump (vfpv3xd-fp16): " $<
	@$(CC) -S $(CFLAGS) -mfpu=vfpv3xd-fp16 -o $@ $<


clean:
	@$(RM) $(OBJS) $(TARGET) $(ASMS)

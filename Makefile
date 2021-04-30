OBJS = \
./obj/clock.o 

DIRS = obj lib

all: directories liblpc_1768.a

obj/%.o: ./src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -I"/home/user/vscode-workspace/lpc1768_csp/inc" -Og -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -o $@ $<
	@echo 'Finished building: $<'
	@echo ' '

liblpc_1768.a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Archiver'
	arm-none-eabi-ar -r  "lib/liblpc_1768.a" $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

test: liblpc_1768.a 
	@echo 'Building test program'
	arm-none-eabi-gcc -nostdlib -I"./inc" -L"./lib" -mcpu=cortex-m3 -mthumb test/test.c -nostartfiles -T test/test.ld -o test/test.elf -llpc_1768
clean:
	rm -rf obj lib

.PHONY: directories

directories:  
	-mkdir -p $(DIRS)

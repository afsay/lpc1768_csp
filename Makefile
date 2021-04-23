OBJS += \
./obj/clock.o \
./obj/main.o

all: liblpc_1768.a

obj/%.o: ./src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -I"/home/user/vscode-workspace/lpc1768_csp/inc" -Og -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -o $@ $<
	@echo 'Finished building: $<'
	@echo ' '

liblpc_1768.a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Archiver'
	arm-none-eabi-ar -r  "lib/liblpc_chip_175x_6x.a" $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

clean:
	rm obj/* lib/*

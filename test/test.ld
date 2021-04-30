MEMORY
{
	rom (rx) : ORIGIN = 0x0, LENGTH = 0x80000

	ram (rwx): ORIGIN = 0x10000000, LENGTH = 0x8000
}

stackTop = 0x10000000 + 0x8000;
PROVIDE(_stackTop = stackTop);

SECTIONS
{
	. = 0X0;
	.text : {
	      KEEP(*(.vectors))
	      *(.text)
	      *(.rodata)
	      }
	. = 0x10000000;
	.data : {
	      *(.data)
	      }
	.bss : {
	     *(.bss)
	     }
}

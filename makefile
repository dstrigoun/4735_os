EAC=arm-none-eabi-as.exe
ECC=arm-none-eabi-gcc.exe
ELD=arm-none-eabi-ld.exe
QEMU=qemu-system-arm.exe

default: kernel.elf

boot.o:
	$(EAC) boot.s -o boot.o

draw.o:
	$(EAC) draw.s -o draw.o

ass.o:
	$(ECC) -mcpu=arm6 -fpic -ffreestanding -std=gnu99 -c ass.c -o ass.o -O0

hal.o:
	$(ECC) -mcpu=arm6 -fpic -ffreestanding -std=gnu99 -c hal.c -o hal.o -O0

kernel.o:
	$(ECC) -mcpu=arm6 -fpic -ffreestanding -std=gnu99 -c kernel.c -o kernel.o -O0

kernel.elf: boot.o draw.o kernel.o hal.o ass.o
	$(ELD) boot.o draw.o kernel.o hal.o ass.o -T linker.ld -o kernel.elf

clean:
	rm -f kernel.elf *.o

run:
	$(QEMU) -m 256 -M raspi2 -serial stdio -kernel kernel.elf

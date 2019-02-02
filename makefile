EAC=arm-none-eabi-as.exe
ECC=arm-none-eabi-gcc.exe
ELD=arm-none-eabi-ld.exe
QEMU=qemu-system-arm.exe

default: kernel.elf

obj/boot.o:
	$(EAC) src/boot.s -o obj/boot.o

obj/draw.o:
	$(EAC) src/draw.s -o obj/draw.o

obj/ass.o:
	$(ECC) -mcpu=arm6 -fpic -ffreestanding -std=gnu99 -c src/ass.c -o obj/ass.o -O0

obj/hal.o:
	$(ECC) -mcpu=arm6 -fpic -ffreestanding -std=gnu99 -c src/hal.c -o obj/hal.o -O0

obj/kernel.o:
	$(ECC) -mcpu=arm6 -fpic -ffreestanding -std=gnu99 -c src/kernel.c -o obj/kernel.o -O0

kernel.elf: obj/boot.o obj/draw.o obj/kernel.o obj/hal.o obj/ass.o
	$(ELD) obj/boot.o obj/draw.o obj/kernel.o obj/hal.o obj/ass.o -T src/linker.ld -o kernel.elf

clean:
	rm -f kernel.elf obj/*.o

run:
	$(QEMU) -m 256 -M raspi2 -serial stdio -kernel kernel.elf

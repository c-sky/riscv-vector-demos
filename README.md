# Quickstart

Follow the steps and verify case on qemu for vector instruction.

## Step1: Setup tools

### Setup prebuilt GCC toolchain

	git clone https://github.com/c-sky/xuantie-vector-demos.git
	
	cd riscv-vector-demos
	
	mkdir toolchain
	
	tar xf riscv64-linux-x86_64.tbz2 -C toolchain
	
### Setup QEMU
	
Use prebuilt qemu for Ubuntu-16.04 host on X86-64 platform:

	mkdir qemu
	
	tar xf csky-qemu-x86_64-Ubuntu-16.04-20200512-1231.tar.gz -C qemu
	
For other host, you can also build qemu from source code:

	git clone https://github.com/qemu/qemu.git
	
	cd qemu
	
	./configure
	
	make

More infomation please reference [here](https://github.com/romanheros/qemu.git).

	
## Step2: Build case

	./toolchain/riscv64-linux-x86_64/bin/riscv64-unknown-linux-gnu-gcc -O2 test/run/vlbuv_uint32xm2-1.c
	
More unit test of vector please reference test/gcc

## Step3: Run case

### Run on prebuilt qemu

	./qemu/bin/qemu-riscv64 -cpu c910v -L ./toolchain/riscv64-linux-x86_64/sysroot a.out

### Run on source qemu

	qemu-riscv64 -cpu rv64,x-v=true,vlen=128,elen=64,vext_spec=v0.7.1 a.out

## Step4: Bug reporting

Any issue please let me konw :)

<jiejie.rjj@alibaba-inc.com>

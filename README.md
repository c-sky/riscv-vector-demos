# Quickstart

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
	
you can also build qemu from source code for other host:

	git clone https://github.com/romanheros/qemu.git -b vector-upstream-v3
	
	cd qemu
	
	./configure
	
	make

More infomation please reference [here](https://github.com/romanheros/qemu.git).

	
## Step2: Build case for running on QEMU

	./toolchain/bin/riscv64-unknown-linux-gnu-gcc -O2 test/run/vlbuv_uint32xm2-1.c
	
More unit test of vector please reference test/gcc

## Step3: Run case on QEMU

### Run on prebuilt qemu

	qemu-riscv64 -cpu c910v a.out

### Run on source qemu

	qemu-riscv64 -cpu rv64,x-v=true,vlen=128,elen=64,vext_spec=v0.7.1 a.out

## Step4: Bug reporting

Any issue please let me konw :)

<jiejie.rjj@alibaba-inc.com>

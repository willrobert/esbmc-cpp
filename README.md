# ESBMC++
ESBMC++ is a bounded model checker for embedded ANSI-C software based on SAT Modulo Theories (SMT) solver. It allows the verification engineer (i) to verify single- and multi-threaded software (with shared variables and locks); (ii) to reason about arithmetic under- and overflow, pointer safety, array bounds, atomicity and order violations, deadlock, data race, and user-specified assertions; (iii) to verify programs that make use of bit-level, pointers, structs, unions and fixed-point arithmetic.

## Content
The COM forlder contains the C++ Operational Model (COM) which represents the classes, methods, and other features similar to the actual structure.

#### Running ESBMC++

###### Dependencies

* The user must install the following packages before installation:

```
sudo apt-get install build-essential libtool
sudo apt-get install automake
sudo apt-get install byacc flex
sudo apt-get install libboost-all-dev
sudo apt-get install libgmp3-dev
sudo apt-get install libssl-dev
sudo apt-get install clang-3.8
sudo apt-get install clang-3.8-dev
sudo apt-get install lldb-3.8
sudo apt-get install bison
sudo apt-get install gcc-multilib g++-multilib
sudo apt-get install libc6 libc6-dev
sudo apt-get install openssl
```
## Download
ESBMC++ for LINUX is avaible on:
http://ssvlab.hussama.io/binaries/ecbs2013/esbmc-cpp-linux-64-static.tgz

## Tool usage
>1 - To run ESBMC for a single C program, e.g., crc.c located at the directory "smoke-tests", you should first set the environment variable PATH in your .bashrc file as follows:

`export PATH=$PATH:/home/lucas/esbmc-v1.11/bin/`

>2 - After that, you can run ESBMC from the command line by calling:

`$ esbmc crc.c`

>3 - If you want to model check the GOTO files generated by the goto-cc tool (after you type "$ make" inside the directory "smoke-tests"), then you should enter:

`esbmc --binary crc`

>4 - In order to support the checking of arithmetic under- and overflow, memory leak, data race, and atomicity violation (which are disabled by default), you should type:

>>check for arithmetic under- and overflow`esbmc file_name.c --overflow-check`

>>check for memory leaks `esbmc file_name.c --memory-leak-check`

>>check for data race condition	`esbmc file_name.c --data-races-check`

>>check for atomicity violations at visible statements `esbmc file_name.c --atomicity-check`

ESBMC enables by default the checking of array bounds, division by zero, and pointer safety, which can also be disabled via command line by typing:

`esbmc file_name.c --no-boundssl-check`		//check for out-of-bounds array indexing
`esbmc file_name.c --no-pointer-check`	//check for NULL-pointer dereferencing
`esbmc file_name.c --no-div-by-zero-check`	//check for divisions by zero

>5 - If your program calls functions from other libraries, you can set the path of the libraries by typing:

`esbmc file_name.c -I pathA -I pathB -I pathN`

where path1 means the path of library A, path2 means the path of library B, and so on.

>6 - If ESBMC does not detect automatically the bounds of the program, then you can enter:

`esbmc --unwind 36 fir_new.c`

where 36 is the maximum number of the bound. Note that if ESBMC reports "unwinding loop assertions", it means that the property holds until this bound. You can thus increase the number of the bound until ESBMC proves that the property holds or the SMT solver explodes.

>7 - ESBMC is also able to check each function of your C program individually by typing:

`esbmc file_name.c --function fun_name`

where fun_name is the name of your C function.

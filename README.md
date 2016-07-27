# 8051Emu

Emulator for the Atmel AT89C5131A

# Building

Required tools: cmake, gcc

```
mkdir build && cd build
cmake ..
make
```

# Running

```
./8051Emu
```

The path of the .hex file is hardcoded in main.cpp, change it to run your own program.

You'll need a compiler to generate an Intel HEX (.hex) file of your program.

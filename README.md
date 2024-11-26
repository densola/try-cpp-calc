# Trying C++ Calculator

Basic calculator written in C++.

## Running the program

### Prerequisites

- Install the `g++` compiler for C++ programs. If you don't have it preinstalled, visit [gcc.gnu.org](https://gcc.gnu.org/install/download.html)
- Install `make` for compiling C++ programs with Makefiles. If you don't have it preinstalled, visit [gnu.org](https://www.gnu.org/software/make/#download).
- Download the [gtkmm](https://www.gtkmm.org/en/download.html) library along with its dependencies.

### Running

Assuming that this repository was just cloned and the prerequisites have been fulfilled, the steps for running the program are as follows:

1. Open a command line
2. Change directory into this repo's directory.
3. In the command line, run:

```sh
make run
```

### Running without make

Alternatively, if you don't have `make` installed, run the commands written in the Makefile.

1. Open a command line
2. Change directory into this repo's directory.
3. Compile the program with this command:

```sh
g++ main.cc utils.cc gui.cc -o exe `pkg-config --cflags --libs gtkmm-4.0` -std=c++17
```

2. Run the program with this command:

```sh
./exe
```

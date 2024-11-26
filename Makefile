build:
	g++ -c utils.cc
	g++ main.cc utils.o -o exe `pkg-config --cflags --libs gtkmm-4.0` -std=c++17

run: build
	./exe
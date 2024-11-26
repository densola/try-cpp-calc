build:
	g++ gui.cc main.cc utils.cc -o exe `pkg-config --cflags --libs gtkmm-4.0` -std=c++17

run: build
	./exe
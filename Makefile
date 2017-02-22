all: Decompressor

Decompressor: main.cpp Decompressor.cpp HuffmanTree.cpp StatsCollector.cpp
	g++ -std=c++11 -g -o Decompressor main.cpp Decompressor.cpp HuffmanTree.cpp StatsCollector.cpp

clean:
	rm -rf Decompressor

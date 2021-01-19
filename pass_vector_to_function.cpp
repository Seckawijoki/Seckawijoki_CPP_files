#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Block {
public:
	Block(){
		printf("Block(): this = %d\n", this);
	}
//	Block(const Block& from){
//		printf("Block(): this = %d | from = %d\n", this, &from);
//	}
};

void setData(vector<Block>& blocks){
	printf("setData(): &blocks = %d\n", &blocks);
	size_t size = blocks.size();
	for (size_t i = 0; i < size; ++i){
		printf("setData(): &blocks[%d] = %d\n", i, &blocks[i]);
	}
}

int main(){
//	vector<Block> blocks;
//	blocks.resize(3);
//	
//	printf("main(): &blocks = %d\n", &blocks);
//	size_t size = blocks.size();
//	for (size_t i = 0; i < size; ++i){
//		printf("main(): &blocks[%d] = %d\n", i, &blocks[i]);
//	}
//	
//	setData(blocks);

	Block b0 = Block();
	Block b1 = b0;
	printf("main(): &b0 = %d\n", &b0);
	printf("main(): &b1 = %d\n", &b1);
	return 0;
}

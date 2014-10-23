#include <iostream>

using namespace std;

#define INT_BIT 32

typedef struct
{
	unsigned int* table;
	int size;
}BitMap;

BitMap* bitmap_create(int max_bit)
{
	BitMap* bitmap = new BitMap;
	bitmap->size = max_bit / INT_BIT + 1;
	bitmap->table = new unsigned int[bitmap->size];
	return bitmap;
}

void bitmap_insert(BitMap* bitmap,int key)
{
	int index = key / 32;
	int in_index = key % 32;
	bitmap->table[index] = bitmap->table[index] | (1 << in_index);
}

void bitmap_delete(BitMap* bitmap,int key)
{
	int index = key / 32;
	int in_index = key % 32;
	bitmap->table[index] = bitmap->table[index] & ~(1<<in_index);
}

int bitmap_search(BitMap* bitmap,int key)
{
	int index = key / 32;
	int in_index = key % 32;
	return ((bitmap->table[index]) & (1 << in_index));
}

int main(int argc, char** argv)
{
	BitMap* bitmap = bitmap_create(3999);
	bitmap_insert(bitmap, 1111);
	bitmap_insert(bitmap, 222);
	bitmap_insert(bitmap, 1);
	bitmap_delete(bitmap, 1);
	if (bitmap_search(bitmap, 1)){
		cout<<"success!"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	return 0;
}
#include <iostream>
#include "bintree.h"






int main() {
	
	//std::cout << "bintree" << std::endl;
	BinTree<int> bt(5);
	auto b1 = bt.InsertAsLC(bt.Root(), 6);
	auto b2 = bt.InsertAsRC(bt.Root(), 7);
	auto b3 = bt.InsertAsLC(b1, 4);
	auto b4 = bt.InsertAsRC(b1, 1);
	auto b5 = bt.InsertAsRC(b3, 2);
	auto b6 = bt.InsertAsLC(b2, 9);
	bt.TravPreOrder(bt.Root());
	std::cout << std::endl;
	bt.TravInOrder(bt.Root());
	std::cout << std::endl;
	bt.TravPostOrder(bt.Root());
	std::cout << std::endl;
	system("pause");
	return 0;
}
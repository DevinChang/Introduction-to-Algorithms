#include <iostream>
#include "tree.h"




int main() {
	auto bt = Tree();
	bt->TravPreOrderIteration1(bt->Root());
	std::cout << std::endl;
	//ex13.2
	bt->RightRotate(bt->Root());
	bt->TravPreOrderIteration1(bt->Root());
	system("pause");
	return 0;
}
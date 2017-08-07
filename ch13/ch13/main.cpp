#include <iostream>
#include "tree.h"




int main() {
	auto bt = Tree();
	bt->TravInOrderIteration1(bt->Root());
	//bt->LeftRotate()
	system("pause");
	return 0;
}
#pragma  once

#include "../../DSA_CPP/BinTree/bintree.h"
#include <memory>


std::shared_ptr<BinTree<int>> Tree() {
	std::shared_ptr<BinTree<int>> bt = std::make_shared<BinTree<int>>(6);
	auto b1 = bt->InsertAsLC(bt->Root(), 4);
	auto b2 = bt->InsertAsRC(bt->Root(), 7);
	auto b3 = bt->InsertAsLC(b1, 3);
	auto b4 = bt->InsertAsRC(b1, 5);
	auto b5 = bt->InsertAsLC(b3, 1);
	auto b6 = bt->InsertAsLC(b4, 2);
	auto b7 = bt->InsertAsLC(b2, 6);
	auto b8 = bt->InsertAsRC(b2, 8);
	auto b9 = bt->InsertAsRC(b7, 9);
	return bt;
}
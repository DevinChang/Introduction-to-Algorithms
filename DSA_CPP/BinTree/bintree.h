#pragma once

//template<typename T> class BinNode;
//#define BinNodePos(T) BinNode<T>*




template<typename T>
class BinNode {
public:
	//constructor
	BinNode() = default;
	BinNode(T e, BinNode<T> p = NULL, BinNode<T> lc = NULL, BinNode<T> rc = NULL, int h = 0) 
		: data(e), parent(p), lchild(lc), rchild(rc), height(h){}
	~BinNode();
public:
	//interface
	BinNode<T> InsertAsLC(const T &);
	BinNode<T> InsertAsRC(const T &);
	void TravPreOrder();
	void TravInOrder();
	void TravPostOrder();
private:
	T data;
	BinNode<T> parent, lchild, rchild;
	int height;
};
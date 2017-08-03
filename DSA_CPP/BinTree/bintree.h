#pragma once
#include "../Stack/stack.h"

//#define IsRoot(x) (!(x).parent))
//#define IsLChild(x) (!IsRoot(x) && ((x) == (x).parent->lc))
//#define IsRChild(x) (!IsRoot(x) && ((x) == (x).parent->rc))
//#define HasLChild(x) ((x).lc)
//#define HasRChild(x) ((x).rc)
//#define HasChild(x) (HasLChild(x) || HasRChild(x))
//#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
//#define IsLeaf(x) (!HasChild(x))
//brother
//#define Sibling(p) (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc)
//uncle
//#define Uncle(x) (IsLChild(*((x)->parent) ? (x)->parent->parent->rc : (x)->parent->parent->lc)
//height
#define Stature(p) ((p) ? (p)->height : -1)
//来自父节点的引用
//#define FromParentTo(x) (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))
#define max(a, b) (((a) > (b)) ? (a) : (b)) 





template<typename T>
struct BinNode {
	//constructor
	BinNode() = default;
	BinNode(T e, BinNode<T> *p = NULL, BinNode<T> *lchild = NULL, BinNode<T> *rchild = NULL, int h = 0) 
		: data(e), parent(p), lc(lchild), rc(rchild), height(h){}
	~BinNode(){}
	//interface
	BinNode<T>* InsertAsLC(T const &);
	BinNode<T>* InsertAsRC(T const &);
	//void TravPreOrder();
	//void TravInOrder();
	//void TravPostOrder();
	
	T data;
	BinNode<T>* parent;
	BinNode<T>*lc;
	BinNode<T>*rc;
	int height;
};


//template<typename N> class BinTree;
//template<typename T>
//void FromParentTo(BinNode<T> *);
//
//
//template<typename N> class BinTree;
//template<typename T>
//void Release(BinNode<T> *);

template<typename N> class BinTree;
template<typename T>
bool IsRoot(BinNode<T> *);

template<typename N> class BinTree;
template<typename T>
bool IsLChild (BinNode<T>*);

template<typename N> class BinTree;
template<typename T>
bool IsRChild(BinNode<T>*);

template<typename N> class BinTree;
template<typename T>
void Release (BinNode<T> *);

template<typename N> class BinTree;
template<typename T>
BinNode<T>* FromParentTo (BinNode<T> *);

template<typename N> class BinTree;
template<typename T>
bool HasLChild (BinNode<T>*);

template<typename N> class BinTree;
template<typename T>
bool HasRChild(BinNode<T>*);

template<typename N> class BinTree;
template<typename T>
bool HasChild(BinNode<T>*);

template<typename N> class BinTree;
template<typename T>
bool IsLeaf(BinNode<T>*);


template<typename N> class BinTree;
template<typename T>
BinNode<T> *Succeed (BinNode<T> *);

template<typename T>
class BinTree {
	friend bool IsRoot <T>(BinNode<T> *);
	friend bool IsLChild <T>(BinNode<T>*);
	friend bool IsRChild <T>(BinNode<T>*);
	friend void Release <T>(BinNode<T> *);
	friend BinNode<T>* FromParentTo <T>(BinNode<T> *);
	friend bool HasLChild <T>(BinNode<T>*);
	friend bool HasRChild <T>(BinNode<T>*);
	friend bool HasChild <T>(BinNode<T>*);
	friend bool IsLeaf <T>(BinNode<T>*);
	friend BinNode<T> *Succeed <T>(BinNode<T> *);
public:
	//constructor
	BinTree() = default;
	BinTree(T const &e) : _size(0), _root(new BinNode<T>(e)){}
	~BinTree() { Remove(_root); }
	//interface
	int size() { return _size; }
	bool empty() { return !_root; }
	BinNode<T>* Root() const { return _root; }
	BinNode<T>* InsertAsRoot(T const &);
	BinNode<T>* InsertAsLC(BinNode<T>*, T const &);
	BinNode<T>* InsertAsRC(BinNode<T>*, T const &);
	//连接子树
	BinNode<T>* AttathAsLC(BinNode<T>*, BinTree<T>* &);
	BinNode<T>* AttathAsRC(BinNode<T>*, BinTree<T>* &);
	//Recursive
	void TravPreOrder(BinNode<T>*);
	void TravInOrder(BinNode<T>*);
	void TravPostOrder(BinNode<T>*);
	//
	void TravPreOrderIteration1(BinNode<T>*);
	void TravPreOrderIteration2(BinNode<T>*);
	void TravInOrderIteration1(BinNode<T>*);
	void TravInOrderIteration2(BinNode<T>*);
	//space O(1)
	void TravInOrderIerationNoStack(BinNode<T>*);
	void TravPostOrderIteration(BinNode<T>*);
	
	int Remove(BinNode<T>*);
	static int RemoveAt(BinNode<T>*);
	static void VisitAlongLeftBranch(BinNode<T>*, Stack<BinNode<T>*> &);
	static void GoThroughLeftBranch(BinNode<T>*, Stack<BinNode<T>*> &);
	static void GoToHLVFL(Stack<BinNode<T>*> &);
protected:
	int _size;
	BinNode<T>* _root;
	int UpdateHeight(BinNode<T>* x);
	void UpdateHeightAbove(BinNode<T>* x);
};


template<typename T>
BinNode<T>* BinNode<T>::InsertAsLC(T const &e) {
	return lc = new BinNode(e, this);
}

template<typename T>
BinNode<T>* BinNode<T>::InsertAsRC(T const &e) {
	return rc = new BinNode(e, this);
}

template<typename T>
int BinTree<T>::UpdateHeight(BinNode<T>* x) {
	return x->height = 1 + max(Stature(x->lc), Stature(x->rc));
}

template<typename T>
void BinTree<T>::UpdateHeightAbove(BinNode<T>* x) {
	while (x) {
		UpdateHeight(x);
		x = x->parent;
	}
}

template<typename T>
BinNode<T>* BinTree<T>::InsertAsRoot(T const &e) {
	_size = 1;
	return _root = new BinNode<T>(e);
}

template<typename T>
BinNode<T>* BinTree<T>::InsertAsLC(BinNode<T>* x, T const &e) {
	_size++;
	x->InsertAsLC(e);
	UpdateHeightAbove(x);
	return x->lc;
}

template<typename T>
BinNode<T>* BinTree<T>::InsertAsRC(BinNode<T>* x, T const &e) {
	_size++;
	x->InsertAsRC(e);
	UpdateHeightAbove(x);
	return x->rc;
}

template<typename T>
inline void BinTree<T>::TravPreOrder(BinNode<T>* bt){
	if (bt) {
		std::cout << bt->data << " ";
		TravPreOrder(bt->lc);
		TravPreOrder(bt->rc);
	}
}

template<typename T>
inline void BinTree<T>::TravInOrder(BinNode<T>*bt){
	if (bt) {
		TravInOrder(bt->lc);
		std::cout << bt->data << " ";
		TravInOrder(bt->rc);
	}
}

template<typename T>
inline void BinTree<T>::TravPostOrder(BinNode<T>*bt){
	if (bt) {
		TravPostOrder(bt->lc);
		TravPostOrder(bt->rc);
		std::cout << bt->data << " ";
	}
}

template<typename T>
inline void BinTree<T>::TravPreOrderIteration1(BinNode<T>* p){
	Stack<BinNode<T>*> s;
	if (p)
		s.push(p);
	while (!s.empty()) {
		p = s.pop();
		std::cout << p->data << " ";
		if (HasRChild(p))
			s.push(p->rc);
		if (HasLChild(p))
			s.push(p->lc);
	}
}

template<typename T>
inline void BinTree<T>::TravPreOrderIteration2(BinNode<T>* p){
	Stack<BinNode<T>*> s;
	while (true) {
		VisitAlongLeftBranch(p, s);
		if (s.empty())
			break;
		p = s.pop();
	}
}

template<typename T>
inline void BinTree<T>::TravInOrderIteration1(BinNode<T>* p){
	Stack<BinNode<T>*> s;
	while (true) {
		GoThroughLeftBranch(p, s);
		if (s.empty())
			break;
		p = s.pop();
		std::cout << p->data << " ";
		p = p->rc;
	}
}

template<typename T>
inline void BinTree<T>::TravInOrderIteration2(BinNode<T>* p){
	Stack<BinNode<T>*> s;
	while (true) {
		if (p) {
			s.push(p);
			p = p->lc;
		}
		else if (!s.empty()) {
			p = s.pop();
			std::cout << p->data << " ";
			p = p->rc;
		}
		else
			break;
	}
}


template<typename T>
inline void BinTree<T>::TravInOrderIerationNoStack(BinNode<T>* p){
	bool backtrack = false;
	while (true) {
		if (!backtrack && HasLChild(p))
			p = p->lc;
		else {
			std::cout << p->data << " ";
			if (HasRChild(p)) {
				p = p->rc;
				backtrack = false;
			}
			else {
				p = Succeed(p);
				if (!p)
					break;
				backtrack = true;
			}
		}
	}
}

template<typename T>
inline void BinTree<T>::TravPostOrderIteration(BinNode<T>* p){
	Stack<BinNode<T>*> s;
	if (p)
		s.push(p);
	while (!s.empty()) {
		if (s.top() != p->parent)
			GoToHLVFL(s);
		p = s.pop();
		std::cout << p->data << " ";
	}
}

template<typename T>
bool IsRoot(BinNode<T>* p){
	if (!p->parent)
		return true;
	return false;
}

template<typename T>
bool IsLChild(BinNode<T>*p){
	if (!IsRoot(p) && p == p->parent->lc)
		return true;
	return false;
}

template<typename T>
bool IsRChild(BinNode<T>*p) {
	if (!IsRoot(p) && p == p->parent->rc)
		return true;
	return false;
}

template<typename T>
void Release(BinNode<T>* bt) {
	if (bt) {
		bt->data = 0;
		delete bt;
		bt = nullptr;
	}
}


//#define FromParentTo(x) (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))

template<typename T>
BinNode<T>* FromParentTo(BinNode<T>* p){
	if (IsRoot(p))
		return p;
	return (IsLChild(p) ? p->parent->lc : p->parent->rc);
}

template <typename T>
bool HasLChild(BinNode<T>* p){
	if (!p)
		return false;
	if (p->lc)
		return true;
	return false;
}

template <typename T>
bool HasRChild(BinNode<T>* p) {
	if (!p)
		return false;
	if (p->rc)
		return true;
	return false;
}

template <typename T>
bool HasChild(BinNode<T>* p) {
	return HasLChild(p) || HasRChild(p);
}

template <typename T>
bool IsLeaf(BinNode<T>* p) {
	return !HasChild(p);
}


template<typename T>
BinNode<T>* Succeed(BinNode<T>* p){
	BinNode<T> *s = p;
	if (p->rc) {
		s = p->rc;
		while(s->lc)
			s = s->lc;
	}
	else {
		while (IsRChild(s))
			s = s->parent;
		s = s->parent;
	}
	return s;
}



template<typename T>
int BinTree<T>::Remove(BinNode<T>* x) {
	auto p = FromParentTo(x);
	p = NULL;
	UpdateHeightAbove(x->parent);
	int n = RemoveAt(x);
	_size -= n;
	return n;
}



template<typename T>
inline int BinTree<T>::RemoveAt(BinNode<T>* x){
	if (!x)
		return 0;
	int n = 1 + RemoveAt(x->lc) + RemoveAt(x->rc);
	Release(x);
	return n;
}

template<typename T>
inline void BinTree<T>::VisitAlongLeftBranch(BinNode<T>*p, Stack<BinNode<T>*> &s){
	while (p) {
		std::cout << p->data << " ";
		s.push(p->rc);
		p = p->lc;
	}
}

template<typename T>
inline void BinTree<T>::GoThroughLeftBranch(BinNode<T>* p, Stack<BinNode<T>*>& s){
	while (p) {
		s.push(p);
		p = p->lc;
	}
}

template<typename T>
inline void BinTree<T>::GoToHLVFL(Stack<BinNode<T>*>& s){
	while (auto p = s.top()) {
		if (HasLChild(p)) {
			if (HasRChild(p))
				s.push(p->rc);
			s.push(p->lc);
		}
		else
			s.push(p->rc);
	}
	s.pop();
}








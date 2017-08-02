#pragma once


//#define IsRoot(x) (!(x).parent))
//#define IsLChild(x) (!IsRoot(x) && ((x) == (x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && ((x) == (x).parent->rc))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))
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
void Release (BinNode<T> *);

template<typename N> class BinTree;
template<typename T>
BinNode<T>* FromParentTo (BinNode<T> *);

template<typename T>
class BinTree {
	friend bool IsRoot <T>(BinNode<T> *);
	friend bool IsLChild <T>(BinNode<T>*);
	friend void Release <T>(BinNode<T> *);
	friend BinNode<T>* FromParentTo <T>(BinNode<T> *);
	
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

	void TravPreOrder(BinNode<T>*);
	void TravInOrder(BinNode<T>*);
	void TravPostOrder(BinNode<T>*);
	
	int Remove(BinNode<T>*);
	static int RemoveAt(BinNode<T>*);

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








/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Trees - BT, BST, AVL   						                   *
* Dated: November 28, 2007                                                 *
* Version: 2.21   Classes example for all Trees with example code          *                                                 
* Last modified: December 02, 2007                                         *
****************************************************************************/

#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
// Binary Search Tree Class 
template <class T>
class BSTREE;
//Binary Tree Class
template <class T>
class BTree;
// AVL Tree Class
template <class T>
class AVLtree;
//BSTNode Class
template <class T>
class BSTNODE
{
	friend BSTREE<T>;
	friend BTree<T>;
	friend AVLtree<T>;
	protected :
			T data;
			BSTNODE<T>* left;
			BSTNODE<T>* right;
	public :

			BSTNODE()
			{
				data = 0;
				left = 0;
				right = 0;
			}

			BSTNODE(const T& insertvalue)
			{
				data = insertvalue;
				left = 0;
				right = 0;
			}
			// Parametric constructors 
			BSTNODE(const T& inser,BSTNODE<T>* lptr,BSTNODE<T>* rptr)
			{
				data = inser;
				left = lptr;
				right = rptr;
			}
};

template<class T>
class BTree
{
	private :
			void Inorder(BSTNODE<T>* t);
			void Preorder(BSTNODE<T>* t);
			void Postorder(BSTNODE<T>* t);
			void countl(BSTNODE<T>* t,int& count);
			void Nodecount(BSTNODE<T>* t,int& count);
			void oneparentNodecount(BSTNODE<T>* t,int& count);
			bool isBST(BSTNODE<T>* t);

	protected :

			BSTNODE<T>* root;
			BSTNODE<T>* current;

	public :

		virtual void insert(const T&) = 0;
		virtual void deletenode(const T&) = 0;
		virtual bool find(const T&,int&,int&,long int&)= 0;
		BTree();
		~BTree();

		void deletetree(BSTNODE<T>* root);
		T minimum();
		T maximum();
		int leafcount();
		void printtree(ofstream& outf);
		int nc();
		int onc();
		void orderz ();
		void isb();

};

template <class T>
BTree<T> :: BTree()
		{
			root = 0;
			current = 0;
		}
template <class T>
BTree<T> :: ~BTree()
		{
			deletetree(root);
		}

// private function deletetree
template <class T>
void BTree<T>  :: deletetree(BSTNODE<T>* root)
		{
			if (root)
			{
				deletetree(root->left);
				deletetree(root->right);
				delete root;
				root = 0;
			}
		}
		
// Minimum from BST
template <class T>
T BTree<T>  :: minimum()
		{
			BSTNODE<T>* currptr = root;

			if (root !=0)
			{
				while (currptr->left !=0)
					currptr = currptr->left;

				return currptr->data;
			}
			else
				return 0;
		}
// Maximum from BST
template <class T>
T BTree<T>  :: maximum()
		{
			BSTNODE<T>* currptr = root;

			if (root !=0)
			{
				while (currptr->right !=0)
					currptr = currptr->right;

				return currptr->data;
			}
			else
				return 0;
		}

//counting leaves nodes 
template <class T>
int BTree<T>  :: leafcount()
		{
			BSTNODE<T>* t = root;
			int count = 0;
			countl(t,count);
			return count;
		}

template <class T>
void BTree<T>  :: printtree(ofstream& outf)
		{
			BSTNODE<T>* t = root;
			Inorder(t,outf);
		}

template <class T>
void BTree<T>  :: orderz ()
		{
			BSTNODE<T>* t= root;
			cout << "INORDER TRAVERSAL IS : " << endl;
			Inorder(root);
			t = root;
			cout << "PREORDER TRAVERSAL IS : " << endl;
			Preorder(root);
			t = root;
			cout << "POSTORDER TRAVERSAL IS : " << endl;
			Postorder(root);
		}

template <class T>
int BTree<T>  :: nc()
		{
			BSTNODE<T>* t = root;
			int count = 0;
			Nodecount(t,count);
			return count;
		}

template <class T>
int BTree<T>  :: onc()
		{
			BSTNODE<T>* t = root;
			int count = 0;
			oneparentNodecount(t,count);
			return count;
		}


template <class T>
void BTree<T>  :: isb()
		{
			BSTNODE<T>* t = root;

			if (isBST(t))
				cout << "true";
			else
				cout << "false";
		}

template <class T>
void BTree<T>  :: Inorder(BSTNODE<T>* t)
			{
				if (t != 0)
				{
					Inorder(t->left);
					cout << t->data << endl;
					Inorder(t->right);
				}
			}

template <class T>
void BTree<T>  :: Preorder(BSTNODE<T>* t)
			{
				if (t != 0)
				{
					cout << t->data << endl;
					Preorder(t->left);
					Preorder(t->right);
				}
			}

template <class T>
void BTree<T>  :: Postorder(BSTNODE<T>* t)
			{
				if (t != 0)
				{
					Postorder(t->left);
					Postorder(t->right);
					cout << t->data << endl;
				}
			}

template <class T>
void BTree<T>  :: countl(BSTNODE<T>* t,int& count)
			{
				if (t != 0)
				{
					countl(t->left,count);
					countl(t->right,count);

					if (t->left == 0 && t->right == 0)
						++count;
				}
			}
template <class T>
void BTree<T>  :: Nodecount(BSTNODE<T>* t,int& count)
			{
				if (t)
				{

					Nodecount(t->left,count);
				//	++count;
					Nodecount(t->right,count);
					++count;
				}
			}

template <class T>
void BTree<T>  :: oneparentNodecount(BSTNODE<T>* t,int& count)
{
	if (t)
	{
		oneparentNodecount(t->left,count);
		oneparentNodecount(t->right,count);
		if (t->left == 0 && t->right != 0 || t->left != 0 && t->right == 0)
			++count;
	}
}

template <class T>
bool BTree<T>  :: isBST(BSTNODE<T>* t)
{
	if (t)
	{
		isBST(t->left);

		isBST(t->right);
		if (t->left == 0 && t->right != 0)
		{
			if (t->right->data < t->data)
			{
				return false;

			}
		}
		else if (t->left != 0 && t->right == 0)
		{
			if (t->left->data > t->data)
			return false;
		}
		else if (t->left != 0 && t->right != 0)
		{
			if (t->left->data > t->data)
				return false;
			else if (t->right->data < t->data)
				return false;
		}

	}
	else
		return true;
}



///////////////////////////////////////////////////////

template <class T>
class BSTREE	: public BTree<T>
{
	private :
			int comparisonb;
			void display(BSTNODE<T>* currptr,ofstream&);
			BSTNODE<T>* findnode(const T& value,BSTNODE<T>*& parent);
			BSTNODE<T>* copytree(BSTNODE<T>* t);
			BSTNODE<T>* createmirrortree(BSTNODE<T>* t);
			void calav(BSTNODE<T>* t,double& av);

	public :
			BSTREE();
			BSTREE<T>& operator = (const BSTREE<T>& rhs);
			BSTREE(const BSTREE<T>&);
			void insert(const T& value);
			void printlist(ofstream& outf);
			bool find(const T& item,int& success,int& failure,long int& comb);
			void deletenode(const T& value);
			void update(const T& value);
			void Freetreenode(BSTNODE<T>* p);
			void cmt();		// callin create mirror tree
			double average(double& avera);

			friend istream& operator  >> (istream& s,BSTREE<T>& s1)
			{

					long int gedata;
					while (!s.eof())
					{
						s >> gedata;
						s1.insert(gedata);
					}
					return s;
			}



};

template <class T>
BSTREE<T> :: BSTREE()
			{
				comparisonb = 0;
			}

template <class T>
BSTREE<T>& BSTREE<T> :: operator = (const BSTREE<T>& rhs)
		{
			if (this == &rhs)
				return *this;
			deletetree();
			root = copytree(rhs.root);

			return *this;
		}

template <class T>
BSTREE<T> :: BSTREE(const BSTREE<T>& copobject)
{
		root = copytree(copobject.root);
}


template <class T>
BSTNODE<T>* BSTREE<T>  :: copytree(BSTNODE<T>* t)
		{
			BSTNODE<T>* newlptr,*newrptr,*newnode;

			if (t == 0)
				return 0;

			if (t->left != 0)
				newlptr = copytree(t->left);
			else
				newlptr = 0;
			if (t->right != 0)
				newrptr = copytree(t->right);
			else
				newrptr = 0;

			newnode = new BSTNODE<T>(t->data,newlptr,newrptr);

			return newnode;
		}



template <class T>

void cmt(const BSTREE<T>& a)
{
	root = createmirrortree(a.root);
}


template <class T>
BSTNODE<T>* BSTREE<T>  :: createmirrortree(BSTNODE<T>* t)
		{
			BSTNODE<T>* newlptr,*newrptr,*newnode;

			if (t == 0)
				return 0;

			if (t->left != 0)
				newlptr = copytree(t->left);
			else
				newlptr = 0;
			if (t->right != 0)
				newrptr = copytree(t->right);
			else
				newrptr = 0;

			newnode = new BSTNODE<T>(t->data,newrptr,newlptr);

			return newnode;
		}


template <class T>
double BSTREE<T> :: average(double& avera)
{
				BSTNODE<T>* t = root;		
				calav(t,avera);
				return avera;
}

template <class T>
void BSTREE<T> ::calav(BSTNODE<T>* t,double& av)
				{
					if (t)
					{
						calav(t->left,av);
						av += t->data;
						calav(t->right,av);
					}
				}

template <class T>
void BSTREE<T> :: display(BSTNODE<T>* currptr,ofstream& outf)
			{
				if (currptr)
				{
					display(currptr->left,outf);
					outf << currptr->data << endl;
					display(currptr->right,outf);
				}
			}

template <class T>
void BSTREE<T> :: insert(const T& value)
			{
				BSTNODE<T>* currptr = root,*parent = 0,*newnode;
				while (currptr != 0)
				{
					parent = currptr;
					if (value < currptr->data)
						currptr = currptr->left;
					else
						currptr = currptr->right;

				}
				newnode = new BSTNODE<T>(value);
				if (parent == 0)
				{
					root = newnode;
				}
				else if (parent->data > value)
					parent->left = newnode;
				else
					parent->right = newnode;

				currptr = newnode;
			}

template <class T>
void BSTREE<T> ::printlist(ofstream& outf)
			{
				BSTNODE<T>* current = root;
				display(current,outf);
			}

template <class T>
BSTNODE<T>* BSTREE<T> :: findnode(const T& value,BSTNODE<T>*& parent)
			{
				BSTNODE<T>* findptr = root;
				parent = 0;

				while (findptr != NULL)
				{
					if (value == findptr->data)
						break;
					else
					{
						parent = findptr;
						if (value < findptr->data)
						{
							findptr = findptr->left;
							++comparisonb;
						}
						else
						{
							findptr = findptr->right;
							++comparisonb;
						}
					}
				}
				return findptr;
			}

template <class T>
bool BSTREE<T> :: find(const T& item,int& success,int& failure,long int& 
comb)
			{
				BSTNODE<T>* parent;
				current = findnode(item,parent);
				comb = comparisonb;
				if (current != NULL)
				{
					++success;
					return true;
				}
				else
				{
					++failure;
					return false;
				}
			}

template <class T>
void BSTREE<T> :: deletenode(const T& value)
			{
				BSTNODE<T>* Dnodeptr,*Pnodeptr,*Rnodeptr;

				if ((Dnodeptr = findnode(value,Pnodeptr)) == NULL)
				{
					cout << "not found";
					return;
				}
				if (Dnodeptr->left == NULL)
					Rnodeptr = Dnodeptr->right;
				else if (Dnodeptr->right == NULL)
					Rnodeptr = Dnodeptr->left;
				else
				{
					BSTNODE<T>* Porfnodeptr = Dnodeptr;
					Rnodeptr = Dnodeptr->left;

					while (Rnodeptr->right != NULL)
					{
						Porfnodeptr = Rnodeptr;
						Rnodeptr = Rnodeptr->right;
					}

					if (Porfnodeptr == Dnodeptr)
					{
						Rnodeptr->right = Dnodeptr->right;
						Dnodeptr->right = 0;
					}
					else
					{
						Porfnodeptr->right = Rnodeptr->left;
						Rnodeptr->right = Dnodeptr->right;
						Rnodeptr->left = Dnodeptr->right;
					}
				}

				if (Pnodeptr == 0)
					root = Rnodeptr;
				else if (Dnodeptr->data < Pnodeptr->data)
					Pnodeptr->left = Rnodeptr;
				else
					Pnodeptr->right = Rnodeptr;


			}

template <class T>
void BSTREE<T> :: update(const T& value)
			{
				BSTNODE<T>* parent;
				current = find(value,parent);

				if (current != 0 && current->data == value)
					current->data = value;
				else
					insert(value);
			}

template <class T>
void BSTREE<T> :: Freetreenode(BSTNODE<T>* p)
			{
				delete p;
			}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

template <class T>
class AVLnode : public BSTNODE<T>
{
	private :
			int balfactor;
			AVLnode<T>* aleft;
			AVLnode<T>* aright;

	public :
			friend AVLtree<T>;
			AVLnode()
			{
				balfactor = 0;
				aleft = 0;
				aright = 0;

			}
			AVLnode(const T& value)
			{
				data = value;
				aleft = 0;
				aright = 0;
				balfactor = 0;
			}
			int getbalfactor()
			{
				return balfactor;
			}
			AVLnode(const T& inser,AVLnode<T>* lptr,AVLnode<T>* rptr)
			{
				data = inser;
				left = lptr;
				right = rptr;
			}
};

template <class T>
class AVLtree : public BSTREE<T>
{
		private :
				AVLnode<T>* AVLroot;

				int comparison;
				void rotateleft(AVLnode<T>* &p);
				void rotateright(AVLnode<T>* &p);
				int ins(AVLnode<T>* &p,const T& value);
				int del (AVLnode<T>* &p,int x);
				void disp(const AVLnode<T>* p,ofstream&);
				void calav(AVLnode<T>* t,double& av);
				AVLnode<T>* findnode(const T& value,AVLnode<T>*& parent);
				void deletetree(AVLnode<T>* AVLroot);
				virtual AVLnode<T>* copytree(AVLnode<T>* t);
				AVLnode<T>* createmirrortree(AVLnode<T>* t);
		public :
				AVLtree();
				virtual ~AVLtree();
				virtual void insert(const T& value);
				virtual void deletenode(T x);

				virtual void printlist(ofstream& outf);
				bool find(const T& item,int& success,int& failure,long int& comb);
				virtual T minimum();
				virtual T maximum();
				double average(double&);
				virtual AVLtree<T>& operator = (const AVLtree<T>& rhs);
				AVLtree(const AVLtree<T>&);
				void cmt(const AVLtree<T>&);

				friend istream& operator  >> (istream& s,AVLtree<T>& s1)
				{

					long int gedata;
					while (!s.eof())
					{
						s >> gedata;
						s1.insert(gedata);
					}
					return s;
				}



};

template <class T>
AVLtree<T> :: AVLtree()
				{
					AVLroot = 0;
					comparison = 0;

				}

template <class T>
AVLtree<T> :: ~AVLtree()
{

}

template <class T>
AVLtree<T>& AVLtree<T> :: operator = (const AVLtree<T>& rhs)
		{
			if (this == &rhs)
				return *this;
			deletetree(AVLroot);
			AVLroot = copytree(rhs.AVLroot);

			return *this;
		}

template <class T>
AVLtree<T> :: AVLtree(const AVLtree<T>& copobject)
{
		AVLroot = copytree(copobject.AVLroot);
}


template <class T>
AVLnode<T>* AVLtree<T>  :: copytree(AVLnode<T>* t)
		{
			AVLnode<T>* newlptr,*newrptr,*newnode;

			if (t == 0)
				return 0;

			if (t->aleft != 0)
				newlptr = copytree(t->aleft);
			else
				newlptr = 0;
			if (t->aright != 0)
				newrptr = copytree(t->aright);
			else
				newrptr = 0;

			newnode = new AVLnode<T>(t->data,newlptr,newrptr);

			return newnode;
		}

template <class T>
void AVLtree<T>  :: deletetree(AVLnode<T>* AVLroot)
{
			if (AVLroot)
			{
				deletetree(AVLroot->aleft);
				deletetree(AVLroot->aright);
				delete AVLroot;
				AVLroot = 0;
			}
}
template <class T>
void AVLtree<T> :: insert(const T& value)
				{
				//	AVLnode<T>* curr = AVLroot;
					ins(AVLroot,value);
				}
template <class T>
void AVLtree<T> :: deletenode(T x)
				{
					AVLnode<T>* curr = AVLroot;
					del(curr,x);
				}


template <class T>
void AVLtree<T> :: rotateleft(AVLnode<T>* &p)
				{
					AVLnode<T>* q =p;
					p = p->aright;
					q->aright = p->aleft;
					p->aleft = q;
					q->balfactor--;
					if (p->balfactor > 0)
						q->balfactor -= p->balfactor;
					p->balfactor--;
					if (q->balfactor < 0)
						p->balfactor += q->balfactor;
				}

template <class T>
void AVLtree<T> :: rotateright(AVLnode<T>* &p)
				{
					AVLnode<T>* q = p;
					p = p->aleft;
					q->aleft = p->aright;
					p->aright = q;
					q->balfactor++;
					if (p->balfactor < 0)
						q->balfactor -= p->balfactor;
					p->balfactor++;
					if (q->balfactor > 0)
						p->balfactor += q->balfactor;
				}

template <class T>
int AVLtree<T> :: ins(AVLnode<T>* &p,const T& value)
				{
					int deltaH = 0;

					if (p == 0)
					{
						p = new AVLnode<T>(value);

						deltaH = 1;
					}
					else if (value > p->data)
					{
						if (ins(p->aright,value))
						{
							p->balfactor++;
							if (p->balfactor == 1)
								deltaH = 1;
							else if (p->balfactor == 2)
							{
								if (p->aright->balfactor == -1)
									rotateright(p->aright);
								rotateleft(p);
							}
						}
					}

					else if (value < p->data)
					{
						if (ins(p->aleft,value))
						{
							p->balfactor--;
							if (p->balfactor == -1)
								deltaH = 1;
							else if (p->balfactor == -2)
							{
								if (p->aleft->balfactor == 1)
									rotateleft(p->aleft);
								rotateright(p);
							}
						}
					}
					++comparison;
					++comparison;
					return deltaH;
				}

template <class T>
int AVLtree<T> :: del (AVLnode<T>* &p,int x)
				{
					AVLnode<T> **qq,*p0;
					int deltaH = 0;
					if (p == 0)
						return 0;
					if (x < p->data)
					{
						if (del(p->aleft,x))
						{
							p->balfactor++;
							if (p->balfactor == 0)
								deltaH = 1;
							else if (p->balfactor == 2)
							{
								if (p->aright->balfactor == -1)
									rotateright(p->aright);
								rotateleft(p);
								if (p->balfactor == 0)
									deltaH = 1;
							}
						}
					}
					else if (x > p->data)
					{
						if (del(p->aright,x))
						{
							p->balfactor--;
							if (p->balfactor == 0)
								deltaH = 1;
							else if (p->balfactor == -2)
							{
								if (p->aleft->balfactor == 1)
									rotateleft(p->aleft);
								rotateright(p);
								if (p->balfactor == 0)
									deltaH = 1;
							}
						}
					}
					else
					{
						if (p->aright == 0)
						{
							p0 = p;
							p = p->aleft;
							delete p0;
							return 1;
						}
						else if (p->aleft == 0)
						{
							p0 = p;
							p = p->aright;
							delete p0;
							return 1;
						}
						else
						{
							qq = &p->aleft;
							while ((*qq)->aright != 0)
								qq = &(*qq)->aright;
							p->data = (*qq)->data;
							(*qq)->data = x;
							if (del(p->aleft,x))
							{
								p->balfactor++;
								if (p->balfactor == 0)
									deltaH = 1;
								else if (p->balfactor == 2)
								{
									if (p->aright->balfactor == -1)
										rotateright(p->aright);
									rotateleft(p);
									if (p->balfactor == 0)
										deltaH = 1;
								}
							}
						}
					}
					return deltaH;
				}


template <class T>
void AVLtree<T> :: disp(const AVLnode<T>* p,ofstream& outf)
				{
					if (p)
					{
						disp(p->aleft,outf);
						outf << p->data << ' ' << p->balfactor << endl;
						disp(p->aright,outf);
					}
				}

template <class T>
void AVLtree<T> ::calav(AVLnode<T>* t,double& av)
				{
					if (t)
					{
						calav(t->aleft,av);
						av += t->data;
						calav(t->aright,av);
					}
				}

template <class T>
void AVLtree<T> ::printlist(ofstream& outf)
				{
				AVLnode<T>* t= AVLroot;

				disp(t,outf);

			}


template <class T>
AVLnode<T>* AVLtree<T> :: findnode(const T& value,AVLnode<T>*& parent)
			{
				AVLnode<T>* findptr = AVLroot;
				parent = 0;

				while (findptr != NULL)
				{
					if (value == findptr->data)
						break;
					else
					{
						parent = findptr;
						if (value < findptr->data)
						{
							findptr = findptr->aleft;
							++comparison;
						}
						else
						{
							findptr = findptr->aright;
							++comparison;
						}
					}
				}
				return findptr;
			}

template <class T>
bool AVLtree<T> ::find(const T& item,int& success,int& failure,long int& 
com)
			{
				AVLnode<T>* parent;
				current = findnode(item,parent);
				com = comparison;
				if (current != NULL)
				{
					++success;
					return true;
				}
				else
				{
					++failure;
					return false;
				}
			}

template <class T>
T AVLtree<T> :: minimum()
			{
				AVLnode<T>* currptr = AVLroot;

				if (AVLroot !=0)
				{
					while (currptr->aleft !=0)
						currptr = currptr->aleft;

					return currptr->data;
				}
				else
					return 0;
			}

template <class T>
T AVLtree<T> :: maximum()
			{
				AVLnode<T>* currptr = AVLroot;

				if (AVLroot !=0)
				{
					while (currptr->aright !=0)
						currptr = currptr->aright;

					return currptr->data;
				}
				else
					return 0;
			}


template <class T>
double AVLtree<T> :: average(double& avera)
{
				AVLnode<T>* t = AVLroot;		
				calav(t,avera);
				return avera;
}

template <class T>

void cmt(const AVLtree<T>& a)
{
	AVLroot = createmirrortree(a.root);
}


template <class T>
AVLnode<T>* AVLtree<T>  :: createmirrortree(AVLnode<T>* t)
		{
			AVLnode<T>* newlptr,*newrptr,*newnode;

			if (t == 0)
				return 0;

			if (t->aleft != 0)
				newlptr = copytree(t->aleft);
			else
				newlptr = 0;
			if (t->aright != 0)
				newrptr = copytree(t->aright);
			else
				newrptr = 0;

			newnode = new AVLnode<T>(t->data,newrptr,newlptr);

			return newnode;
		}





//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////



int main(int argc,char* argv[])

{
	if (argc < 3)
	{
		cerr << "Invalid Number of arguments" << endl;
		cerr << "Usage: HugeIntDriver inFile outFile" << endl;

		return 1;
	}

	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	ifstream inf(argv[1]);
	if ( !outfile )
	{
		cerr << "unable to create output file" << endl;
		return 2;
	}

	if ( !infile )
	{
		cerr << "unable to open input file" << endl;
		return 3;
	}


	int a = 0;
	int b = 0;
	for (int k =3;k<strlen(argv[1]);k++)
	{
		if (argv[1][k] >= '0' && argv[1][k] <= '9')
		{
			a = argv[1][k];
			a -= 48;
			b += a;
		}

		if (a == 0)
		 b *= 10;
		a = 1;

	}

	b *= 100;
	AVLtree<long int> avtree;
	BSTREE<long int> b1;
	BSTREE<double> time;
	AVLtree<long int> compar;
	BSTREE<double> timeb;
	AVLtree<long int> comparb;
	
	infile >> avtree;

	inf >> b1;

	int success = 0;
	int failure = 0;
	int successb = 0;
	int failureb = 0;
	long int com = 0;
	long int comb = 0;
	double avera = 0;
	for (int j = 0;j < 500;j++)
	{
		long int a = rand();
		long int runningTime = 0;
		__int64 freq;
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		__int64 startTime,stopTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&startTime);
		
		bool achk = avtree.find(a,success,failure,com);
		
		QueryPerformanceCounter((LARGE_INTEGER*)&stopTime);
		
		runningTime=((stopTime-startTime)*1000000)/freq;
		if (achk)
		{
			compar.insert(com);
			time.insert(runningTime);
		}

		long int a1 = rand();
		
		long int runningTime1;
		__int64 freq1;
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq1);
		__int64 startTime1,stopTime1;
		QueryPerformanceCounter((LARGE_INTEGER*)&startTime1);
		bool bchk = b1.find(a1,successb,failureb,comb);
		QueryPerformanceCounter((LARGE_INTEGER*)&stopTime1);
		runningTime1=((stopTime1-startTime1)*1000000)/freq1;

		


		if (bchk)
		{
			comparb.insert(comb);
			timeb.insert(runningTime1);
		}
		com = 0;
		comb = 0;
	}


	outfile << "Success of AVL= " << success << endl;
	outfile << "Failure of AVL= " << failure << endl;
	outfile << "Success of BST= " << successb << endl;
	outfile << "Failure of BST= " << failureb << endl;
	outfile << "Maximum comparison of AVL = " << compar.maximum() << endl;
	outfile << "Average comparison of AVL = " << compar.average(avera) / success << endl;
	outfile << "Minimum comparison of AVL = " << compar.minimum() << endl;
	avera = 0;
	outfile << "Maximum comparison of BST = " << comparb.maximum() << endl;
	outfile << "Average comparison of BST = " << comparb.average(avera) / successb << endl;
	outfile << "Minimum comparison of BST = " << comparb.minimum() << endl;
	avera = 0;
	outfile << "Maximum time of AVL = " << time.maximum() << " micro seconds " << endl;
	outfile << "Average time of AVL = " << time.average(avera) / success << " micro seconds " << endl;
	outfile << "Minimum time of AVL = " << time.minimum() << " micro seconds " << endl;
	avera = 0;
	outfile << "Maximum time of BST = " << timeb.maximum() << " micro seconds " << endl;
	outfile << "Average time of BST = " << timeb.average(avera) / successb << " micro seconds " << endl;
	outfile << "Minimum time of BST = " << timeb.minimum() << " micro seconds " << endl;
	return 0;
}



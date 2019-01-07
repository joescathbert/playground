#include<iostream>
using namespace std;
class Node
{
	int data,height;
	Node *left,*right,*parent;
	void heightCalc(Node *temp)
	{
		if(temp->left != NULL && temp->right != NULL)
			temp->height = (temp->left->height>temp->right->height)?(1+temp->left->height):(1+temp->right->height);
		else if(temp->left != NULL)
			temp->height = 1+temp->left->height;
		else if(temp->right != NULL)
			temp->height = 1+temp->right->height;
		else
			temp->height = 1;
	}
	int slope(Node *temp)
	{
		if(temp->left != NULL && temp->right != NULL)
			return temp->left->height-temp->right->height;
		else if(temp->left != NULL)
			return temp->left->height;
		else if(temp->right != NULL)
			return 0-temp->right->height;
		return 0;

	}
	void rightRotate(Node *temp)
	{
		int a,b;
		Node *n1,*n2,*n3;
		a = temp->data;
		b = temp->left->data;
		n1 = temp->left->left;
		n2 = temp->left->right;
		n3 = temp->right;
		
		temp->data = b;
		temp->right = temp->left;
		temp->right->data = a;
		temp->left = n1;
		if(n1 != NULL)
			temp->left->parent = temp;
		temp->right->left = n2;
		if(n2 != NULL)
		    temp->right->left->parent = temp->right;
		temp->right->right = n3;
		if(n3 != NULL)
			temp->right->right->parent = temp->right;
		heightCalc(temp->right);
		heightCalc(temp);
		//cout<<temp->right->height<<endl;
	}
	void leftRotate(Node *temp)
	{
		int a,b;
		Node *n1,*n2,*n3;
		a = temp->data;
		b = temp->right->data;
		n1 = temp->left;
		n2 = temp->right->left;
		n3 = temp->right->right;
		
		temp->data = b;
		//temp->right = new Node(a);
		temp->left = temp->right;
		temp->left->data = a;
		//temp->right->parent = temp;
		temp->right = n3;
		if(n3 != NULL)
			temp->right->parent = temp;
		temp->left->left = n1;
		if(n1 != NULL)
			temp->left->left->parent = temp->left;
		temp->left->right = n2;
		if(n2 != NULL)
			temp->left->right->parent = temp->left;	
		heightCalc(temp->left);
		heightCalc(temp);
	}
	void balance(Node *temp)
	{
		if(slope(temp)==+2)
		{
			if(slope(temp->left)==-1)
				leftRotate(temp->left);
			rightRotate(temp);
		}
		else if(slope(temp)==-2)
		{
			if(slope(temp->right)==1)
				rightRotate(temp->right);
			leftRotate(temp);
		}
	}
	void deleten(Node *temp)
	{
		if(temp->left == NULL && temp->right == NULL)
    		deleteLeaf(temp);
		else if(temp->left != NULL && temp->right == NULL)
			deleteOneChild(temp,0);
		else if(temp->left == NULL && temp->right != NULL)
			deleteOneChild(temp,1);
		else if(temp->left != NULL && temp->right != NULL)
			deleteChild(temp);
	}
	void heightBalDel(Node *temp)
	{
		while(temp->parent != NULL)
		{
			balance(temp);
			heightCalc(temp);
			temp = temp->parent;
		}
		balance(temp);
		heightCalc(temp);
	}
	void deleteLeaf(Node *temp)
	{
		if(temp->data > temp->parent->data)
		{
			temp->parent->right = NULL;
			heightBalDel(temp->parent);
			temp->parent = NULL;
		}
		else if(temp->data < temp->parent->data)
		{
			temp->parent->left = NULL;
			heightBalDel(temp->parent);
			temp->parent = NULL;
		}
	}
	void deleteOneChild(Node *temp,int ch)
	{
		if(ch == 0)
		{
			if(temp->data > temp->parent->data)
			{
				temp->parent->right = temp->left;
				heightBalDel(temp->parent);
				temp->parent = NULL;
				temp->left = NULL;
			}
			else if(temp->data < temp->parent->data)
			{
				temp->parent->left = temp->left;
				heightBalDel(temp->parent);
				temp->parent = NULL;
				temp->left = NULL;
			}
		}
		else if(ch == 1)
		{
			if(temp->data > temp->parent->data)
			{
				temp->parent->right = temp->right;
				heightBalDel(temp->parent);
				temp->parent = NULL;
				temp->right = NULL;
			}
			else if(temp->data < temp->parent->data)
			{
				temp->parent->left = temp->right;
				heightBalDel(temp->parent);
				temp->parent = NULL;
				temp->right = NULL;
			}
		}
	}
    void deleteChild(Node *temp)
    {
    	Node *pr;
    	pr = predn(temp->data);
    	temp->data = pr->data;
    	deleten(pr);
	}
	Node *findn(int t)
	{
		Node *temp = this;
		while(temp != NULL)
		{
			if(temp->data == t)
			    return temp;
			else if(t<temp->data)
			    temp = temp->left;
			else if(t>temp->data)
			    temp = temp->right;
		}
		return NULL;
    }
	Node *predn(int n)
	{
		Node *temp; 
		temp = findn(n);
		if(temp->left != NULL)
			return maxin(temp->left);
		else
		{
			while(temp->parent != NULL && temp == temp->parent->left)
			{
				temp = temp->parent;
			}
		}
		return temp->parent;
	}
	Node *succn(int n)
	{
		Node *temp;
		temp = findn(n);
		if(temp->right != NULL)
			return minin(temp->right);
		else
		{
			while(temp->parent != NULL && temp == temp->parent->right)
			{
				temp = temp->parent;
			}
		}
		return temp->parent;
	}
	Node *maxin(Node *temp)
	{
		while(temp->right != NULL)
		    temp = temp->right;
		return temp;
	}
	Node *minin(Node *temp)
	{
		while(temp->left != NULL)
		    temp = temp->left;
		return temp;
	}
	public:
		Node(int d)
		{
			this->data = d;
			height = 1;
			left = NULL;
			right = NULL;
			parent = NULL;
		}
		int maxi(Node *temp)
		{
			while(temp->right != NULL)
			    temp = temp->right;
			return temp->data;
		}
		int mini(Node *temp)
		{
			while(temp->left != NULL)
			    temp = temp->left;
			return temp->data;
		}
		int pred(int n)
		{
			Node *temp; 
			temp = findn(n);
			if(temp->left != NULL)
				return maxi(temp->left);
			else
			{
				while(temp->parent != NULL && temp == temp->parent->left)
				{
					temp = temp->parent;
				}
			}
			return temp->parent->data;
		}
		int succ(int n)
		{
			Node *temp;
			temp = findn(n);
			if(temp->right != NULL)
				return mini(temp->right);
			else
			{
				while(temp->parent != NULL && temp == temp->parent->right)
				{
					temp = temp->parent;
				}
			}
			return temp->parent->data;
		}
		void insert(int d)
		{
			if(d < this->data)
			{
			    if(left == NULL)
			    {
			    	left = new Node(d);
			    	left->parent = this;
					heightCalc(this);
			    	//cout<<"lheight:"<<height<<data<<endl;
				}
				else
				{
					left->insert(d);
					balance(this);
					heightCalc(this);
					//cout<<"lheight:"<<height<<data<<endl;
				}
			}
			else if(d > this->data)
			{
				if(right == NULL)
				{
					right = new Node(d);
					right->parent = this;
					heightCalc(this);
					//cout<<"rheight:"<<height<<data<<endl;
				}
				else
				{
					right->insert(d);
					balance(this);
					heightCalc(this);
					//cout<<"rheight:"<<height<<data<<endl;
				}
			}
		}
		int find(int t)
		{
			Node *temp = this;
			while(temp != NULL)
			{
				if(temp->data == t)
				    return 1;
				else if(t<temp->data)
				    temp = temp->left;
				else if(t>temp->data)
				    temp = temp->right;
			}
			return 0;
	    }
	    void deleteN(int n)
	    {
	    	Node *temp;
	    	temp = findn(n);
	    	deleten(temp);
		}
		void inOrder()
		{
			if(left != NULL)
			{
				left->inOrder();	
			}
			cout<<this->data<<" "<<this->height<<endl;
			if(right != NULL)
			{
				right->inOrder();
			}	
		}
		
};
main()
{
	Node root(7);
	root.insert(4);
	root.insert(9);
	root.insert(1);
	root.insert(2);
	root.insert(8);
	root.insert(10);
	root.deleteN(4);
	root.inOrder();
    
}

#include<iostream>
using namespace std;



template<typename T>
class list {
    list* next;
    T* data;
 
public:
    list()
    {
        next = NULL;
        data = NULL;
    }
 
    list(T* data)
    {
        set(data);
        next = new list();
    }
 
    ~list()
    {
        delete next;
    }
 
//  list(const list& c) {
//  }
 
    list& operator=(const list& c) {
        int l = c.len();
        this->data = c->data;
        list<T>* prev = this;
        list<T>* old = c->next;
        for (int i = 0 ; i < l - 1; i ++)
        {
            list * n = new list<T>();
            n->data = old.get();
            prev->next = n;
            prev = n;
            old = old->next;
        }
        list * m = new list<T>();
        prev->next = m;
    }
 
 
    int len()
    {
        if (next == NULL)
        {
            return 0;
        }
        return next->len() + 1;
    }
 
    void add(T* data) {
        if (next == NULL)
        {
            list* tmp = new list();
            tmp->next = NULL;
            tmp->data = NULL;
            this->next = tmp;
            this->data = data;
            return;
        }
        if (next->next == NULL)
        {
            list* tmp = new list();
            tmp->next = next;
            tmp->data = data;
            next = tmp;
            return;
        }
        next->add(data);
    }
    
    void print()
    {
    	if(next!=NULL)
    	{
    		cout<<data<<endl;
    		next->print();
    	}
    	return;
    }
    
    void remove (int index)
    {
    /*	if(next==NULL)
    	{
    		delete this;
    		return;
    	}
    	delete (this->data);
    	list * tmp = next;
		delete this;
    	tmp->remove();*/
    	if(next == NULL || this->len() <= index)
    	return;
    	
		list *point = this;
    	int i = 0;
		while((i != index) && (point->next->next != NULL))
		{
			i++;
			point = point->next;
			
		}
		delete point->data;
		point->data = point->next->data;
		list * tmp = point->next->next;
		delete point->next;
		point->next = tmp;
		return;
    }
    
    
    
    void set(T* data) {this->data = data;}
    T* get() {return data;}
};


 


int main()
{//while(true)
//{
list<char>* L = new list<char>();
	for(int i=0;i<5;i++)
	{
		char* C = new char[20];
		C[0] = 70+i;
		C[1] = '\0';
		L->add(C);	
}
	L->print();
	L->remove(0);
	L->remove(900);
//	L->remove(1);
//	L->print();
		/*while(true){char* A = new char[20];
		L->add(A);
		L->remove(40000);}*/
	
}

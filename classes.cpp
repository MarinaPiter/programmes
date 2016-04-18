#include <iostream>



using namespace std;



ostream& operator<<(ostream& o, string& s)

{

o << s.c_str();

return o;

}



istream& operator>>(istream& i, string& s)

{

char buf[256];

i >> buf;

string tmp(buf);

s = tmp;



return i;

}





template<typename T>

class AbstractList

{

protected:

T _default;

public :

virtual void sort(bool (*f) (T* first, T* second)) = 0;

virtual T get(int index) = 0;

virtual void set(int index, T data) = 0;

virtual void insert(int index, T data) = 0;

virtual T remove(int index) = 0;

virtual int len() = 0;

void push(T data)

{
//cout<<"2";
insert(0, data);

}

virtual T pop()

{

if (empty())

return _default;

else

return remove(0);

}



virtual bool empty()

{

return len() == 0;

}



virtual ostream& print(ostream& o)

{

for (int i = 0; i < len(); i ++)

{

o << get(i) << endl;

}

return o;

}



virtual istream& read(istream& in)

{

int count;

in >> count;
for (int i = 0 ; i < count ; i ++)
{

T tmp;

in >> tmp;

insert(len(), tmp);

}

return in;

}



};



template<typename T>

class zuzu : public AbstractList<T>

{

T _data;

zuzu* next;

protected:

T _default;

public :

zuzu()
{
    this->next = NULL;
}

zuzu(T def, T data)

{

this->_data = data;

this->_default = def;

this->next = NULL;

}

virtual ~zuzu()
{
    if(next!=NULL)
        delete next;
}

virtual T get(int index)

{

zuzu* tmp = this;

if (index >= len())

return _default;

for(int i = 0; i < index; i++)

{

if(next==NULL)

return tmp->_default;

tmp = tmp->next;

}

return tmp->_data;

}

virtual void set(int index, T data)

{

zuzu* tmp = this;

for(int i = 0; i < index; i++)

{

if(next!=NULL)

tmp = tmp->next;

}

tmp->_data = data;

}

virtual void insert(int index, T data)
{
zuzu* a = new zuzu (_default, data);
zuzu* tmp = this;
if(index == 0)
{
    this->_data = a->_data;
    //this->next = tmp;
    tmp->next = this->next;
    this->next = tmp;
    delete a;
}
else
{
    for(int i = 0; i < index; i++)
     {
        if(next!=NULL)
        tmp = tmp->next;
     }
    a->next = tmp->next;
    tmp->next = a;
}
}

virtual T remove(int index)

{

    if(len() == 0)
    {
       return this->_default;
    }
zuzu* tmp = this;
if(index == 0)
{
  T str = this->_data;
  this->_data = this->next->_data;
   //this->next = this->next->next;
  tmp = this->next->next;
  this->next->next = NULL;
  delete this->next;
  this->next = tmp;
  return str;
}
else
{
for(int i = 1; i <= index; i++)

{

    if(tmp->next != NULL)

    tmp = tmp->next;

    }

        zuzu* del = tmp->next;

        T Str = del->_data;

        tmp->next = tmp->next->next;

        del->next = NULL;

        delete del;

        return Str;

    }
}

/*
virtual zuzu* operator = (zuzu* a)
{
    this->_data = a->_data;
    this->next = a->next;
    this->_default = a->_default;
    return this;
}*/

virtual int len()

{
int i=0;
zuzu* tmp = this;
while(tmp->next != NULL)
    {
     i++;
     tmp = tmp->next;
    }
 return i;
}


virtual void sort(bool (*f) (T* first, T* second))

{

zuzu* tmp = this;

zuzu* prev = this;

zuzu* tmp1 = this;

zuzu* future = this;

for(int i = 0; i<len(); i++)

{

for(int n = 0; n<len()-1; n++)

{

if(f(&(tmp->_data), &(tmp->next->_data)) == true)

{

tmp1 = tmp->next;

future = tmp->next->next;

prev->next = tmp1;

tmp1->next = tmp;

tmp->next = future;

}

prev = tmp;

tmp = tmp->next;

}

}



}



};



template <typename T>

bool morer (T* first, T* second)

{

return *first>*second;

}



AbstractList<string>* get_init()

{

string e("EMPTY!");

string d("Hello world!");

zuzu<string>* s = new zuzu<string>(e, d);

string test("test");

s->set(0, test);

return s;

}



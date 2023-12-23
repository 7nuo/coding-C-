#include <iostream>

using namespace std;

class List { // 创建一个List类
public:
    List(){create_List();} //创建一个公共构造函数，创建List类的实例时会被调用
    ~List(){clear();}

    void create_List();
    void insert(const int& d);//const是为了防止该值在函数中被修改，int&是引用，避免了对函数参数的引用，提升了效率
    void print();
    void insert_pos(const int& d,const int& d1);
    void erase(const int& d);
    void update(const int& d,const int& d1);
    void reverse();
private:
    struct Node{
        int data;
        Node * next;
        Node(const int& d):data(d),next(NULL){}  //有{}是为了定义构造函数的主体
    };
    Node * head; //创建头节点
    //链表清理函数，将所有链表都删除
    void clear()
    {
        Node * p = head; //将指针p指向头节点
        while(p)//直到p指向null后
        {
            Node * q = p->next;
            delete p;
            p = q; //现在p指向下一个节点
        }
    }

    //查找数据d的上一个节点位置的函数
    //方便后面的删除操作
    Node* find(const int& d)
    {
        Node * p = head;//创建一个指向头节点的函数
        for(;p;p=p->next) 
        // 第一个为不进行初始化操作，第二个为检查p是否为非空，第三个为p指向下一个节点
        {
            if(p->next->data == d) //寻找下一个节点的值是否为d
            {
                break;
            }
        }
        return p;
    }
};
    
//创建头节点    
void List::create_List()
{
    head = new Node(0);
}
//从头插入一个节点
void List::insert(const int& d)
{
    Node * p = new Node(d);
    p->next = head->next;
    head->next = p;
}
//打印函数
void List::print()
{
    for(Node * p=head->next;p;p=p->next)
    {
        cout << p->data << endl;
    }
}
//在d位置之前插入d1
void List::insert_pos(const int& d,const int& d1)
{
    Node * p = find(d);
    Node * q = new Node(d1);
    q->next = p->next;
    p->next = q;
}
//删除节点
void List::erase(const int& d)
{
    Node * p = find(d);
    Node *q = p->next;
    p->next = p->next->next;
    delete q;
}
//修改指定数据
void List::update(const int& d,const int& d1)
{
    Node * p = find(d);
    p->next->data = d1;
}
//反转链表
void List::reverse()
{
    Node * p = head->next;
    Node * q = head->next->next;
    Node * o = head->next->next->next;
    p->next = NULL;
    while(o)
    {
        q->next = p;
        p=q,q=o;
        o = o->next; 
    }
    q->next = p;
    head->next = q;
}

int main()
 //为什么要这么写int main呢？因为main函数需要接受一些参数
{
    List list;
    list.insert(10);
    list.insert(20);
    list.print();
    list.reverse();
    list.print();

    return 0;
}
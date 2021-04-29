#include <iterator>
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next, * prev;
};
class DoubleList
{
public:
    DoubleList();
    DoubleList(const DoubleList&);
    void push_back(int x);
    void push_front(int x);
    void pop_back();
    void pop_front();
    int size();
    bool empty();
    void print();
    bool operator==(DoubleList& list);
    static DoubleList& merge(const DoubleList& list1, DoubleList& list2);
private:
    Node* Head, * Tail;
    int Size;
};
DoubleList::DoubleList(const DoubleList& List)
{
    Head = nullptr;
    Tail = nullptr;
    Size = 0;
    int variable = 0;
    Node* tmp = List.Head;
    while (variable != List.Size)
    {
        push_back(tmp->value);
        tmp = tmp->next;
        variable++;
    }
}
void DoubleList::print() {
    Node* current = Head;
    while (current != nullptr)
    {
        cout << current->value << ' ';
        current = current->next;
    }
    cout << endl;
}
bool DoubleList::empty()
{
    if (Size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int DoubleList::size()
{
    return Size;
}
DoubleList::DoubleList()
{
    Size = 0;
    Head = nullptr;
    Tail = nullptr;
}
void DoubleList::push_back(int x)
{
    Node* tmp = new Node;
    Node* last = new Node;
    last->value = 0;
    last->prev = tmp;
    tmp->next = last;
    tmp->prev = Tail;
    tmp->value = x;
    if (Tail != nullptr)
    {
        Tail->next = tmp;
    }
    Tail = tmp;
    Tail->next = nullptr;
    if (Size == 0)
    {
        Head = tmp;
    }
    Size++;
}
void DoubleList::push_front(int x)
{
    Node* tmp = new Node;
    tmp->next = Head;
    tmp->prev = nullptr;
    tmp->value = x;
    if (Head != nullptr)
    {
        Head->prev = tmp;
    }
    Head = tmp;
    if (Size == 0)
    {
        Tail = tmp;
    }
    Size++;
}
void DoubleList::pop_front()
{
    Node* tmp = Head->next;
    tmp->prev = nullptr;
    delete Head;
    Head = tmp;
    Size--;
}
void DoubleList::pop_back()
{
    Node* tmp = Tail->prev;
    Node* last = new Node;
    last->value = 0;
    last->prev = tmp;
    tmp->next = last;
    delete Tail;
    Tail = tmp;
    Size--;
}
bool DoubleList::operator==(DoubleList& list){
    if (Size != list.Size) {
        return false;
    }
    Node* current1 = Head;
    Node* current2 = list.Head;
    if (current1 && current2) {
        while (current1->next != nullptr && current2->next != nullptr) {
            if (current1->value != current2->value) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        return true;
    }
    return false;
}
DoubleList& DoubleList::merge(const DoubleList& list1, DoubleList& list2)
{
    DoubleList* res = new DoubleList();
    Node* last = res->Head;
    Node* i = list1.Head;
    Node* j = list2.Head;
    while (i && j) 
    {
        if (last != nullptr && last->value == i->value) 
        {
            i = i->next;
            continue;
        }
        if (last != nullptr && last->value == j->value) 
        {
            j = j->next;
            continue;
        }
        if (i->value < j->value)
        {
            res->push_back(i->value);
            last = i;
            i = i->next;
        }
        else if (i->value > j->value) 
        {
            res->push_back(j->value);
            last = j;
            j = j->next;
        }
        else {
            res->push_back(j->value);
            last = j;
            while (i && i->next && i->value == i->next->value) 
            {
                i = i->next;
            }
            while (j && j->next && j->value == j->next->value)
            {
                j = j->next;
            }
        }
    }
    while (i) {
        if (last == nullptr || last->value != i->value) 
        {
            res->push_back(i->value);
            last = i;
            i = i->next;
        }
        else {
            i = i->next;
        }
    }
    while (j) {
        if (last == nullptr || last->value != j->value)
        {
            res->push_back(j->value);
            last = j;
            j = j->next;
        }
        else {
            j = j->next;
        }
    }
    return *res;
}
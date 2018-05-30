#include <cstdio>
#include <cstdlib>

#define MaxNum 10000
typedef int VALUE_TYPE;

struct Link_list {
    struct Node
    {
        VALUE_TYPE val;
        Node * next;
    } Node;
    Node *front;
    int length;
    Link_list() :front(NULL),length(0) {}
    bool insert_val(int pos, VALUE_TYPE value) {
        if(pos<0||pos>=length)
        {

        }
    }
    bool delete_val(int pos, VALUE_TYPE &value) {

    }
};

int main() {
    Link_list list;

    scanf("%d",)
    for(int i =0;i<10;i++)
    {
        list.insert_val(0,i);
    }
    int ab;
    list.delete_val(3,ab);
    printf("%d\n",ab);
    for(int i =0 ;i<list.length;i++)
    {
        printf("%d\n",list.val[i]);
    }
    return 0;
}

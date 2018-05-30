#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
#define MaxNum 10000
typedef int VALUE_TYPE;

struct Sqlist {
    VALUE_TYPE *val;
    int length ;
    int listsize;

    explicit Sqlist(int ls) : listsize(ls) {
        val = (VALUE_TYPE *) malloc(ls * sizeof(VALUE_TYPE));
        if (!val) {
            return;
        }
    }

    Sqlist() {
        val = (VALUE_TYPE *) malloc(MaxNum * sizeof(VALUE_TYPE));
        if (!val) {
            return;
        }
    }

    bool delete_val(int pos, VALUE_TYPE &value) {
        if (pos >= length || pos < 0) {
            return false;
        } else {
            value = val[pos];
            for (int i = pos; i < length; i++) {
                val[i] = val[i + 1];
            }
            length--;
            return true;
        }
    }

    bool insert_val(int pos, VALUE_TYPE value) {
        if (pos > length || pos < 0) {
            return false;
        } else if (length >= listsize) {
            VALUE_TYPE *newbase = (VALUE_TYPE *) realloc(val, int(listsize * 1.5) * sizeof(VALUE_TYPE));
            if (!newbase)
                return false;
            val = newbase;
            listsize = int(listsize * 1.5);
        }
        length++;
        for (int i = length; i > pos; i--) {
            val[i] = val[i - 1];
        }
        val[pos] = value;
        return true;
    }
};

int main() {
    Sqlist list(100);
    srand(time(NULL));
    for(int i =0;i<10;i++)
    {
        list.insert_val(list.length,random()%1000);
    }
    for(int i =0 ;i<list.length;i++)
    {
        printf("%d   ",list.val[i]);
    }
    cout<<endl;
    int pos,val;
    cout<<"请输入你要插入的位置和值，ctr+c继续"<<endl;
    while(cin>>pos>>val)
    {

        list.insert_val(pos,val);
        cout<<"新序列"<<endl;
        for(int i =0 ;i<list.length;i++)
        {
            printf("%d  ",list.val[i]);
        }
        cout<<endl;
        cout<<"请输入你要插入的位置和值，ctr+c继续"<<endl;
    }
    cout<<"请输入你要删除的位置，ctr+c继续"<<endl;
    while(cin>>pos)
    {

        int value;
        list.insert_val(pos,value);
        cout<<"删除的元素为"<<value<<"，下面是新序列"<<endl;
        for(int i =0 ;i<list.length;i++)
        {
            printf("%d  ",list.val[i]);
        }
        cout<<endl;
        cout<<"请输入你要插入的位置和值，ctr+c继续"<<endl;
    }
    return 0;
}

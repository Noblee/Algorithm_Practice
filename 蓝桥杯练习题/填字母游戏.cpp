#include "iostream"
#include "algorithm"
using namespace std;
//先仅从我方出发
//如果针对某一当前状态，只要有一次试探得出的结果能赢，那么就能赢，否则为平局


int is_lol(string x){
    /*1表示能赢
    0表示平局 
    -1表示输 
    */
    int len=x.length(); 
    if(x.find("LOL")!=string::npos) return -1;//当我方开始填时已出现LOL时，则我方输 
    if(x.find("*")==string::npos) return 0;//当没有出现LOL时，且没有空格则为平局 
    int ping=0;//先假设为平局 
    for(int i=0;i<len;i++){
	        if(x[i]=='*'){
	            x[i]='L';
	            switch(is_lol(x))
	            {
	                case -1: return 1;//当我方填完后，出现LOL,则我方赢 
	                case 0: ping=1;//当我方填完后,没有空格,则为平局 
	            }
	            x[i]='O';
	                switch(is_lol(x))
	            {
	                case -1: return 1;//当我方填完后，出现LOL,则我方赢 
	                case 0: ping=1;//当我方填完后,没有空格,则为平局 
	            }
	            x[i]='*';
	    }
    }
    //能到这里说明
    if(ping) return 0;//如果存在平局，则结果为平局,否则即输 
    return -1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin>>str;
		cout<<is_lol(str)<<endl;
	}
	return 0;
}

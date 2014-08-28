#include <iostream>


using namespace std;


template<class T>
class Binary_Index_Tree{
public:
    T * a;
    T * c;
    int size;
    Binary_Index_Tree(T * b,int size){
        if(b==NULL) return;
        a=new T[size+1];
        c=new T[size+1];
        this->size=size+1;
        for(int i=0;i<size+1;i++){
            a[i]=0;
            c[i]=0;
        }
        for(int i=1;i<=size;i++){
            a[i]=b[i-1];
            add(i, a[i]);
        }
    }

    T sum(int i){
        i++;
        T sum=0;
        while(i>=1){
            sum += c[i];
            i-=lowbit(i);
        }
        return sum;
    }

    T query(int l,int r){
        T res= sum(r)-sum(l)+a[l];
        return res;
    }


    T get(int i){
        return a[i+1];
    }

    T set(int i,int v){
        i++;
        int d=v-a[i];
        a[i] = v;
        add(i,d);
    }


private:
    int lowbit (int x){
        return x&(-x);
    } ;

    void add(int i,T v){
        while(i>=1&&i<this->size){
            c[i]+=v;
            i+=lowbit(i);
        }
    }

};

int main()
{
    double d[4]={0.1,0.2,0.3,0.1};
    double * t=d;
    Binary_Index_Tree<double> test(t,4);
    cout<<test.sum(1);
    return 0;
}

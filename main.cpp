#include <iostream>
#include "stdio.h"

int Ex1(int res){
    int n;
    return  1<<res;
};

void Ex2(int res){
    int i=1024;
    while(i >0){
       if ((res & i)!=0){
           std:: cout << 1;
       }else std:: cout << 0;
       i = (i >> 1);
    }
}

int Ex3(int res){
    int CountOne=0;
    int i=1;
    int b=res;
    while(res > 0){
        if ((b & i)!=0){
            CountOne+=1;
        }
        res = (res>>1);
        i = (i << 1);
    }
    return CountOne;
}

int Ex4(int res){
    int NumOne=-1; //  нумерация идет от 0
    int i=1;
    int b=res;
    while(res > 0){
        NumOne+=1;
        res = (res>>1);
        i = (i << 1);
    }
    if(NumOne<0){
        return NumOne=0;
    }else return NumOne;
}

int Ex5(int n, int i){
    int j=0;
    while(j < 10){
        if (j == i){
            if ((n & (1<<j))==0){
                n=n|(1<<i);
            }
        }
        j+=1;
    }
    return n;
}

int Ex6(int n, int i){
    int j=0;
    while(j < 10){
        if (j == i){
            if ((n & (1<<j))!=0){
                n-=(1<<i);
            }
        }
        j+=1;
    }
    return n;
}

int Ex7(int n, int i){
    int j=0;
    while(j < 10){
        if (j == i){
            if ((n & (1<<j))==0){
                n=n|(1<<i);
            }else{
                n-=(1<<i);
            }
        }
        j+=1;
    }
    return n;
}

int Ex8(int n){
    int prev = n & 1;
    int res=0;
    for (int i = 1; i<8; i++){
        res = res|(prev<<1);
        prev = (n & (1<<i));
    }
    if ((n & (1<<7))!=0){
        res = res | 1;
    }
    return(res);
}

int Ex9(int n){
    int b=n;
    int i=2;
    int prev = n & 1;
    int CountEleven=0;
    while(n > 0){
        if (((b & i)!=0) && (prev!=0)){
            CountEleven+=1;
        }
        n = (n>>1);
        prev=b & i;
        i = (i << 1);
    }
    return CountEleven;
}

int Ex10(int n, int i, int j){
    int k=0;
    int res = 0;
    int iBit= n & (1<<i) ;
    int jBit = n & (1<<j);
    while(k < 10){
        if ((k == i)||(k == j)) {
            if (k == j) {
                res = res + (jBit<<i);
            } else {
                res = res + (iBit<<j);
            }
        }
        else{
            res = res + (n&(1<<k));
        }
        k+=1;
    }
    return res;
}

int Ex11(int n, int i ){
    int FirstPart = 0;
    int j=0;
    int b=n;
    while(j<i){
        FirstPart = FirstPart + (n&(1<<j));
        j+=1;
        b=b>>1;
    }
    int SecondPart = (n-FirstPart)>>i+1;
    int res = FirstPart+(SecondPart<<i);
    return res;
}

int main() {
    return 0;

}
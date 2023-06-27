#ifndef _MY_BIG_INT_
#define _MY_BIG_INT_

#include <iostream>
#include <cstdint>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>
#include <memory>

struct MyBigInt {
        MyBigInt() { }
        MyBigInt(int x){
           std::vector<int> tmp;
           while(x!=0){
                tmp.push_back(x%10);
                x=x/10;
           }
           size=tmp.size();
           digits=std::make_unique<int_least8_t*>(new int_least8_t[tmp.size()]);
           
           for(int i=0;i<size;i++){
              (*digits)[i]=(int_least8_t)tmp[i];
           }
        }
        
        MyBigInt(const MyBigInt& x){
           digits=std::make_unique<int_least8_t*>(new int_least8_t[x.size]);
           size=x.size;
           for(int i=0;i<x.size;i++){
              (*digits)[i]=(*x.digits)[i];
           }
        }
        
        MyBigInt(const char *s){
           int n=strlen(s);
           size=n;
           digits=std::make_unique<int_least8_t*>(new int_least8_t[n]);
           for(int i=0;i<n;i++){
              (*digits)[i]=s[n-1-i]-'0';
           }
        }
        
        ~MyBigInt(){ }
        
        
        bool operator!=(const MyBigInt& y){
            if(size!=y.size)
              return true;
            for(int i=0;i<size;i++){
               if((*digits)[i]!=(*y.digits)[i])
                 return true;
            }
            return false;  
        }
        
        bool operator==(const MyBigInt& y){
            if(size!=y.size)
              return false;
            for(int i=0;i<size;i++){
               if((*digits)[i]!=(*y.digits)[i])
                 return false;
            }
            return true;  
        }
        
        
        void operator=(const MyBigInt& y){
            size=y.size;
            digits=std::make_unique<int_least8_t*>(new int_least8_t[y.size]);
            for(int i=0;i<size;i++){
               (*digits)[i]=(int_least8_t)(*y.digits)[i];
            }
        }
        
        //friend MyBigInt operator"" _mbi(unsigned long long int  x); 
        friend MyBigInt operator"" _mbi(const char *x); 
	friend MyBigInt operator+(const MyBigInt& lhs, const MyBigInt& rhs);	

//private:  
      
        //std::unique_ptr
	std::unique_ptr<int_least8_t*> digits;
	int size = 0;
};


std::ostream& operator<<(std::ostream& s, const MyBigInt& number){
             for(int i=number.size-1;i>=0;i--){
                s << (int)(*number.digits)[i];
             }
             return s;
        }

#endif

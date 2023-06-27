#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

void error(std::string s){
   std::cerr << s << std::endl;
   exit(EXIT_FAILURE);
}

template<typename T>
auto sum(T x){
  return x;
}

template<typename T1, typename T2>
auto sum(T1 x, T2 y){
  return x+y;
}

template<typename T1, typename T2, typename... Args>
auto sum(T1 x, T2 y, Args... args){
  return x+y+sum(args...);
}


template<typename T>
auto minimum(T x){
  return x;
}


template<typename T1, typename T2>
auto minimum(T1 x, T2 y){
  return x < y ? x : y;
}

template<typename T1, typename T2, typename... Args>
auto minimum(T1 x, T2 y, Args... args){
  if(x<y)
    return minimum(x, args...);
  else
    return minimum((T1)y, args...);      
}

template<typename T>
void my_printf(T s){
   int n=strlen(s);
   for(int i=0;i<n;i++){
      if(s[i]=='%' && i+1<n && (s[i+1]=='s' || s[i+1]=='d' || s[i+1]=='f')){
        std::cerr << "\n!!Invalid number of arguments during the call of my_printf function!!\n" << std::endl;
        exit(EXIT_FAILURE);
      }
   }
   std::cout << s;
}

template<typename T1, typename T2, typename... Args>
void my_printf(T1 s, T2 x, Args... args){
   int n=strlen(s);
   int index=-1;
   for(int i=0;i<n;i++){
      if(s[i]=='%'){
        index=i;
        break;        
      } else {
        std::cout << s[i];
      }
   }
   
   if(index+1<n && s[index+1]=='d' && *(typeid(x).name())=='i'){
     std::cout << x;
   } else if(index+1<n && s[index+1]=='f' && *(typeid(x).name())=='d'){
     std::cout << x;
   } else if(index+1<n && s[index+1]=='s' && *(typeid(x).name())!='d' && *(typeid(x).name())!='f'){
     std::cout << x;
   } else {
     error("\nIncopatible types!\n");
   }
   
   s=s+index+2;
   my_printf(s, args...);
}


int main(){   
   
   /*
   char *name="Petar Tesic";
   
   int a;
   int b;
   float x;
   float y;
   
   std::cout << "----------------------------------------------------\n";
   std::cout << "Enter two integer numbers: " << std::endl;
   std:: cin >> a >> b;
   
   std::cout << "\n----------------------------------------------------\n";
   std::cout << "Now we need you to enter two double numbers: " << std::endl;
   std::cin >> x >> y;
   std::cout << "\n----------------------------------------------------\n";
   
   int result1=sum(a, b);
   float result2=sum(x, y);
   
   std::cout << "Sum of two entered integer numbers is equal to: " << result1 << ".\n";
   std::cout << "Sum of two entered double numbers is equal to: " << result2 << ".\n";
   
   std::cout << "\n----------------------------------------------------\n";
   std::cout << "Minimum of two entered integer numbers is equal to: " << min(a, b) << ".\n";
   std::cout << "Minimum of two entered double numbers is equal to: " << min(x, y) << ".\n";
   std::cout << "\n----------------------------------------------------\n";
   
   
   char *s="This is the first time we test my_printf function!\n %f %f %d %d %s\n";   
   my_printf(s, x, y, a, b, name);
   
   return 0;
   */
	
   // sum = 17.4
   cout << sum(2, 1.8, 3.8, 4, 5.8) << endl;
	
   // sum = 17.4
   cout << sum(1.8, 2, 3.8, 4, 5.8) << endl;
	
   // min = 1.1
   cout << minimum(2.2, 1.1, 4, 4, 58) << endl;
   
   // min = -58
   cout << minimum(2.2, 1.1, 4, 4, -58) << endl;

   // Test #1: OK
   my_printf("Simple check\nNew line\nAgain new line\n");
	
   // Test #2: Invalid number of arguments
   my_printf(" text %s, integral value %d than something %d\n", "SUCCESSFULLY", 85);
	
   // Test #3: Incorrect type / Invalid number of arguments
   my_printf("Some text %s, some floating point number %f again something %k\n", "45", 89.7, 56);
	
   // Test #4: OK
   my_printf("Some text %s, some floating point number %f again something %d\n", "45", 89.7, 56);

   return 0;
}

#include <iostream>
#include <cassert>

// Here you need to write the following function: 
constexpr int fibo(int n){
   int a=0;
   int b=1;
   for(int i=0;i<n;i++){
      int tmp=b;
      b=a+b;
      a=tmp;
   }
   return a;
}

int main(){
	
	static_assert(fibo(7) == 13, "Greska!");
	const int k = fibo(5);
	
	std::cout << k << std::endl;
	
	
	std::cout << "\n---------------------------------------------------------------------\n";
	for(int i=0;i<20;i++){
	   std::cout << fibo(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "\n---------------------------------------------------------------------\n";
	
	
	std::cout << k << std::endl;
	//constexpr int l = fibo(300); // 300. Фибоначијев број је превелик за int
	
	return 0;
}

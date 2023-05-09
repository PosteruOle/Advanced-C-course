#include "MyBigInt.h"
#include <iostream>
#include <string>

/*
MyBigInt operator"" _mbi(unsigned long long int x){
    MyBigInt result(x);
    return result;
}
*/

MyBigInt operator"" _mbi(const char *x){
    MyBigInt result(x);
    return result;
}

MyBigInt operator+(const MyBigInt& lhs, const MyBigInt& rhs)
{
	MyBigInt ret;
	const MyBigInt& longerArg = (lhs.size < rhs.size) ? rhs : lhs;
	const MyBigInt& shorterArg = (lhs.size < rhs.size) ? lhs : rhs;
	ret.digits = new int_least8_t[longerArg.size + 1];
	int_least8_t reminder = 0;
	for (int i = 0; i < shorterArg.size; i++) {
		int_least8_t tempSum = longerArg.digits[i] + shorterArg.digits[i] + reminder;
		ret.digits[i] = (tempSum > 9) ? tempSum - 10 : tempSum;
		reminder = (tempSum > 9) ? 1 : 0;
	}
	for (int i = shorterArg.size; i < longerArg.size; i++) {
		int_least8_t tempSum = longerArg.digits[i] + reminder;
		ret.digits[i] = (tempSum > 9) ? tempSum - 10 : tempSum;
		reminder = (tempSum > 9) ? 1 : 0;
	}
	if (reminder == 0) {
		ret.size = longerArg.size;
	} else {
		ret.size = longerArg.size + 1;
	}
	ret.digits[longerArg.size] = reminder;
	return ret;
}

// Овде написати следећу функцију:
MyBigInt fibo(int n){
    
    MyBigInt a=0;
    MyBigInt b=1;
    std::vector<int> tmp;
    for(int i=0;i<n;i++){
       MyBigInt tmp=b;
       b=a+b;
       a=tmp;
    }
    return a;
}


int main(){       
	/*
	int_least8_t faith='0'+ 2;
	std::cout << "How should we print this? -> " << faith << std::endl;
	MyBigInt k{123};
        MyBigInt test(12345);
        
        std::cout << "---------------------------------\n";
        std::cout << test << std::endl;
        std::cout << "---------------------------------\n";
        
        std::cout << k << std::endl;
	k = fibo(9);
	std::cout << k << std::endl;
	k = k + 5;
	std::cout << k << std::endl;
	std::cout << "\n---------------------------------\n";
	for(int i=0;i<=13;i++){
	   std::cout << i << " -> " << fibo(i) << std::endl;
	}
	std::cout << "\n---------------------------------\n";
	std::cout << k << std::endl;
	k = 7 + fibo(11);
	std::cout << k << std::endl;
	std::cout << "\n---------------------------------\n";
	k = 13_mbi;
	
	std::cout << k << std::endl;
	MyBigInt l = fibo(300);
	
	//Just added!
	MyBigInt tmp=222232244629420445529739893461909967206666939096499764990979600_mbi;
	std::cout << "\n---------------------------------\n";
	std::cout << "Last checking!\n";
	std::cout << l << std::endl;
	std::cout << tmp << std::endl;
	std::cout << "\n---------------------------------\n";
	
	if (l != 222232244629420445529739893461909967206666939096499764990979600_mbi) {
		std::cout << "Greska!" << std::endl;
		return 1;
	}
	
	std::cout << l << std::endl;
	{
		MyBigInt m = l;
		std::cout << "I can't believe this works!\n";
		std::cout << m << std::endl;
	}
	std::cout << l << std::endl;
	{
		MyBigInt n = std::move(l);
		std::cout << "I can't believe this works too!\n";
		std::cout << n << std::endl;
	}
	
	return 0;
        */
        MyBigInt k{123};
	std::cout << k << std::endl;
	k = fibo(9);
	std::cout << k << std::endl;
	k = k + 5;
	std::cout << k << std::endl;
	k = 7 + fibo(11);
	std::cout << k << std::endl;
	k = 13_mbi;
	std::cout << k << std::endl;
	MyBigInt l = fibo(300);
	if (l != 222232244629420445529739893461909967206666939096499764990979600_mbi) {
		std::cout << "Greska!" << std::endl;
		return 1;
	}
	std::cout << l << std::endl;
	{
		MyBigInt m = l;
		std::cout << m << std::endl;
	}
	std::cout << l << std::endl;
	{
		MyBigInt n = std::move(l);
		std::cout << n << std::endl;
	}
	return 0;
}

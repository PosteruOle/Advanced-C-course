/*
Реализовати програм који претвара мала слова у велика слова. Формирати три
програмске нити:
1. улазна програмска нит,
2. програмска нит обраде и
3. излазна програмска нит.
Улазна програмска нит прихвата улазни карактер и смешта га у улазни кружни низ
максималне величине RING_SIZE. Програмска нит обраде преузима карактере из
улазног низа и претвара их у велика слова. Претворени карактер се затим смешта
у излазни кружни низ. Излазна програмска нит преузима карактере из излазног
кружног низа и исписује их на стандардни излаз.
*/
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <map>
#include <unistd.h>
#include <cctype>

#define RING_SIZE 1000
std::vector<char> circular_array;
int n=0;

void function1(){
    char c;
    std::cin >> c;
    circular_array.push_back(c);
    n++;
}

struct work1{
  void operator()(){}
};

struct work2{
  void operator()(std::thread input){
     input.join();
     circular_array[n-1]=std::toupper(circular_array[n-1]);
  }
};

struct work3{
  void operator()(std::thread process){
     process.join();
     std::cout << circular_array[n-1] << std::endl;
  }
};

int main(){

  std::thread input_thread(function1);
  std::thread processing_thread(work2{}, std::move(input_thread));
  std::thread output_thread(work3{}, std::move(processing_thread));
  
  //input_thread.join();
  //processing_thread.join();
  output_thread.join();

  return 0;
}

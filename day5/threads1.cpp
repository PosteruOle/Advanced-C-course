/*
Направити три нити, тако да једна исписује 1, друга 2 и трећа 3. Све три нити
направити у функцији main. Нит 1 треба да спава 3 секунде па да онда испише
свој број и заврши се. Нит 2 треба да прикључи нит 1, затим да испише свој број и
заврши се, а нит 3 треба да прикључи нит 2, испише свој број и заврши се. У
функцији main треба прикључити нит 3.
*/
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <map>
#include <unistd.h>


void print1(){
   sleep(3);
   std::cout << "1" << std::endl;
}

struct print2{
   void operator()(std::thread thread1){
       thread1.join();
       std::cout << "2" << std::endl;
   }
};

struct print3{
   void operator()(std::thread thread2){
       thread2.join();
       std::cout << "3" << std::endl;
   }
};

int main(){

  //std::thread thread1([]() { std::cout << "1" << std::endl; });
  //thread1.join();
  //std::cout << "2" << std::endl;
  std::thread thread1(print1);
  std::thread thread2(print2(), std::move(thread1));
  std::thread thread3(print3(), std::move(thread2));
  thread3.join();
  

  return 0;
}

/*
Реализовати две програмске нити. Нити треба да деле два ресурса, то јест две
целобројне променљиве. Свака променљива је заштићена са својим објектом
искључивог приступа. Прва нит уписује у дељене променљиве следеће парове:
{(1,2),(3,4),(5,6)}. Када дође до краја низа враћа се на први пар и ради све поново.
Друга нит ишчитава вредности из променљивих и сабира их. Резултат исписује на
стандардни излаз. Испис резултата треба да буде један по пару. Једине
вредности које се могу појавити као резултат сабирања су 3, 7, 11.
*/
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <map>
#include <unistd.h>
#include <mutex>

std::vector<int> tmp1={1,3,5};
std::vector<int> tmp2={2,4,6};
int n=tmp1.size();

int a=0;
int b=0;
std::mutex m;
int count=0;

void work1(){
   while(true){
      for(int j=0;j<n;j++){
         m.lock();
         a=tmp1[j];
         b=tmp2[j];
         m.unlock();  
      }
   }
}

void work2(){
   while(true){
      for(int j=0;j<n;j++){
         m.lock();
         std::cout << a+b << " ";
         count++;
         if(count==10){
           count=0;
           std::cout << std::endl;
         }
         m.unlock();  
      }
   }
}

int main(){

  std::thread thread1(work1);
  std::thread thread2(work2);
  thread1.join();
  thread2.join();
  std::cout << "Final!" << std::endl;

  return 0;
}

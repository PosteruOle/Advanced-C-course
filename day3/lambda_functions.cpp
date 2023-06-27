#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

int salary=0;
int position=0;
bool flag=false;
double reciprocnaSuma=0;

//5th request!
std::vector<int> secondVector;

void help1(int x){
   std::cout << x << " ";
}

int help2(){
   salary+=5;
   return salary;
}


//1st request!
void printVector(const std::vector<int>& vec){
    std::cout << "\n------------------------------------\n";
    for_each(vec.begin(), vec.end(), help1);
    std::cout << "\n------------------------------------\n";
}

int main(){
   
   //2nd request!
   std::vector<int> firstVector(20);
   
   printVector(firstVector);
   
   //3rd request!
   generate(firstVector.begin(), firstVector.end(), help2);
   printVector(firstVector);
   
   //4th request!
   for_each(firstVector.begin(), firstVector.end(), [](int& x) { x=x*x; });
   printVector(firstVector);
   
   //6th request!
   for_each(firstVector.begin(), firstVector.end(), [](int& x) { if(x%7!=0) secondVector.push_back(x); });
   printVector(secondVector);
   
   //7th request!
   for_each(secondVector.begin(), secondVector.end(), [](int&x){ if(x!=0) reciprocnaSuma+=1.0/x; });
   std::cout << std::endl << "reciprocnaSuma = " << reciprocnaSuma << std::endl;
   
   
   //8th request!
   secondVector.erase(std::remove_if(secondVector.begin(), secondVector.end(), [](const int& x) { return x%9==0; }), secondVector.end());
   printVector(secondVector);
   
   //9th and the last request!
   for_each(secondVector.begin(), secondVector.end(), 
            [](const int&x){ if(!flag && x%13==0){ 
                                std::cout << position << std::endl; 
                                flag=true; 
                             } 
                             position++; 
                           });
   if(!flag)
     std::cout << "We must print -1!\n";                        
   
   return 0;
}

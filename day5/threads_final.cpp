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
#include <vector>
#include <thread>
#include <cctype>
#include <mutex>
#include <condition_variable>

class Semaphore {
    int m_s = 0;
    std::mutex m_mut;
    std::condition_variable m_cv;
public:
    Semaphore() = default;
    
    Semaphore(int x) : m_s(x) {}
    
    void signal() {
        std::unique_lock<std::mutex> lock(m_mut);
        m_s += 1;
        m_cv.notify_one();
    }
    
    void wait() {
        std::unique_lock<std::mutex> lock(m_mut);
        m_cv.wait(lock, [this](){ return m_s != 0; });
        m_s -= 1;
    }
};

class RingBuffer {
    std::array<char, 10> m_buff;
    int m_w{0};
    int m_r{0};
    Semaphore m_free{10};
    Semaphore m_taken{0};
    std::mutex m_mut;
public:
    RingBuffer() = default;
    void write(char x);
    char read();
};

void RingBuffer::write(char c) {
    m_free.wait();
    std::lock_guard<std::mutex> l(m_mut);
    m_buff[m_w] = c;
    m_w = (m_w + 1) % 10;
    m_taken.signal();
}

char RingBuffer::read() {
    m_taken.wait();
    std::lock_guard<std::mutex> l(m_mut);
    char res = m_buff[m_r];
    m_r = (m_r + 1) % 10;
    m_free.signal();
    return res;
}

//Global variable we need in this exercise!
RingBuffer circular_array;

void function1(){
    while(true){
       char c;
       std::cin >> c;
       circular_array.write(c);
    }
}

void function2(){
    while(true){
       char c=circular_array.read();
       c=std::toupper(c);
       circular_array.write(c);
    }
}

void function3(){
    while(true){
       char c=circular_array.read();
       std::cout << c << " ";
    }
}

/*
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
*/

int main(){

   std::thread input_thread(function1);
   std::thread processing_thread(function2);
   std::thread output_thread(function3);
   
   input_thread.join();
   processing_thread.join();
   output_thread.join();
   

   return 0;
}

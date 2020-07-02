//重新设计下面的代码，使其可以理大数的素数与超级素数
//同时仔细理面向对象的编程式 
#include<iostream>
template <class Big>
class BigPrime{
public:
  BigPrime(int n) : num(n){
  }
  virtual bool isPrime() const {
    return false;
  }
    BigPrime(Big n) : num(n){ }
    virtual bool isPrime() const {
        int i;
        int number = num;
        for(i = 2; i < number; i++){
            if(number % i == 0) break;
        }
        if(i != number) return false;
        return true;
    }
private:
  const int num;
}; 
class BigSuperPrime : public BigPrime {
    const Big num;
};
template <class Big>
class BigSuperPrime : public BigPrime<Big> {
public:
  BigSuperPrime(int n) : BigPrime(n), num(n){
  }
  virtual bool isPrime() const {
    return true;
  }
    BigSuperPrime(Big n) : BigPrime<Big>(n), num(n){
        int number = n;
        int t;
        int Sum = 0, Multi = 1, SquareSum = 0;
        while(number >= 10){
            t = number % 10;
            number = number/10;
            Sum += t;
            Multi *= t;
            SquareSum += (t*t);
        }
        Sum += number;
        Multi *= number;
        SquareSum += (number * number);
        sum = new BigPrime<Big>(Sum);
        multi = new BigPrime<Big>(Multi);
        square = new BigPrime<Big>(SquareSum);
    }
    virtual ~BigSuperPrime(){
        delete sum;
        delete multi;
        delete square;
    }
    virtual bool isPrime() const {
        if(BigPrime<Big>::isPrime()
           &&sum->isPrime()
           && multi->isPrime()
           && square->isPrime()) return true;
        return false;
    }
private:
  const int num;
    const Big num;
    const BigPrime<Big> *sum;
    const BigPrime<Big> *multi;
    const BigPrime<Big> *square;
};
template <class T>
class Set {
class Set{
public:
  Set(int sz);
  ~Set();
  bool add(T *bp);
  bool remove(T *bp);
  int count() const {
  	int ret = 0;
  	for (int i = 0; i < index; i++) {
  	  if (pset[i]->isPrime())
  	    ret += 1;
	  }
  	return ret;
  }
  int sum() const {
  	return 0;
  } 
    Set(int sz);
    ~Set();
    bool add(T *bp);
    int count() const {
        int a = 0;
        for(int i = 0; i < index; i++){
            if(pset[i]->isPrime()) a++;
        }
        return a;
    }
    int sum() const {
        return 0;
    }
private:
  T **pset;
  int size, index;
    T **pset;
    int size, index;
};

int main() 
{
  Set<BigPrime> set(1000);
  BigSuperPrime bp(2), bp1(3);
  set.add(&bp);
  set.add(&bp1);
  std::cout << set.count() << std::endl;
  return 0;
} 
    Set< BigPrime<double> > set(1000);
    BigSuperPrime<double> bp(200), bp1(113);
    set.add(&bp);
    set.add(&bp1);
    std::cout << set.count() << std::endl;
    return 0;
}

template <class T>
Set<T>::Set(int sz):size(sz) {
  index = 0;
  pset = new T*[size];  //分配存储空间 
bool Set<T>::add(T *bp) {
    if(index > size) return false;
    pset[index] = bp;
    index++;
    return true;
}

template <class T>
Set<T>::~Set() {
  delete[] pset;  //回收 
Set<T>::Set(int sz) : size(sz) {
    index = 0;
    pset = new T*[size];
}

template <class T>
bool Set<T>::add(T *bp) {
  pset[index++] = bp;
  return true;
Set<T>::~Set() 
{
    delete[] pset;
}

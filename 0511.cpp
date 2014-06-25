#include <cstdio>
#include <cstdlib>
#include <iostream>

template<typename T>
class SmartPointer {
  public:
  SmartPointer (T* ptr)  {
    ref = ptr;
    ref_count = (unsigned*)malloc(sizeof(unsigned));
    *ref_count = 1;
    }
  SmartPointer(SmartPointer<T>& sptr) {
    ref = sptr.ref;
    ref_count = sptr.ref_count;
    ++*ref_count;
  }

  SmartPointer<T>& operator=(SmartPointer<T>& sptr) {
    if(this != sptr) {
      ref = sptr.ref;
      ref_count = sptr.ref_count;
      ++*ref_count;
    }
    return *this;
  }
  ~SmartPointer() {
    --*ref_count;
    if (*ref_count == 0) {
      delete ref;
      free(ref_count);
      ref  = NULL;
      ref_count = NULL;
    }
  }
  T* operator->() {
    return ref;
  }
  T& operator*() {
    return *ref;
  }
  protected:
  T* ref;
  unsigned* ref_count;
};

int main () {
  int num = 10;
  SmartPointer<int> ptr1(&num);
  SmartPointer<int> ptr2(ptr1);
  SmartPointer<int> ptr3 = ptr2;
  std::cout << num << std::endl;
  std::cout << ptr1 << std::endl;
  return 0;
}


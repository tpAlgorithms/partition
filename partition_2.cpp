#include <vector>
#include <iostream>
#include <cstdio>
#include <functional>



using std::swap;
using std::less;

void print(int *a, int n) {
  for (int i = 0; i < n; ++i) {
    printf ("%d ", a[i]);
  }
  printf("\n");
}

int partition(int *a, int n, int k) {
  swap(a[n-1], a[k]);

  int i=0;
  int j=0;

  for (; j < n - 1; ) {
    if (less<int>()(a[j], a[n-1])) {
      swap(a[i], a[j]);
      ++i;
      ++j;
    } else {
      ++j;
    }
  }

  swap(a[i], a[n-1]);

  return i;
}


int nth_element(int *a, int n, int k) {
  
  print (a, n); 

  int pos = partition(a, n, 0);

  if (pos < k) {
    return pos + 1 + nth_element(&a[pos + 1], n - (pos +1), k - (pos +1));
  } else if (pos > k ) {
    return nth_element(a, pos, k);
  } else {
    return pos;
  }
}



int main() {

  std::vector<int> data;

  while(1) {
    int value;
    if ( scanf("%d", &value) != 1 ) {
      break;
    }
    data.push_back(value);
  }


  int pos =  nth_element(&data[0], data.size(), data.size() / 2);


  printf("%d", data[pos]);

  return 0;
};

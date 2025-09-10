input/code.cpp: In function 'int main()':
input/code.cpp:121:13: warning: unused variable 'sz' [-Wunused-variable]
  121 |         int sz = ost.size();
      |             ^~
input/code.cpp: In instantiation of 'void segtree<T>::_incUpdate(ll, ll, T) [with T = std::pair<long long int, long long int>; ll = long long int]':
input/code.cpp:67:40:   required from 'void segtree<T>::update(ll, ll, T) [with T = std::pair<long long int, long long int>; ll = long long int]'
input/code.cpp:117:18:   required from here
input/code.cpp:70:46: warning: operation on 'l' may be undefined [-Wsequence-point]
   70 |             if(l & 1) { _updateLazy(l, val); lazy[l++] = op(lazy[l], val); }
      |                                              ^~~~
input/code.cpp:72:49: warning: operation on 'r' may be undefined [-Wsequence-point]
   72 |             if(!(r & 1)) { _updateLazy(r, val); lazy[r--] = op(lazy[r], val); }
      |                                                 ^~~~
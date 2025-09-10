input/code.cpp: In instantiation of 'void segtree<T>::_incUpdate(int, int, T) [with T = long long int]':
input/code.cpp:34:40:   required from 'void segtree<T>::update(int, int, T) [with T = long long int]'
input/code.cpp:80:19:   required from here
input/code.cpp:37:46: warning: operation on 'l' may be undefined [-Wsequence-point]
   37 |             if(l & 1) { _updateLazy(l, val); lazy[l++] = op(lazy[l], val); }
      |                                              ^~~~
input/code.cpp:39:49: warning: operation on 'r' may be undefined [-Wsequence-point]
   39 |             if(!(r & 1)) { _updateLazy(r, val); lazy[r--] = op(lazy[r], val); }
      |                                                 ^~~~
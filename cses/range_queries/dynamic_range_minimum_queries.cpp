input/code.cpp: In instantiation of 'void segtree<T>::increment(int, int, T) [with T = long long int]':
input/code.cpp:58:41:   required from here
input/code.cpp:31:57: warning: operation on 'l' may be undefined [-Wsequence-point]
   31 |             if(l & 1) { tree[l] += val; _updateLazy(l); lazy[l++] = val+value(lazy[l]); }
      |                                                         ^~~~
input/code.cpp:33:60: warning: operation on 'r' may be undefined [-Wsequence-point]
   33 |             if(!(r & 1)) { tree[r] += val; _updateLazy(r); lazy[r--] = val+value(lazy[r]); }
      |                                                            ^~~~
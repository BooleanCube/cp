input/code.cpp: In function 'int main()':
input/code.cpp:19:23: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   19 |         for(int i=0; i<a.size(); i++) cout << a[i] << " \n"[i==(a.size()-1)];
      |                      ~^~~~~~~~~
input/code.cpp:19:62: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   19 |         for(int i=0; i<a.size(); i++) cout << a[i] << " \n"[i==(a.size()-1)];
      |                                                             ~^~~~~~~~~~~~~~
input/code.cpp:21:23: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   21 |         for(int i=0; i<b.size(); i++) cout << b[i] << " \n"[i==(b.size()-1)];
      |                      ~^~~~~~~~~
input/code.cpp:21...
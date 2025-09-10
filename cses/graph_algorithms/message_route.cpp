input/code.cpp: In function 'int main()':
input/code.cpp:39:19: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   39 |     for(int i=0; i<ans.size(); i++) cout << ans[i] << " \n"[i==ans.size()-1];
      |                  ~^~~~~~~~~~~
input/code.cpp:39:62: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   39 |     for(int i=0; i<ans.size(); i++) cout << ans[i] << " \n"[i==ans.size()-1];
      |                                                             ~^~~~~~~~~~~~~~
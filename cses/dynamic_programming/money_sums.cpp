input/code.cpp: In function 'int main()':
input/code.cpp:25:19: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   25 |     for(int i=0; i<ans.size(); i++) cout << ans[i] << " \n"[i==ans.size()-1];
      |                  ~^~~~~~~~~~~
input/code.cpp:25:62: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   25 |     for(int i=0; i<ans.size(); i++) cout << ans[i] << " \n"[i==ans.size()-1];
      |                                                             ~^~~~~~~~~~~~~~
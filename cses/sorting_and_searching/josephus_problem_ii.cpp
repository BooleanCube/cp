input/code.cpp: In function 'int main()':
input/code.cpp:35:22: warning: comparison of integer expressions of different signedness: 'std::vector<int>::size_type' {aka 'long unsigned int'} and 'int' [-Wsign-compare]
   35 |     while(ans.size() < n) {
      |           ~~~~~~~~~~~^~~
input/code.cpp:38:23: warning: comparison of integer expressions of different signedness: 'std::vector<int>::size_type' {aka 'long unsigned int'} and 'int' [-Wsign-compare]
   38 |         if(ans.size() == n) break;
      |            ~~~~~~~~~~~^~~~
input/code.cpp: In function 'int main()':
input/code.cpp:7:19: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
    7 |     for(int i=0; i<=s.size(); i++) DP[i][0] = i;
      |                  ~^~~~~~~~~~
input/code.cpp:8:19: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
    8 |     for(int i=0; i<=t.size(); i++) DP[0][i] = i;
      |                  ~^~~~~~~~~~
input/code.cpp:9:19: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
    9 |     for(int i=1; i<=s.size(); i++) {
      |                  ~^~~~~~~~~~
input/code.cpp:10:23: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_str...
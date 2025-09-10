input/code.cpp: In function 'int main()':
input/code.cpp:13:34: warning: comparison of integer expressions of different signedness: 'std::map<int, int>::size_type' {aka 'long unsigned int'} and 'int' [-Wsign-compare]
   13 |                 while(vis.size() <= k && j <= n) vis[nums[j++]]++;
      |                       ~~~~~~~~~~~^~~~
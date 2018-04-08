#include <vector>

using namespace std;
class empinfo {
    private:
       vector<int> ids;

    public:
      empinfo() {}
      void addId( int i ) { ids.push_back(i); }
};

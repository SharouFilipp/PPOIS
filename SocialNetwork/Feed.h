#include "Post.h"
#include <string>
#include <vector>
using namespace std;

class Feed {
public:
    Feed(int userId);
    
    void refreshFeed();
    void applyFilter(string filter);
    int getUserId();
    string getFilters();
private:
    int userId;
    string filters;
};
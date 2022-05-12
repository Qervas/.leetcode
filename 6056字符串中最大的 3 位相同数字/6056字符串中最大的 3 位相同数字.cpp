#include<string>
using std::string;
class Solution {
public:
    string largestGoodInteger(string num) {
        char max = NULL;
        size_t size = num.size();
        if(size < 3){return {};}
        char value = NULL;
        for(size_t i = 2; i < size; ++i, value = 0){
            if(num[i-2] == num[i-1] && num[i] == num[i-1]){
                value = num[i];
                max = max < value ?  value : max;  
            }
        }
        if(max < '0' || max > '9'){return "";}
        string answer;
        for(int i = 0; i < 3; ++i) answer+=max;
        return answer;
        
    }
};


int main(void){

    Solution s;
    string num = "6777133339";
    s.largestGoodInteger(num);
    return 0;
}
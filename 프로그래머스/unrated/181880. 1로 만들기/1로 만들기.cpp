#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int count = 0;
    for (int num : num_list) {
        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num = (num - 1) / 2;
            }
            count++;
        }
    }
    return count;
}
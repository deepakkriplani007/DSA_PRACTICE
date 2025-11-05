class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long apples = 0, side = 1;
        while (apples < neededApples){
            apples += 12LL * side * side;
            ++side;
        }
        return (side - 1) << 3;
    }
};
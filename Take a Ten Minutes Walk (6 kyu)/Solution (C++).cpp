#include <vector>
#include <algorithm>

bool isValidWalk(std::vector<char> walk) {
    return walk.size() == 10 &&
        std::count(walk.begin(), walk.end(), 'n') == std::count(walk.begin(), walk.end(), 's') &&
        std::count(walk.begin(), walk.end(), 'e') == std::count(walk.begin(), walk.end(), 'w');
}
#include "combine_vectors.h"
#include <cstddef>

using namespace combineVectors;

std::vector<int> combineVectors::combine_vectors(const std::vector<int>& vec_1, const std::vector<int>& vec_2) {
    
    std::vector<int> res;
    const size_t sz1 = vec_1.size();
    const size_t sz2 = vec_2.size();
    unsigned int idx1 = 0, idx2 = 0;

    // While neither of the vectors have reached the end
    while (idx1 < sz1 && idx2 < sz2) {
        if (vec_1[idx1] < vec_2[idx2]) res.push_back(vec_1[idx1++]);
        else res.push_back(vec_2[idx2++]);
    }

    // While vec_1 has not reached the end
    while (idx1 < sz1) res.push_back(vec_1[idx1++]);

    // While vec_2 has not reached the end
    while (idx2 < sz2) res.push_back(vec_2[idx2++]);

    return res;
}

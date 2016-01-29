#ifndef SEARCH_DISTANCE_H_
#define SEARCH_DISTANCE_H_

#include <vector>

class SearchDistance {
 public:
    enum SearchMethod {
        SEARCH_SHORTEST, /* search the minimum value of candidates */
        SEARCH_MEDIAN,   /* search the median value of candidates */
        SEARCH_MODE,     /* search the mode (most common) value of candidates */
    };

    explicit SearchDistance(std::vector<float> distance_in_rectangle);
    float GetDistance(SearchMethod mehthod);

 private:
    std::vector<float> candidates_;
};

#endif  // SEARCH_DISTANCE_H_


















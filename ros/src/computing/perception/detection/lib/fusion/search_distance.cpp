#include <algorithm>
#include <iterator>
#include <map>
#include "include/search_distance.h"


float GetShortest(std::vector<float> candidates) {
  /* Sort candidate by its distances */
  if (!candidates.empty()) {
    std::sort(candidates.begin(), candidates.end());
  }

  if (candidates.empty()) {
    return 0.0f;
  } else {
    /*
      As candidates are already sorted by its distance,
      the first element is the shortest one
    */
    return candidates.at(0);
  }
}


float GetMedian(std::vector<float> candidates) {
  /* Sort candidate by its distances */
  if (!candidates.empty()) {
    std::sort(candidates.begin(), candidates.end());
  }

  float median;
  size_t num_candidates = candidates.size();

  if (num_candidates == 0) {
    median = 0.0f;
  } else if (num_candidates == 1) {
    median = candidates.at(0);
  } else if (num_candidates % 2 == 0) {
    median = (candidates.at(num_candidates/2 - 1) + candidates.at(num_candidates/2)) / 2;
  } else {
    median = candidates.at(num_candidates/2);
  }

  return median;
}


float GetMode(std::vector<float> candidates) {
  /*
    Express histogram by std::map.
    key (first) of map = bin (category) of histgram (bin means integer distance of candidates here)
    value (second) of map = candidate's real value which belong to that category
  */
  std::map<int, std::vector<float>> histogram;

  /* Categorize each candidates into histogram */
  for (const auto& sample : candidates) {
    int bin = static_cast<float>(sample);
    histogram[bin].push_back(sample);
  }

  /* Search the most common bin */
  size_t max_num_candidates = 0;
  int max_bin = 0;
  for (const auto& bin : histogram) {
    if (max_num_candidates < bin.second.size()) {
      max_bin = bin.first;
      max_num_candidates = bin.second.size();
    }
  }

  /* Calculate median value of candidates which belong to most common bin */
  return GetMedian(histogram[max_bin]);
}



SearchDistance::SearchDistance(std::vector<float> distance_in_rectangle) {
  /* Copy the input vector into private vector of this class */
  std::copy(distance_in_rectangle.begin(),
            distance_in_rectangle.end(),
            back_inserter(candidates_));
}


float SearchDistance::GetDistance(SearchMethod method) {
  float distance = 0.0f;

  switch (method) {
    case SEARCH_SHORTEST:
      distance = GetShortest(candidates_);
      break;
    case SEARCH_MEDIAN:
      distance = GetMedian(candidates_);
      break;
    case SEARCH_MODE:
      distance = GetMode(candidates_);
      break;
  }

  return distance;
}



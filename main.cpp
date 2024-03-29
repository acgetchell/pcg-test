#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
//#include <gsl/gsl>
#include "pcg_random.hpp"

int main()
{
  // Seed with a real random value, if available
  pcg_extras::seed_seq_from<std::random_device> seed_source;

  // Make a random number engine
  pcg64 rng(seed_source);

  // Choose a random mean between 1 and 6
  std::uniform_int_distribution<int> uniform_dist(1, 6);
  int mean = uniform_dist(rng);
  std::cout << "Randomly-chosen mean: " << mean << '\n';

  // Generate a normal distribution around that mean
  std::normal_distribution<> normal_dist(mean, 2);

  // Produce histogram
  std::map<int, int> hist;
  for (int n = 0; n < 10000; ++n) {
    ++hist[std::round(normal_dist(rng))];
  }
  std::cout << "Normal distribution around " << mean << ":\n";
  for (auto p : hist) {
    std::cout << std::fixed << std::setprecision(1) << std::setw(2)
              << p.first << ' ' << std::string(p.second/30, '*') << '\n';
  }
}
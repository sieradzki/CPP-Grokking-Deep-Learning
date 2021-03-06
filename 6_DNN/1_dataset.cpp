#include <iostream>
#include <vector>
#include <math.h>
#include "../include/mathFuncs.h"

int main()
{
  std::vector<float> weights = {0.5, 0.48, -0.7};
  float alpha = 0.1;

  std::vector<std::vector<float>> streetlights = {
    {1, 0, 1},
    {0, 1, 1},
    {0, 0, 1},
    {1, 1, 1},
    {0, 1, 1},
    {1, 0, 1} };

  std::vector<float> walk_vs_stop = {0, 1, 0, 1, 1, 0};

  std::vector<float> input = streetlights[0];
  float goal_prediction = walk_vs_stop[0];

  for(int i=0; i<40; i++)
  {
    float error_for_all_lights = 0;
    
    for(int j=0; j<int(walk_vs_stop.size()); j++)
    {
      std::vector<float> input = streetlights[j];
      float goal_prediction = walk_vs_stop[j];
      
      float prediction = mf::dot_product(input, weights);

      float delta = prediction - goal_prediction;
      float error = pow(delta, 2);
      error_for_all_lights += error;

      weights = mf::vect_subt(weights, mf::scalar_mult(alpha, (mf::scalar_mult(delta, input))));

      std::cout << "Prediction: " << prediction << std::endl;
    }

    std::cout << "Error: " << error_for_all_lights << "\n\n";
  }

  return 0;
}


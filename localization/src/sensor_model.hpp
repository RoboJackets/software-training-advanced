// Copyright 2021 RoboJackets
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef SENSOR_MODEL_HPP_
#define SENSOR_MODEL_HPP_

#include <stsl_interfaces/msg/tag_array.hpp>
#include <rclcpp/rclcpp.hpp>
#include <map>
#include <random>
#include <vector>
#include "particle.hpp"

namespace localization
{


class SensorModel
{
public:
  virtual double ComputeLogProb(Particle & particle) {return 0.0;}
  virtual double ComputeLogNormalizer() {return 0.0;}
  virtual bool IsMeasUpdateValid(rclcpp::Time cur_time);
  ~SensorModel() = default;

protected:
  std::vector<double> meas_cov_;
  double time_delay_;
  SensorModel() = default;

private:
};
}  // namespace localization


#endif  // SENSOR_MODEL_HPP_
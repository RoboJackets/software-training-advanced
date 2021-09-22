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

#ifndef ODOMETRY_SENSOR_MODEL_HPP_
#define ODOMETRY_SENSOR_MODEL_HPP_

#include <nav_msgs/msg/odometry.hpp>
#include "sensor_model.hpp"

namespace localization
{
class OdometrySensorModel : public SensorModel
{
public:
  explicit OdometrySensorModel(rclcpp::Node * node);

  void UpdateMeasurement(const nav_msgs::msg::Odometry::SharedPtr odom);
  double ComputeLogProb(Particle & particle) override;
  double ComputeLogNormalizer() override;
  bool IsMeasUpdateValid(rclcpp::Time cur_time) override;

private:
  nav_msgs::msg::Odometry::SharedPtr last_msg_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
};
}  // namespace localization


#endif  // ODOMETRY_SENSOR_MODEL_HPP_
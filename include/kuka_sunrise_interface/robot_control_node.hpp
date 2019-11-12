/*
 * robot_control_node.hpp
 *
 *  Created on: Nov 11, 2019
 *      Author: rosdeveloper
 */

#ifndef INCLUDE_KUKA_SUNRISE_INTERFACE_ROBOT_CONTROL_NODE_HPP_
#define INCLUDE_KUKA_SUNRISE_INTERFACE_ROBOT_CONTROL_NODE_HPP_

#include "fri_client/friClientApplication.h"
#include "fri_client/friUdpConnection.h"
#include "kuka_sunrise_interface/robot_control_client.hpp"

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"

#include "pthread.h"
#include "limits.h"
#include "sched.h"
#include "sys/mman.h"


namespace kuka_sunrise_interface{

class RobotControlNode : public rclcpp_lifecycle::LifecycleNode
{
public:
  RobotControlNode();
  void runClientApplication();

  virtual rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_configure(const rclcpp_lifecycle::State&);

  virtual rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_cleanup(const rclcpp_lifecycle::State&);

  virtual rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_shutdown(const rclcpp_lifecycle::State&);

  virtual rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_activate(const rclcpp_lifecycle::State&);

  virtual rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_deactivate(const rclcpp_lifecycle::State&);

  virtual rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_error(const rclcpp_lifecycle::State&);

private:
  KUKA::FRI::UdpConnection udp_connection_;
  RobotControlClient client_;
  KUKA::FRI::ClientApplication client_application_;

  pthread_t client_application_thread_;


};


}
#endif /* INCLUDE_KUKA_SUNRISE_INTERFACE_ROBOT_CONTROL_NODE_HPP_ */

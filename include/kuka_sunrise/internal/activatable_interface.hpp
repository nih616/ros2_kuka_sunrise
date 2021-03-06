// Copyright 2020 Zoltán Rési
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef KUKA_SUNRISE__INTERNAL__ACTIVATABLE_INTERFACE_HPP_
#define KUKA_SUNRISE__INTERNAL__ACTIVATABLE_INTERFACE_HPP_

namespace kuka_sunrise
{

class ActivatableInterface
{
public:
  virtual bool activate()
  {
    is_active_ = true;
    return true;
  }
  virtual bool deactivate()
  {
    is_active_ = false;
    return true;
  }
  bool isActive()
  {
    return is_active_;
  }
  virtual ~ActivatableInterface()
  {
  }

protected:
  bool is_active_;
};

}  // namespace kuka_sunrise

#endif  // KUKA_SUNRISE__INTERNAL__ACTIVATABLE_INTERFACE_HPP_

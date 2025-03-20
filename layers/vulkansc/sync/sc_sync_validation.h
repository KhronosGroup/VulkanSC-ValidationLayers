/* Copyright (c) 2023-2025 The Khronos Group Inc.
 * Copyright (c) 2023-2025 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Daniel Rakos <daniel.rakos@rastergrid.com>
 */

#pragma once

#include "sync/sync_validation.h"
#include "vulkansc/state_tracker/sc_state_tracker.h"

namespace syncval::sc {

class Instance : public vvl::sc::Instance<syncval::Instance> {
  protected:
    using BaseClass = vvl::sc::Instance<syncval::Instance>;

  public:
    using StateTracker = vvl::sc::Instance<syncval::Instance>;

    Instance(vvl::dispatch::Instance *dispatch) : BaseClass(dispatch) {}
};

class Device : public vvl::sc::Device<SyncValidator> {
  protected:
    using BaseClass = vvl::sc::Device<SyncValidator>;

  public:
    using StateTracker = vvl::sc::Device<SyncValidator>;

    Device(vvl::dispatch::Device *dev, syncval::sc::Instance *instance_vo) : BaseClass(dev, instance_vo) {}
};

}  // namespace syncval::sc

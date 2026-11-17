// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See dispatch_object_generator.py for modifications

/***************************************************************************
 *
 * Copyright (c) 2015-2026 The Khronos Group Inc.
 * Copyright (c) 2015-2026 Valve Corporation
 * Copyright (c) 2015-2026 LunarG, Inc.
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
 ****************************************************************************/

// NOLINTBEGIN

#include "chassis/dispatch_object.h"
#include "thread_tracker/thread_safety_validation.h"
#include "stateless/stateless_validation.h"
#include "object_tracker/object_lifetime_validation.h"
#include "vulkansc/state_tracker/sc_state_tracker.h"
#include "vulkansc/core_checks/sc_core_validation.h"
#include "vulkansc/sync/sc_sync_validation.h"

namespace vvl {

void DispatchInstance::InitValidationObjects() {
    // Note that this DEFINES THE ORDER IN WHICH THE LAYER VALIDATION OBJECTS ARE CALLED
    // Anyone using state tracking (LayerObjectTypeStateTracker) must be called after and enable it

    if (!settings.disabled[thread_safety]) {
        object_dispatch.emplace_back(new threadsafety::Instance(this));
    }
    if (!settings.disabled[stateless_checks]) {
        object_dispatch.emplace_back(new stateless::Instance(this));
    }
    if (!settings.disabled[object_tracking]) {
        object_dispatch.emplace_back(new object_lifetimes::Instance(this));
    }
    if (!settings.disabled[core_checks] || settings.enabled[sync_validation]) {
        object_dispatch.emplace_back(new vvl::sc::InstanceState(this));
    }
    if (!settings.disabled[core_checks]) {
        object_dispatch.emplace_back(new core::sc::Instance(this));
    }
    if (settings.enabled[sync_validation]) {
        object_dispatch.emplace_back(new syncval::sc::Instance(this));
    }
}

void DispatchDevice::InitValidationObjects() {
    // Note that this DEFINES THE ORDER IN WHICH THE LAYER VALIDATION OBJECTS ARE CALLED
    // Anyone using state tracking (LayerObjectTypeStateTracker) must be called after and enable it

    if (!settings.disabled[thread_safety]) {
        object_dispatch.emplace_back(new threadsafety::Device(
            this, static_cast<threadsafety::Instance*>(dispatch_instance->GetValidationObject(LayerObjectTypeThreading))));
    }
    if (!settings.disabled[stateless_checks]) {
        object_dispatch.emplace_back(new stateless::Device(
            this, static_cast<stateless::Instance*>(dispatch_instance->GetValidationObject(LayerObjectTypeParameterValidation))));
    }
    if (!settings.disabled[object_tracking]) {
        object_dispatch.emplace_back(new object_lifetimes::Device(
            this, static_cast<object_lifetimes::Instance*>(dispatch_instance->GetValidationObject(LayerObjectTypeObjectTracker))));
    }
    if (!settings.disabled[core_checks] || settings.enabled[sync_validation]) {
        object_dispatch.emplace_back(new vvl::sc::DeviceState(
            this, static_cast<vvl::sc::InstanceState*>(dispatch_instance->GetValidationObject(LayerObjectTypeStateTracker))));
    }
    if (!settings.disabled[core_checks]) {
        object_dispatch.emplace_back(new core::sc::Device(
            this, static_cast<core::sc::Instance*>(dispatch_instance->GetValidationObject(LayerObjectTypeCoreValidation))));
    }
    if (settings.enabled[sync_validation]) {
        object_dispatch.emplace_back(new syncval::sc::Device(
            this, static_cast<syncval::sc::Instance*>(dispatch_instance->GetValidationObject(LayerObjectTypeSyncValidation))));
    }
}
}  // namespace vvl

// NOLINTEND

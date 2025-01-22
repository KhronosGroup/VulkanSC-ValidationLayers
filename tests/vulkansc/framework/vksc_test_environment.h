/*
 * Copyright (c) 2024-2025 The Khronos Group Inc.
 * Copyright (c) 2024-2025 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#pragma once

#include "../../framework/test_common.h"
#include "../../framework/test_framework.h"

class VkSCTestEnvironment : public ::testing::Environment {
  public:
    virtual void SetUp() override;
    virtual void TearDown() override;

    static void InitArgs(int *argc, char *argv[]);

    static bool IsSpvDebugInfoEnabled() { return !no_spv_debug_info; }

  private:
    inline static bool no_spv_debug_info = false;
};

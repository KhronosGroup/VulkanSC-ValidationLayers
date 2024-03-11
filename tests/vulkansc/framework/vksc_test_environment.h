/*
 * Copyright (c) 2024-2024 The Khronos Group Inc.
 * Copyright (c) 2024-2024 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#include "../../framework/test_common.h"
#include "../../framework/test_framework.h"

class VkSCTestEnvironment : public ::testing::Environment {
  public:
    virtual void SetUp() override;
    virtual void TearDown() override;
};

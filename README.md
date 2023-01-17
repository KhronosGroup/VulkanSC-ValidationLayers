# Vulkan and Vulkan SC Ecosystem Components

This project provides the Khronos Vulkan validation layers for Windows, Linux, Android, and MacOS,
and the Khronos Vulkan SC Development validation layers for Windows, Linux, and QNX.

## CI Build Status
| Build Status |
|:------------|
| [![Build Status](https://github.com/KhronosGroup/VulkanSC-ValidationLayers/actions/workflows/build_windows.yml/badge.svg?branch=sc_main)](https://github.com/KhronosGroup/VulkanSC-ValidationLayers/actions) |
| [![Build Status](https://github.com/KhronosGroup/VulkanSC-ValidationLayers/actions/workflows/build_linux.yml/badge.svg?branch=sc_main)](https://github.com/KhronosGroup/VulkanSC-ValidationLayers/actions) |
| [![Build Status](https://github.com/KhronosGroup/VulkanSC-ValidationLayers/actions/workflows/build_linux_gn.yml/badge.svg?branch=sc_main)](https://github.com/KhronosGroup/VulkanSC-ValidationLayers/actions) |
| [![Build Status](https://github.com/KhronosGroup/VulkanSC-ValidationLayers/actions/workflows/build_android.yml/badge.svg?branch=sc_main)](https://github.com/KhronosGroup/VulkanSC-ValidationLayers/actions) |


## Introduction

### Vulkan
Vulkan is an Explicit API, enabling direct control over how GPUs actually work. By design, minimal error checking is done inside
a Vulkan driver. Applications have full control and responsibility for correct operation. Any errors in
how Vulkan is used can result in a crash. This project provides Vulkan validation layers that can be enabled
to assist development by enabling developers to verify their applications correct use of the Vulkan API.

The [Vulkan-ValidationLayer](https://github.com/KhronosGroup/Vulkan-ValidationLayers) repository contains the
official Vulkan validation layers that are used for Linux, Windows, MacOS, and iOS.

### Vulkan SC

Vulkan SC is an API derived from Vulkan with various changes applied to fulfill the special
requirements of safety critical applications. The Vulkan SC API has a large overlap with Vulkan.
As such, we endeavor to leverage as many of the Vulkan Ecosystem components as possible.

### This Repository

The following components are available in this repository:
- [*Validation Layers*](layers/)
- [*Tests*](tests/)

This repository contains the Vulkan SC Validation Layers which is intended for **development** environments,
and is not expected to be used in **production** (safety) environments.

**NOTE**: This repository is a downstream fork of
[KhronosGroup/Vulkan-ValidationLayers](https://github.com/KhronosGroup/Vulkan-ValidationLayers)
which is periodically rebased.

This repository continues to have functioning Vulkan validation layers with equivalent functionality
to the upstream branch point.

The choice of Vulkan or Vulkan SC support is determined at build time.

The `sc_main` branch is currently based on the `sdk-1.2.198` Vulkan-ValidationLayers tag and contains Vulkan SC modifications to support the Vulkan SC 1.0 API.

## Contact Information

For Vulkan SC specific issues, or issues specific to this fork:

* [Daniel Koch](mailto:dkoch@nvidia.com) for Vulkan SC-specific concerns.

General validation issues these should be reported to the upstream repository:

* [KhronosGroup/Vulkan-ValidationLayers](https://github.com/KhronosGroup/Vulkan-ValidationLayers)

## Information for Developing or Contributing:

Please see the [CONTRIBUTING.md](CONTRIBUTING.md) file in this repository for more details.
Please see the [GOVERNANCE.md](GOVERNANCE.md) file in this repository for repository management details.

## How to Build and Run

[BUILD.md](BUILD.md)
Includes directions for building all components as well as running validation tests.

Information on how to enable the various Validation layers is in [LAYER_CONFIGURATION.md](LAYER_CONFIGURATION.md).

## Version Tagging Scheme

Updates to the `VulkanSC-ValidationLayers` repository which correspond to a new Vulkan specification release are tagged using the following format: `v<`_`version`_`>` (e.g., `v1.1.96`).

**Note**: Marked version releases have undergone thorough testing but do not imply the same quality level as SDK tags. SDK tags follow the `sdk-<`_`version`_`>.<`_`patch`_`>` format (e.g., `sdk-1.1.92.0`).

This scheme was adopted following the 1.1.96 Vulkan specification release.

For Vulkan SC, updates to a new API version will be tagged using the following format `vksc<`_`version`_`>.<`_`patch`_`>` (e.g., `vksc1.0.11`).

## License
This work is released as open source under a Apache-style license from Khronos including a Khronos copyright.

See [LICENSE.txt](LICENSE.txt) for a full list of licenses used in this repository.

## Acknowledgements
While this project has been developed primarily by LunarG, Inc., there are many other
companies and individuals making this possible: Valve Corporation, funding
project development; Google providing significant contributions to the validation layers;
Khronos providing oversight and hosting of the project.

Vulkan SC modifications have been contributed by NVIDIA CORPORATION.

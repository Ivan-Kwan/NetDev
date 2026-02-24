# NetDev
A project to learn about networking development of embedded software

## Project Overview
This project is a dedicated sandbox for FreeRTOS kernel development and embedded systems programming. By leveraging QEMU emulation, this environment allows for the development, testing, and verification of real-time multi-tasking applications without the immediate need for physical hardware.
The primary goal is to master RTOS primitives—such as task scheduling, inter-task communication, and resource management—within a professional, automated build environment.

## Hardware & Baseline Configuration
To ensure industry-standard compatibility, this project utilizes a stable baseline from the FreeRTOS official distribution:
### Target Machine: ARM MPS2 (Motherboard Prototyping System 2).
### Processor Core: Cortex-M3 (Industry-standard RISC architecture).
### Base Demo Folder: CORTEX_MPS2_QEMU_IAR_GCC.
#### This provides the essential Linker Scripts (.ld), Startup Files, and the Portable Layer for the GCC compiler, ensuring low-level hardware abstraction is handled correctly.

## Toolchain & Development Environment
The project is built using a "Headless" workflow, mirroring modern CI/CD practices used in large-scale embedded firmware engineering:
### Host OS: Windows (via MSYS2 UCRT64).
### Compiler: Arm GNU Toolchain 15.2.Rel1 (arm-none-eabi-gcc).
### Build System: GNU Make.
### Emulator: QEMU 10.1.3 (utilizing mon:stdio for stable serial output on Windows).

## Future Roadmap
The project is designed to evolve into a complex IoT/Embedded system. Planned milestones include:
### Advanced RTOS Primitives: Implementing Queue-based telemetry and Semaphore-guarded shared resources.
### Memory Optimization: Analyzing the .text, .data, and .bss segments to minimize Flash and RAM footprints (currently ~144KB).
### Network Integration: Porting FreeRTOS+TCP or LwIP to simulate UDP/TCP communication, building on prior experience with ESP32 and Google Cloud integration.
### Hardware Migration: Porting the verified application logic to physical STM32 or ESP32 hardware once the software-in-the-loop (SIL) testing is complete.

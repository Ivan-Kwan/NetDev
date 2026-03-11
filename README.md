# NetDev
A project to learn about networking development of embedded software

## Project Overview
This project is a dedicated sandbox for FreeRTOS kernel development and embedded systems programming. By leveraging QEMU emulation, this environment allows for the development, testing, and verification of real-time multi-tasking applications and TCP/IP networking without the immediate need for physical hardware.
The primary goal is to master RTOS primitives—such as task scheduling, inter-task communication, and resource management—and integrate a networking stack (LwIP) within a professional, automated build environment.

## Hardware & Baseline Configuration
To ensure industry-standard compatibility and robust network emulation, this project targets the Stellaris LM3S series:
* **Target Machine**: Stellaris LM3S6965 Evaluation Board (Simulated via QEMU).
* **Processor Core**: Cortex-M3 (Industry-standard RISC architecture).
* **Hardware Abstraction**: `libopencm3` framework.
* **Custom Board Definition**: A custom PlatformIO board configuration (`boards/qemu_lm3s6965.json`) is used to map the exact RAM (64KB) and Flash (256KB) specifications for the emulator.

## Toolchain & Development Environment
The project utilizes a modern IDE-driven workflow using PlatformIO, ensuring seamless dependency management and build automation:
* **IDE**: Visual Studio Code (VS Code).
* **Build System & Package Manager**: PlatformIO (PIO).
* **RTOS**: FreeRTOS Kernel (integrated via PIO `lib_deps`).
* **Network Stack**: Lightweight IP (LwIP).
* **Emulator**: QEMU (launched automatically via custom Python post-build scripts `run_qemu.py`).

## Software Architecture
The codebase strictly follows a decoupled, Layered Architecture organized within the PlatformIO `lib` directory to ensure portability:
1. **Application Layer (`main.c`)**: Implements business logic, FreeRTOS task orchestration, and high-level application flow.
2. **Interface Layer (`lib/intf/`)**: Wraps LwIP and MQTT APIs, providing a clean, hardware-agnostic interface for the application.
3. **Driver Layer (`lib/driver/`)**: The LwIP porting layer, bridging the network stack with the simulated hardware via FreeRTOS primitives (Tasks and Semaphores).
4. **Hardware Abstraction Layer (`lib/hal/`)**: Utilizes `libopencm3` for direct register-level access to the virtual Ethernet MAC and PHY.

## Future Roadmap
The project is designed to evolve into a complex IoT/Embedded system. Planned milestones include:
* **Advanced RTOS Primitives**: Implementing Queue-based telemetry and Semaphore-guarded shared resources.
* **Network Integration**: Completing the LwIP port to establish stable MQTT communication between the QEMU guest and the host machine broker.
* **Hardware Migration**: Porting the verified software-in-the-loop (SIL) application logic to physical STM32 hardware, leveraging the decoupled HAL design.

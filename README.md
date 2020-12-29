# stm32-NHD-1.69-160128ASC3
STM32 Fast and Basic driver for NHD-1.69-160128ASC3

Install:
- Docker Desktop
- WSL 2.0 with Ubuntu 20.04
- Install STLINK from https://www.st.com/en/development-tools/stsw-link004.html, adjust ./debug_win.ps1

Use visual studio Code extentions:
- Remote - Containers
- Remote - WSL
- C/C++
- Docker

Launch a Visual Code from the folder:
- When asked, from the Remote - Conttainer extention, launch in Dev Container
- The container should build with required configuration
- Visual Code should launch in Dev Container: Docker from Docker mode
- Build using CTRL+B or run build task prepdebug
- Debug:
  - Launch ./debug_win.ps1 in host (this relates to the fact that usb devices are not accessible on the container)
  - Start Debug Session GDB (REMOTE) in Visual Code
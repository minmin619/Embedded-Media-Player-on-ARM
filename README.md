# Embedded Media Player on ARM

A lightweight embedded multimedia player using **GStreamer + FFmpeg**, optimized for ARM Linux.

## **Features**
**Embedded Linux System** with Buildroot  
**ARM Cross-compilation** for lightweight performance  
**GStreamer + FFmpeg** for H.264 video playback  
**Zero-copy Optimization** (DMA, V4L2, OpenGL)  


---

## **Installation**
### **1. Install ARM Cross-Compilation Toolchain**
```bash
sudo apt update
sudo apt install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf
```

### **2. Build Root Filesystem with Buildroot**
```bash
git clone https://git.buildroot.net/buildroot
cd buildroot
make qemu_arm_vexpress_defconfig
make
```

### **3. Install GStreamer and FFmpeg**
```bash
sudo apt install libgstreamer1.0-dev gstreamer1.0-plugins-base \
                 gstreamer1.0-plugins-good gstreamer1.0-plugins-bad \
                 gstreamer1.0-plugins-ugly gstreamer1.0-libav
```

---

## **Build and Run Media Player**
### **1. Compile Media Player**
```bash
gcc simple_player.c -o simple_player `pkg-config --cflags --libs gstreamer-1.0`
```

### **2. Run Player**
```bash
./simple_player sample.mp4
```

---



## **Optimization Techniques**
### **1. Reduce Binary Size**
```bash
strip simple_player
```
## Challenges Encountered

1. CPU & Memory Limitations

Buildroot requires high CPU and memory resources, which may cause performance issues on low-end computers.
To mitigate this, using make -j1 instead of parallel compilation (make -j4 or higher) can help reduce resource usage.
Running Buildroot on a virtual machine (VirtualBox/VMware) may further slow down the process if insufficient RAM or CPU is allocated.

2. Storage Limitations

Buildroot requires at least 10GB of free space.
If /var or /tmp is full, the build process might fail.
Cleaning up unnecessary packages (sudo apt clean && sudo apt autoremove) can free up space.

3. Alternative Solutions

Pre-built Images: Instead of compiling Buildroot from scratch, downloading a pre-built image can save time.
Dedicated Embedded Board: Running the project directly on an ARM board like Raspberry Pi or Jetson Nano can bypass resource limitations on a local machine.

## **Future Improvements**
Add Web Interface** using WebKitGTK + WebSocket  
Add RTSP streaming support  
Implement adaptive bitrate playback  
Improve low-latency rendering  



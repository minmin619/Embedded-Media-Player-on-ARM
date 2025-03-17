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


## **Future Improvements**
Add Web Interface** using WebKitGTK + WebSocket  
Add RTSP streaming support  
Implement adaptive bitrate playback  
Improve low-latency rendering  



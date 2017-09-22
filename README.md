FFmpeg 3.3.4 “Hilbert” with Cedrus264 for R40 and A64
-----------------------------------------------------

FFmpeg 3.3.4 Source code and Deb packages (HOWTO).

| architecture           | build and tested on following devices | deb package                  |
|------------------------|---------------------------------------|------------------------------|
| armhf                  | BananaPi R40                          | ffmpeg-3.3.4_1.0-1_armhf.deb |
| arm64 / aarch64        | BananaPi M64 / NanoPi A64             | ffmpeg-3.3.4_1.0-1_arm64.deb |
| arm64 / aarch64        | Pine64 / OPi Win A64                  | ffmpeg-3.3.4_1.0-1_arm64.deb |


Linux source for the latest ffmpeg with cedrus hw encoder.
You can build the code or install the deb packages for your current architecture.


System Requirements (Debian-based distribution)
-----------------------------------------------

* Ubuntu Xenial 16.04
* development libraries
* gcc compiler

**You can build this to Debian or Fedora or any distro, change the dependencies names accordingly**

 
Instructions
------------

**1. Download this instructions**

	git clone https://github.com/avafinger/ffmpeg-3.3.4_cedrus264.git
	cd ffmpeg-3.3.4_cedrus264.git

or

	Use [Clone or download] green button e choose [Download ZIP]
	uncompress
	cd ffmpeg-3.3.4_cedrus264-master


**2. Set up your build environment and dependencies**

Install dependencies:

	sudo apt-get update && apt-get install build-essential
	sudo apt-get install libmp3lame-dev libx264-dev libpulse-dev libpulse-dev libv4l-dev libvdpau-dev


**3. Build from Sources (Ubuntu way)**

	cd src
	./configure --prefix=/usr --enable-nonfree --enable-gpl --enable-version3 --enable-vdpau --enable-libx264 --enable-libmp3lame --enable-libpulse --enable-libv4l2 --disable-shared --enable-static
	make

Go make some coffee, have a lunch, this is going to take a long time to finish. 
This will build ffmpeg statically so you can run it without clashing with your ffmpeg currently installed by apt-get or aptitude. 


**4. Install deb packages if you don't want to compile it**

Device with 32-bit arch:

	sudo dpkg -i ffmpeg-3.3.4_1.0-1_armhf.deb
 

Device with 64-bit arch:        	

	sudo dpkg -i ffmpeg-3.3.4_1.0-1_arm64.deb



**5. Testing and Running your new ffmpeg with camera as input**

Assuming your camera sensor is capable of grabbing 640x480 at 30 FPS, try this:

if you compiled by source code and are in **src** dir:

	sudo ./ffmpeg -f v4l2 -channel 0 -video_size 640x480 -i /dev/video0 -pix_fmt nv12 -t 15 -r 30 -c:v cedrus264 test4_640x480.mp4

if you installed deb package:

	sudo ffmpeg-3.3.4 -f v4l2 -channel 0 -video_size 640x480 -i /dev/video0 -pix_fmt nv12 -t 15 -r 30 -c:v cedrus264 test4_640x480.mp4

Depending on how you set up your distro **sudo** may not be needed. (give normal user the rights to run cedrus).

**6. Considerations and Limitations**

Cedrus is a POC and development seems to be stalled, quality and/or bitrate depends vastly on the parameters and camera driver you use, resolution is a factor too, but if you improve it, please push your changes here.. ;-)



# PW_AudioLED

PW_AudioLED is a JackAudio client that sends audio data as framebuffer to the BeagleBone.GTk timers are used for displaying audio levels and calculating peaks,the calculated peaks are converted to db levels then sent via udp network.
the framebuffer consists of 65 bytes of data sent every 15ms,i can say that the refresh rate is excellent and 15ms is fast enough.
BBB_P10 is used to create lines and boxes: https://github.com/joek85/BBB_P10
you can see a video about it on youtube: https://www.youtube.com/watch?v=sMVi36LVPxk

<br>
<img height="480" width="900" src="https://github.com/joek85/BBB_LEDAUDIO/blob/master/Images/Img1.jpg?raw=true" />
<br>

<br>
<img height="480" width="900" src="https://github.com/joek85/BBB_LEDAUDIO/blob/master/Images/Img2.jpg?raw=true" />
<br>

<br>
<img height="480" width="900" src="https://github.com/joek85/BBB_LEDAUDIO/blob/master/Images/Img3.jpg?raw=true" />
<br>

<br>
<img height="480" width="900" src="https://github.com/joek85/BBB_LEDAUDIO/blob/master/Images/Img4.jpg?raw=true" />
<br>

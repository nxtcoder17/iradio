### A Gstreamer Based Internet Radio Player

**Install Gstreamer and most of its plugins, so you could play different different files with it**

#### Steps to install it 
+ Clone to this repo, anywhere on your system
+ Then, open your `.bashrc` (or other corresponding to your shell), and add this function

```
dir="path-to-the-cloned-repo"
iradio() {
    command $dir/iradio $(cat ~/.STATIONS | grep -i $1)
}
```
+ create a file named STATIONS in your HOME
+ Add urls to your favourite stations into it and with a space separation add unique-key with which you want to search that stream
```
http://strm112.1.fm/top40_mobile_mp3?aw_0_req.gdpr=true  1fm
http://50.7.68.251:7064/stream  hsl
http://78.31.65.20:8880/joyhits.mp3 heart-hits
```

+ Then, refersh your current shell or open a new terminal instance, and issue command ```iradio 1fm```


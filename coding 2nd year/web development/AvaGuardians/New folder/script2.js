// JavaScript for image slider
const images = document.querySelectorAll('.slider img');
let currentIndex = 0;

function showImage(index) {
    images.forEach((image, i) => {
        if (i === index) {
            image.style.display = 'block';
        } else {
            image.style.display = 'none';
        }
    });
}

function nextImage() {
    currentIndex = (currentIndex + 1) % images.length;
    showImage(currentIndex);
}
var map = L.map('map').setView([27.338, 88.606], 13);
L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
    maxZoom: 19,
    attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
}).addTo(map);

// Pause video on page load
 // Get references to your video elements
 const video1 = document.getElementById("sample-video-1");
 const video2 = document.getElementById("sample-video-2");
 const video3 = document.getElementById("sample-video-3");
 const video4 = document.getElementById("sample-video-4");

 // Add mouseenter event listeners to play the videos on hover
 video1.addEventListener("mouseenter", playVideo);
 video2.addEventListener("mouseenter", playVideo);
 video3.addEventListener("mouseenter", playVideo);
 video4.addEventListener("mouseenter", playVideo);

 // Function to play a video
 function playVideo(event) {
     const video = event.target;
     video.play();
 }

 // Add click event listeners to toggle full-screen mode
 video1.addEventListener("click", toggleFullScreen);
 video2.addEventListener("click", toggleFullScreen);
 video3.addEventListener("click", toggleFullScreen);
 video4.addEventListener("click", toggleFullScreen);

 // Function to toggle full-screen mode for a video
 function toggleFullScreen(event) {
     const video = event.target;
     if (video.requestFullscreen) {
         video.requestFullscreen();
     } else if (video.mozRequestFullScreen) { /* Firefox */
         video.mozRequestFullScreen();
     } else if (video.webkitRequestFullscreen) { /* Chrome, Safari, and Opera */
         video.webkitRequestFullscreen();
     } else if (video.msRequestFullscreen) { /* IE/Edge */
         video.msRequestFullscreen();
     }
    }

    const video = document.getElementById('interactive-video');
const playPauseButton = document.getElementById('play-pause');
const seekBar = document.getElementById('seek-bar');
const muteButton = document.getElementById('mute');
const volumeBar = document.getElementById('volume-bar');
const fullScreenButton = document.getElementById('full-screen');
const controls = document.querySelector('.controls');

// Toggle controls visibility on hover
video.addEventListener('mouseenter', () => {
    controls.style.visibility = 'visible';
});

video.addEventListener('mouseleave', () => {
    controls.style.visibility = 'hidden';
});

// Play/Pause button click
playPauseButton.addEventListener('click', () => {
    if (video.paused || video.ended) {
        video.play();
        playPauseButton.textContent = 'Pause';
    } else {
        video.pause();
        playPauseButton.textContent = 'Play';
    }
});

// Seek bar functionality
seekBar.addEventListener('input', () => {
    const seekTime = video.duration * (seekBar.value / 100);
    video.currentTime = seekTime;
});

video.addEventListener('timeupdate', () => {
    const currentTime = (video.currentTime / video.duration) * 100;
    seekBar.value = currentTime;
});

// Mute button click
muteButton.addEventListener('click', () => {
    if (video.muted) {
        video.muted = false;
        muteButton.textContent = 'Mute';
    } else {
        video.muted = true;
        muteButton.textContent = 'Unmute';
    }
});

// Volume bar functionality
volumeBar.addEventListener('input', () => {
    video.volume = volumeBar.value;
});

// Full screen button click
fullScreenButton.addEventListener('click', () => {
    if (video.requestFullscreen) {
        video.requestFullscreen();
    } else if (video.mozRequestFullScreen) { /* Firefox */
        video.mozRequestFullScreen();
    } else if (video.webkitRequestFullscreen) { /* Chrome, Safari, and Opera */
        video.webkitRequestFullscreen();
    } else if (video.msRequestFullscreen) { /* IE/Edge */
        video.msRequestFullscreen();
    }
});

// Automatically advance the slider every 5 seconds
setInterval(nextImage, 5000);

// Show the first image initially
showImage(currentIndex);
var greenIcon = L.icon({
  iconUrl: 'leaf-green.png',
  shadowUrl: 'leaf-shadow.png',

  iconSize:     [38, 95], // size of the icon
  shadowSize:   [50, 64], // size of the shadow
  iconAnchor:   [22, 94], // point of the icon which will correspond to marker's location
  shadowAnchor: [4, 62],  // the same for the shadow
  popupAnchor:  [-3, -76] // point from which the popup should open relative to the iconAnchor
});
var LeafIcon = L.Icon.extend({
  options: {
      shadowUrl: 'leaf-shadow.png',
      iconSize:     [38, 95],
      shadowSize:   [50, 64],
      iconAnchor:   [22, 94],
      shadowAnchor: [4, 62],
      popupAnchor:  [-3, -76]
  }
});
var greenIcon = new LeafIcon({iconUrl: 'leaf-green.png'}),
    redIcon = new LeafIcon({iconUrl: 'leaf-red.png'}),
    orangeIcon = new LeafIcon({iconUrl: 'leaf-orange.png'});
    L.icon = function (options) {
      return new L.Icon(options);
  };
  L.marker([27.105, 88.202], {icon: greenIcon}).addTo(map).bindPopup("I am a green leaf.");
L.marker([27.338, 88.606], {icon: redIcon}).addTo(map).bindPopup("I am a red leaf.");
L.marker([27.211, 88.933], {icon: orangeIcon}).addTo(map).bindPopup("I am an orange leaf.");

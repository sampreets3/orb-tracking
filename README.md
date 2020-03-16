## ORB tracking:

Using the ORB tracker in OpenCV to track an object display a bounding box around the ROI.

This was done to test the performance of the different keypoint detectors.

---

### Explanation:

Here we make use of the ORB detector present in OpenCV, to track a christmas ball(object of interest) as it moves around. The frame of reference for the match detector is the first frame of the video, from which we compute the Region of Interest(ROI), and continue to track the ball.

---

### Usage

  1. Make sure you have OpenCV and cmake installed in your system.
  1. Clone or download this repository onto your computer `git clone https://github.com/sampreets3/orb-tracking.git`
  1. Navigate to the project directory.
  1. Create the build directory and move into it. `mkdir build && cd build`
  1. Open the terminal inside the build directory, and run cmake. `cmake ..`
  1. Once the MakeFile has been generated, you can build the project with the `make` command.
  1. This will generate an executable. You can run the tracking program with by typing `./tracking` on the terminal.

---

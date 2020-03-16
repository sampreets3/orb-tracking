## ORB tracking:

Using the ORB(Oriented FAST and Rotated BRIEF) tracker in OpenCV to track an object and display a bounding box around the ROI. The main reason to chose ORB as a tracker was because it is fast, robust, and above all, free to use.

![GIF](https://sampreets3.github.io/images/orb-tracking.mp4)

---

### Explanation:

>How the ORB detector works is that first it uses the FAST keypoint detector and BRIEF descriptor with many modifications to enhance the performance. The algorithm uses BRIEF descriptors to define the keypoints, which perform poorly with orientation. So, the algorithm is modified such that the descriptors are steered with respect to the orientation of the keypoints.

From the [OpenCV-Python ReadTheDocs](https://opencv-python-tutroals.readthedocs.io/en/latest/py_tutorials/py_feature2d/py_orb/py_orb.html)

Here we make use of the ORB detector present in OpenCV, to track a christmas ball(object of interest) as it moves around. The frame of reference for the match detector is the first frame of the video, from which we compute the Region of Interest(ROI), and continue to track the ball.

---

### Usage

  * Make sure you have OpenCV and cmake installed in your system.
  * Clone or download this repository onto your computer `git clone https://github.com/sampreets3/orb-tracking.git`
  * Navigate to the project directory.
  * Create the build directory and move into it. `mkdir build && cd build`
  * Open the terminal inside the build directory, and run cmake. `cmake ..`
  * Once the MakeFile has been generated, you can build the project with the `make` command.
  * This will generate an executable. You can run the tracking program with by typing `./tracking` on the terminal.

---

### Sources:

  1. [_E. Rublee, V. Rabaud, K. Konolige and G. Bradski, "ORB: An efficient alternative to SIFT or SURF,"_ 2011 International Conference on Computer Vision, Barcelona, 2011, pp. 2564-2571.](https://ieeexplore.ieee.org/document/6126544)
  2. [_OpenCV-Python Read The Docs_ : __ORB(Oriented FAST and Rotated BRIEF__)](https://opencv-python-tutroals.readthedocs.io/en/latest/py_tutorials/py_feature2d/py_orb/py_orb.html)

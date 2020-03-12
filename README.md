## ORB tracking:

Using the ORB tracker in OpenCV to track an object display a bounding box around the ROI.

This was done to test the performance of the different keypoint detectors.

---

### Explanation:

Here we make use of the ORB detector present in OpenCV, to track a christmas ball(object of interest) as it moves around. The frame of reference for the match detector is the first frame of the video, from which we compute the Region of Interest(ROI), and continue to track the ball.

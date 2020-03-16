#include <opencv2/opencv.hpp>
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/features2d.hpp"

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

const int MAX_FEATURES = 500;
const float GOOD_MATCH_PERCENT = 0.15f;

int main(int argc, char **argv)
{
  Mat frame, frame1, imReg, h;
  // Read reference image
  VideoCapture cap("../video1.mp4");
  // Check if camera opened successfully
  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
    return -1;
  }
  cap >> frame1;

  // Read image to be aligned
  while(1)
  {
    cap >> frame;

    // Convert images to grayscale
    Mat im1Gray, im2Gray;
    cvtColor(frame1, im1Gray, CV_BGR2GRAY);
    cvtColor(frame, im2Gray, CV_BGR2GRAY);

    // Variables to store keypoints and descriptors
    std::vector<KeyPoint> keypoints1, keypoints2;
    Mat descriptors1, descriptors2;

    // Detect ORB features and compute descriptors.
    Ptr<Feature2D> orb = ORB::create(MAX_FEATURES);
    orb->detectAndCompute(im1Gray, Mat(), keypoints1, descriptors1);
    orb->detectAndCompute(im2Gray, Mat(), keypoints2, descriptors2);

    // Match features.
    std::vector<DMatch> matches;
    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");
    matcher->match(descriptors1, descriptors2, matches, Mat());

    // Sort matches by score
    std::sort(matches.begin(), matches.end());

    // Remove not so good matches(Lowe ratio test)
    const int numGoodMatches = matches.size() * GOOD_MATCH_PERCENT;
    matches.erase(matches.begin()+numGoodMatches, matches.end());


    // Draw top matches
    Mat imMatches;
    drawMatches(frame1, keypoints1, frame, keypoints2, matches, imMatches);
    imshow("matches.jpg", imMatches);


    // Extract location of good matches
    std::vector<Point2f> points1, points2;

    for( size_t i = 0; i < matches.size(); i++ )
    {
      points1.push_back( keypoints1[ matches[i].queryIdx ].pt );
      points2.push_back( keypoints2[ matches[i].trainIdx ].pt );
    }

    std::vector<Point2f> obj_corners(4);
    std::vector<Point2f> scene_corners(4);

    obj_corners[0] = cvPoint(24, 44);
    obj_corners[1] = cvPoint( 196, 44);
    obj_corners[2] = Point2f( 196, 210 );
    obj_corners[3] = Point2f( 24, 210 );

    // Find homography
    h = findHomography( points1, points2, RANSAC );

    // Use homography to warp image
    perspectiveTransform(obj_corners, scene_corners, h);

    line(frame, scene_corners[0], scene_corners[1], (255, 0, 0), 2, LINE_8, 0);
    line(frame, scene_corners[1], scene_corners[2], (255, 0, 0), 2, LINE_8, 0);
    line(frame, scene_corners[2], scene_corners[3], (255, 0, 0), 2, LINE_8, 0);
    line(frame, scene_corners[3], scene_corners[0], (255, 0, 0), 2, LINE_8, 0);

    //imshow("BB with frame", frame);
    char c=(char)waitKey(25);
    if(c==27)
    {
      break;
    }
  }

  cap.release();

  destroyAllWindows();

}

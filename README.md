# Vehicle-Detection-Tracking
Using **only Image Processing Techniques**, detecting vehicles in real time video, creating bounding box, and tracking them

## Explanation

* Two consecutive frames are taken and their difference is computed. This creates an outline around the moving objects(here vehicles)
* The image is converted to grayscale and a binary thresholding filter is applied
* Then **3 sets of erode and dilate** filters are applied with different kernel sizes and iterations
  * erode(4,4)*1 --> dialate(8,8)*1  ---->  erode(7,7)*1 --> dialate(7,7)*1  ---->  erode(9,9)*1 --> dialate(9,9)*2
  * These parameters have been varied in a wide range to find the optimal values
* Reduntant objects like the number plate, shadow, car's rear view mirrors were also geting detected as seperate ojbects and were being identified as vehicles if we used only one erosion and dilation filter with larger filter size and iterations
* To avoid this **repetitive but small** erosions and dialations operations are done
* **Balance** between two tasks had to be maintained
  * merging cars parts within itself (too much of **dilation** and cars parts separates out of parent car)
  * avoiding merging of one car into other ( too much of **erosion** and two close vehicles merges into one another)
* Also, elimination based on the area of contour could not be done (assuming that noise has a smaller area) because cars far back on the road had contour area comparable to that of the noise

Trackbars were used to tweak the parameters simultaneously
![trackbars](https://github.com/Kartik-Aggarwal/Vehicle-Detection-Tracking/blob/main/readme_photos/trackbars.PNG)
## Following is an image with output from each intermidiate steps shown
!["Steps"](https://github.com/Kartik-Aggarwal/Vehicle-Detection-Tracking/blob/main/readme_photos/Steps.PNG)
Notice how the interiors of the car merges into one whole blob of pixels at the end
## Result
!["result"](https://github.com/Kartik-Aggarwal/Vehicle-Detection-Tracking/blob/main/readme_photos/result.gif)

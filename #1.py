#1
import cv2

img = cv2.imread("atc.jpg")
h, w = img.shape[:2]

cv2.imshow('Original', img)
cv2.imshow('Top Left', img[:h//2, :w//2])
cv2.imshow('Top Right', img[:h//2, w//2:])
cv2.imshow('Bottom Left', img[h//2:, :w//2])
cv2.imshow('Bottom Right', img[h//2:, w//2:])

cv2.waitKey(0)
cv2.destroyAllWindows()

#2
import cv2
import numpy as np

img = cv2.imread("atc.jpg")

translated = np.roll(img, (100, 50), (1, 0))
rotated = cv2.rotate(img, cv2.ROTATE_90_CLOCKWISE)
scaled = cv2.resize(img, None, fx=1.5, fy=1.5)

cv2.imshow("Original", img)
cv2.imshow("Translated", translated)
cv2.imshow("Rotated", rotated)
cv2.imshow("Scaled", scaled)

cv2.waitKey(0)
cv2.destroyAllWindows()

#3
import cv2
import numpy as np

img = cv2.imread("atc.jpg")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

edges = cv2.Canny(gray, 100, 200)
texture = cv2.blur(gray, (5, 5))

for name, image in [("Original", img), ("Edges", edges), ("Texture", texture)]:
    cv2.imshow(name, image)

cv2.waitKey(0)

#4
import cv2

image = cv2.imread('atc.jpg')

cv2.imshow('Original', image)
cv2.imshow('Gaussian Blur', cv2.GaussianBlur(image, (5, 5), 0))
cv2.imshow('Median Blur', cv2.medianBlur(image, 5))
cv2.imshow('Bilateral Filter', cv2.bilateralFilter(image, 9, 75, 75))

cv2.waitKey(0)

#5

import cv2
import numpy as np
image = cv2.imread('6.jpg')
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
blurred = cv2.GaussianBlur(gray, (5, 5), 0)
edges = cv2.Canny(blurred, 50, 150)
contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
contour_image = image.copy()
cv2.drawContours(contour_image, contours, -1, (0, 0, 255), 2)
cv2.imshow('Original Image', image)
cv2.imshow('Image with Contours', contour_image)
cv2.waitKey(0)
cv2.destroyAllWindows()





#6
import cv2
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
image = cv2.imread('face.jpg')
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
faces = face_cascade.detectMultiScale(gray, 1.1, 5, minSize=(30, 30))

for (x, y, w, h) in faces:
    cv2.rectangle(image, (x, y), (x+w, y+h), (0, 255, 0), 2)

cv2.imshow('Face Detection', image)
cv2.waitKey(0)
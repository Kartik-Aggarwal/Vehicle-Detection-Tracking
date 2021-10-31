# Created by me
from django.http import HttpResponse
from django.shortcuts import render, redirect 
from .forms import *
import cv2
from imutils import rotate_bound
from os import listdir,remove
from os.path import isfile, join
def index(request): 
	global ext

	if request.method == 'POST': 
		form = HotelForm(request.POST, request.FILES)
		ext=request.POST.get('ext','default')
		width=request.POST.get('width','default')
		height=request.POST.get('height','default')
		rotation=request.POST.get('rotation','default')
		color=request.POST.get('color','default')
		if form.is_valid(): 
			form.save()
			data_path = 'media/images'
			onlyfiles = [f for f in listdir(data_path) if isfile(join(data_path,f))]
			image=cv2.imread(f"media/images/{onlyfiles[0]}")
			if color=="color" or color=="default":
				pass
			if color=="grayscale":
				image=cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
			if color=="BW":
				image=cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
				image = cv2.threshold(image, 128, 255, cv2.THRESH_BINARY)[1]
			if color=="edges":
				image=cv2.Canny(image,100,100)
			if rotation!="default" :
				image = rotate_bound(image, int(rotation))	
			if width!="" and height!="":
				image=cv2.resize(image,(int(width),int(height)),interpolation=cv2.INTER_AREA)
				#cv2.imwrite(f"media/saveimages/saveimage.{ext}", image)
				#cv2.imwrite(f"imageutils/static/images/saveimage.{ext}", image)
			cv2.imwrite("imageutils/static/image/saveimage.png", image)
			cv2.imwrite("imageutils/static/image/saveimage.jpg", image)
			cv2.imwrite("imageutils/static/image/saveimage.jpeg", image)			
			remove(f"media/images/{onlyfiles[0]}")	 	

			return redirect('success') 
	else: 
		form = HotelForm() 
	return render(request,'index.html', {'form' : form}) 
  
  
def success(request): 
    return render(request,'success.html')

# Journal for IM Midterm Project

## Chinonyerem Ukaegbu

### Additional (after Minimum VP)
+ Day and night mode: after say 20 mouse clicks, keypresses, whatever, background changes from day to night
+ But would the images on top of it continue the same?
+ Think setup() or draw()?

### February 22
+ Uploaded background as image this time
+ A bit confused about where I would put the background(either setup or draw)
+ Put it in setup() at first and got this:

![Setup()Error](imagesTrials/Screenshot%20(224).png)

+ Realized my mistake and moved it to draw(). I also found out that writing the code for the background after the code for the ball would result in the ball being covered by the background instead of drawing over the background so that was really cool.
+ I also found out the dimensions I had to use for the ball to look as if it were rolling smoothly on the ground when the mouse was moved. Now I have to see how I'll implement this when I change it from a ball to the actual object that would catch the falling objects. Sigh

![RollingBall](imagesTrials/rollingball.gif)

### February 26
+ Created "bowl" that would collect the falling objects and programmed it so that it would move in the same way as the rolling ball. TO be honest, I was kind of scared that here would be lag because I used mouseX and the bowl would be moving very frequently but, so far, so good :smiley:

![RollingBowl](imagesTrials/rollingbowl.gif)

+ Will try working on creating the objects falling down the sky today. Thinking of it being like either by shape or by colour. I should get the colour working first though at least. But the idea is that after a certain frameCount maybe, there will be text displayed on the screen as per collect triangle, circle, you g sha regardless of colour. That is if I don't fall asleep first :guardsman:
+ I also discovered rectMode() and ellipseMode(). Wonder if I'll use them. They have the potential to make drawing these shapes a bit easier.

### February 27
+ Lol I fell asleep. Anyways I decided to make drawing the bowl a function and I also made the bowl smaller. I honestly would've just left it in the code plainly but I want some modularity and I think it would be helpful in creating classes maybe IDK?
+ Update: I'm getting the hang of this whole class object thing. However, I was trying to create a class for the triangles that were falling from the sky and when I initialized the object, I placed it after the image and I got a Null Pointer Exception Message which was weird and so I moved the initialization to the line after size() in setup() which was before I initialized the image and it was working fine. I wonder why though?

# -*- coding: utf-8 -*-
"""
Created on Fri Mar 22 22:20:16 2019

@author: hexie
"""

from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5.QtGui import QPainter
from PyQt5.QtCore import Qt, QTimer

class MyWidget(QWidget):
    def __init__(self,diameter1,startx1,starty1):
        super(MyWidget, self).__init__()
        # the first two decide where on the screen it appear
        # the second two decide the size of the window
        self.setGeometry(600,300, 600,400)
        self.dia=diameter1
        self.xpos=startx1
        self.ypos=starty1

        #set the velocity of the ball
        self.xv=1
        self.yv=1
        
  
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Redball')
        # rename the window to be whatever you want
        self.show()
    
    def paintEvent(self, event):
        
        paint = QPainter()
        paint.begin(self)

#        # make a white drawing background
#        paint.setBrush(Qt.white)
#        paint.drawRect(event.rect())
        # for circle make the ellipse radii match
        # let the brush be red for the circle
        paint.setPen(Qt.red)
        # fill the circle with red
        paint.setBrush(Qt.red)
        paint.drawEllipse(self.xpos,self.ypos,self.dia,self.dia)
        paint.end()
        
        ## revised from https://www.daniweb.com/programming/software-development/code/441810/draw-circles-pyside-pyqt
    
    def animate(self):
        self.checkcollide()
        self.xpos=self.xpos+self.xv
        self.ypos=self.ypos+self.yv
        self.update()
        self.timer = QTimer.singleShot(3, self.animate) 
    
    def checkcollide(self):
        if self.xpos + self.dia==self.width() or self.xpos ==0 :
            self.xv=-self.xv
            
        elif self.ypos ==0 or self.ypos + self.dia== self.height():
            self.yv=-self.yv
        
#    def mytimer(self):
#        QTimer.singleShot(30, self.animate)
##        timer = QTimer()  # set up your QTimer
##        timer.timeout.connect(self.animate())  # connect it to your update function
##        timer.start(30)  # set it to timeout in 5000 ms

def main1():
    app = QApplication([])
    diameter=30
    startx=50
    starty=50
    w = MyWidget(diameter,startx,starty)
    w.animate()
    
    # set the background to be anycolor your choice
    p = w.palette()
    p.setColor(w.backgroundRole(), Qt.white)
    w.setPalette(p)
    
#    #set the window size to be 600*400
#    w.resize(600,400)    
        
    
    app.exec_()

if __name__ == '__main__':
    main1()
    
#class MyWidget(QtWidgets.QWidget):
#    def __init__(self):
#        super().__init__()
#        self.setGeometry(30,30,600,400)
#        self.begin = QtCore.QPoint()
#        self.end = QtCore.QPoint()
#        self.show()
#
#    def paintEvent(self, event):
#        qp = QtGui.QPainter(self)
#        br = QtGui.QBrush(QtGui.QColor(100, 10, 10, 40))  
#        qp.setBrush(br)   
#        qp.drawRect(QtCore.QRect(self.begin, self.end))   
# -*- coding: utf-8 -*-
"""
Created on Fri Mar 22 22:21:24 2019

@author: hexie
"""

from PyQt5.QtWidgets import QApplication, QWidget, QColorDialog
from PyQt5.QtGui import QPainter, QColor
from PyQt5.QtCore import Qt, QTimer

class MyWidget(QWidget):
    
    def __init__(self,diameter1,startx1,starty1):
        super(MyWidget, self).__init__()
        self.setGeometry(600,300, 600,400)
        self.dia=diameter1
        self.xpos=startx1
        self.ypos=starty1
        self.color="red"
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Rectangle')
        self.show()
    
    def paintEvent(self, event):
        
        paint = QPainter()
        paint.begin(self)
        paint.setPen(QColor(self.color))
        paint.setBrush(QColor(self.color))
        paint.drawRect(self.xpos,self.ypos,self.dia,self.dia)
        paint.end()
    
    def mouseMoveEvent(self, e):
        x = e.x()
        y = e.y()        
        self.xpos=x-self.diffx
        self.ypos=y-self.diffy
        self.update()    
        
    def mousePressEvent(self, e):
        x=e.x()
        y=e.y()
        
        if x> self.xpos and x< self.xpos+self.dia and y> self.ypos and y< self.ypos+self.dia:
            self.diffx=x-self.xpos
            self.diffy=y-self.ypos

    
    def mouseDoubleClickEvent(self, e):
        x=e.x()
        y=e.y()
        if x> self.xpos and x< self.xpos+self.dia and y> self.ypos and y< self.ypos+self.dia:
            self.color = QColorDialog.getColor()
            self.update()
        
def main1():
    app = QApplication([])
    diameter=50
    startx=0
    starty=0
    w = MyWidget(diameter,startx,starty)
    
    # set the background to be anycolor your choice
    p = w.palette()
    p.setColor(w.backgroundRole(), Qt.white)
    w.setPalette(p)
    
    app.exec_()

if __name__ == '__main__':
    main1()
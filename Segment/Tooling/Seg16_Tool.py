# Project: Seg16_Tool.py
# Author : William Hsiao

#   __A1___A2__
#  | \H J|  K/ |
# F|G1\__|__/G2|B
#  | N/  |M \L |
# E|_/___|___\_|C  O(DP:CA)
#    D1     D2

import sys                                      # System

# Widget
from PyQt5.QtWidgets import QApplication        # Application
from PyQt5.QtWidgets import QWidget             # Widget
from PyQt5.QtWidgets import QLabel              # Label
from PyQt5.QtWidgets import QRadioButton        # Radio Button
from PyQt5.QtWidgets import QButtonGroup        # Button Group

# GUI
from PyQt5.QtGui import QPainter                # Painter
from PyQt5.QtGui import QColor                  # Color
from PyQt5.QtGui import QBrush                  # Brush
from PyQt5.QtGui import QFont                   # Font
from PyQt5.QtGui import QIcon                   # Icon
from PyQt5.QtGui import QPolygon                # Polygon
from PyQt5.QtGui import QPolygonF               # PolygonF

# Core
from PyQt5.QtCore import QRectF                 # Rectangle
from PyQt5.QtCore import Qt
from PyQt5.QtCore import QPoint

class SegmentDisplay(QWidget):
  # Constructor
  def __init__(self):
    super().__init__()
    self.Init_GUI()                             # Initial GUI
    self.Seg_Color     = [QColor(128,0,0)]*12   # Initial Dark Red Color
    self.Circle_Color  = QColor(128,0,0)        # Initial Dark Red Color
    self.Poly_Color    = [QColor(128,0,0)]*4    # Initial Dark Red Color
    self.SegBack_Color = QColor(192,192,192)    # Initial Gray Color

    # Value
    self.Result = 0
    self.NewResult = 0
    self.SeqFlag = 0
    self.COMFlag = 1
    self.Reverse = 0

  # Init_GUI
  def Init_GUI(self):
    self.setWindowTitle("16-Seg Tool")          # Application Title
    self.setWindowIcon(QIcon("./Reousrce/Segment7.png"))
    self.setGeometry(100, 100, 320, 450)

    # Set Label
    self.label_A1  = QLabel("A1",self)
    self.label_A2  = QLabel("A2",self)
    self.label_B   = QLabel("B",self)
    self.label_C   = QLabel("C",self)
    self.label_D1  = QLabel("D1",self)
    self.label_D2  = QLabel("D2",self)
    self.label_E   = QLabel("E",self)
    self.label_F   = QLabel("F",self)
    self.label_G1  = QLabel("G1",self)
    self.label_G2  = QLabel("G2",self)
    self.label_H   = QLabel("H",self)
    self.label_J   = QLabel("J",self)
    self.label_K   = QLabel("K",self)
    self.label_L   = QLabel("L",self)
    self.label_M   = QLabel("M",self)
    self.label_N   = QLabel("N",self)
    self.label_DOT = QLabel("*",self)

    self.label_vA1 = QLabel("0",self)
    self.label_vA2 = QLabel("0",self)
    self.label_vB  = QLabel("0",self)
    self.label_vC  = QLabel("0",self)
    self.label_vD1 = QLabel("0",self)
    self.label_vD2 = QLabel("0",self)
    self.label_vE  = QLabel("0",self)
    self.label_vF  = QLabel("0",self)
    self.label_vG1 = QLabel("0",self)
    self.label_vG2 = QLabel("0",self)
    self.label_vH  = QLabel("0",self)
    self.label_vJ  = QLabel("0",self)
    self.label_vK  = QLabel("0",self)
    self.label_vL  = QLabel("0",self)
    self.label_vM  = QLabel("0",self)
    self.label_vN  = QLabel("0",self)
    self.label_vDOT= QLabel("0",self)

    # A1 A2 B C D1 D2 E F G2 G2 H J K L M N * => 17
    self.label_Result_Hex = QLabel("00000H",self)


    self.label_A1.setGeometry(295,290,50,50)
    self.label_A2.setGeometry(270,290,50,50)
    self.label_B.setGeometry(255,290,50,50)
    self.label_C.setGeometry(240,290,50,50)
    self.label_D1.setGeometry(215,290,50,50)
    self.label_D2.setGeometry(190,290,50,50)
    self.label_E.setGeometry(175,290,50,50)
    self.label_F.setGeometry(160,290,50,50)
    self.label_G1.setGeometry(135,290,50,50)
    self.label_G2.setGeometry(110,290,50,50)
    self.label_H.setGeometry(95,290,50,50)
    self.label_J.setGeometry(80,290,50,50)
    self.label_K.setGeometry(65,290,50,50)
    self.label_L.setGeometry(50,290,50,50)
    self.label_M.setGeometry(35,290,50,50)
    self.label_N.setGeometry(20,290,50,50)
    self.label_DOT.setGeometry(5,290,50,50)

    self.label_vA1.setGeometry(300,320,50,50)
    self.label_vA2.setGeometry(275,320,50,50)
    self.label_vB.setGeometry(255,320,50,50)
    self.label_vC.setGeometry(240,320,50,50)
    self.label_vD1.setGeometry(220,320,50,50)
    self.label_vD2.setGeometry(195,320,50,50)
    self.label_vE.setGeometry(175,320,50,50)
    self.label_vF.setGeometry(160,320,50,50)
    self.label_vG1.setGeometry(140,320,50,50)
    self.label_vG2.setGeometry(115,320,50,50)
    self.label_vH.setGeometry(95,320,50,50)
    self.label_vJ.setGeometry(80,320,50,50)
    self.label_vK.setGeometry(65,320,50,50)
    self.label_vL.setGeometry(50,320,50,50)
    self.label_vM.setGeometry(35,320,50,50)
    self.label_vN.setGeometry(20,320,50,50)
    self.label_vDOT.setGeometry(5,320,50,50)

    self.label_Result_Hex.setGeometry(155,390,200,50)

    # Set Font
    font1 = QFont('Arial',18,QFont.Bold)
    font2 = QFont('Arial',10,QFont.Bold)
    #font3 = QFont('Arial',16,QFont.Bold)
    font4 = QFont('Arial',24,QFont.Bold)
    #font5 = QFont('Arial',28,QFont.Bold)
    #font6 = QFont('Arial',32,QFont.Bold)

    self.label_A1.setFont(font2)
    self.label_A2.setFont(font2)
    self.label_B.setFont(font2)
    self.label_C.setFont(font2)
    self.label_D1.setFont(font2)
    self.label_D2.setFont(font2)
    self.label_E.setFont(font2)
    self.label_F.setFont(font2)
    self.label_G1.setFont(font2)
    self.label_G2.setFont(font2)
    self.label_H.setFont(font2)
    self.label_J.setFont(font2)
    self.label_K.setFont(font2)
    self.label_L.setFont(font2)
    self.label_M.setFont(font2)
    self.label_N.setFont(font2)
    self.label_DOT.setFont(font2)

    self.label_vA1.setFont(font2)
    self.label_vA2.setFont(font2)
    self.label_vB.setFont(font2)
    self.label_vC.setFont(font2)
    self.label_vD1.setFont(font2)
    self.label_vD2.setFont(font2)
    self.label_vE.setFont(font2)
    self.label_vF.setFont(font2)
    self.label_vG1.setFont(font2)
    self.label_vG2.setFont(font2)
    self.label_vH.setFont(font2)
    self.label_vJ.setFont(font2)
    self.label_vK.setFont(font2)
    self.label_vL.setFont(font2)
    self.label_vM.setFont(font2)
    self.label_vN.setFont(font2)
    self.label_vDOT.setFont(font2)

    self.label_Result_Hex.setFont(font4)

    # Set Radio
    self.radio_G2A  = QRadioButton("G->A",self)
    self.radio_A2G  = QRadioButton("A->G",self)
    self.radio_COMH = QRadioButton("COM-H",self)
    self.radio_COML = QRadioButton("COM-L",self)

    self.Seq_Group  = QButtonGroup(self)
    self.COM_Group  = QButtonGroup(self)

    self.Seq_Group.addButton(self.radio_G2A)
    self.Seq_Group.addButton(self.radio_A2G)
    self.COM_Group.addButton(self.radio_COMH)
    self.COM_Group.addButton(self.radio_COML)

    self.radio_G2A.setGeometry(10,370,100,50)
    self.radio_A2G.setGeometry(10,400,100,50)
    self.radio_COMH.setGeometry(85,370,100,50)
    self.radio_COML.setGeometry(85,400,100,50)

    self.radio_G2A.setChecked(True)
    self.radio_COMH.setChecked(True)

    self.Seq_Group.buttonClicked.connect(self.onSeqClicked)
    self.COM_Group.buttonClicked.connect(self.onCOMClicked)

    self.show()

  # paintEvent: Paint
  def paintEvent(self, event):
    Painter = QPainter(self)
    Painter.setRenderHint(QPainter.Antialiasing)  # Blending Antialiasing

    # Draw Rectangles (Segments) L  T   W   H
    self.DrawSeg(Painter,QRectF( 35, 20,235,270),self.SegBack_Color)    # Background
    self.DrawSeg(Painter,QRectF( 90, 30, 50, 20),self.Seg_Color[0])        # A1
    self.DrawSeg(Painter,QRectF(150, 30, 50, 20),self.Seg_Color[1])        # A2
    self.DrawSeg(Painter,QRectF(210, 50, 20,100),self.Seg_Color[2])        # B
    self.DrawSeg(Painter,QRectF(210,160, 20,100),self.Seg_Color[3])        # C
    self.DrawSeg(Painter,QRectF( 90,250, 50, 20),self.Seg_Color[4])        # D1
    self.DrawSeg(Painter,QRectF(150,250, 50, 20),self.Seg_Color[5])        # D2
    self.DrawSeg(Painter,QRectF( 60,160, 20,100),self.Seg_Color[6])        # E
    self.DrawSeg(Painter,QRectF( 60, 50, 20,100),self.Seg_Color[7])        # F
    self.DrawSeg(Painter,QRectF( 90,140, 50, 20),self.Seg_Color[8])        # G1
    self.DrawSeg(Painter,QRectF(150,140, 50, 20),self.Seg_Color[9])        # G2
    self.DrawSeg(Painter,QRectF(135, 60, 20, 70),self.Seg_Color[10])       # J
    self.DrawSeg(Painter,QRectF(135,170, 20, 70),self.Seg_Color[11])       # M

    # Draw Polygen
    pt1 = [QPoint(160,130),QPoint(180, 60),
           QPoint(200, 60),QPoint(180,130)]   # Up and Right
    pt2 = [QPoint( 90,240),QPoint(110,170),
           QPoint(130,170),QPoint(110,240)]   # Down and Left
    pt3 = [QPoint(130,130),QPoint(110,60),
           QPoint( 90, 60),QPoint(110,130)]   # Up and Left
    pt4 = [QPoint(200,240),QPoint(180,170), 
           QPoint(160,170),QPoint(180,240)]   # Down and Right
    
    self.DrawPoly(Painter,pt1,self.Poly_Color[1])
    self.DrawPoly(Painter,pt2,self.Poly_Color[3])
    self.DrawPoly(Painter,pt3,self.Poly_Color[0])
    self.DrawPoly(Painter,pt4,self.Poly_Color[2])

    # Draw Circle
    self.DrawCircle(Painter,QRectF(240,260, 25, 25),self.Circle_Color)  # Dot

  # DrawSeg: Draw Rectangle
  def DrawSeg(self,Painter,Rect,Color):
    Painter.setBrush(QBrush(Color))
    Painter.drawRect(Rect)

  # DrawCircle
  def DrawCircle(self,Painter,Circle,Color):
    Painter.setBrush(QBrush(Color))
    Painter.drawEllipse(Circle)

  # DrawPoly
  def DrawPoly(self,Painter,Points,Color):
    Painter.setBrush(QBrush(Color))
    polygon = QPolygon(Points)
    Painter.drawPolygon(polygon)

  def mousePressEvent(self,event):
    pos = event.pos()

    # Check if any segment is clicked
    Seqment = [QRectF( 90, 30, 50, 20),   # A1
               QRectF(150, 30, 50, 20),   # A2
               QRectF(210, 50, 20,100),   # B
               QRectF(210,160, 20,100),   # C
               QRectF( 90,250, 50, 20),   # D1
               QRectF(150,250, 50, 20),   # D2
               QRectF( 60,160, 20,100),   # E
               QRectF( 60, 50, 20,100),   # F
               QRectF( 90,140, 50, 20),   # G1
               QRectF(150,140, 50, 20),   # G1
               QRectF(135, 60, 20, 70),   # J
               QRectF(135,170, 20, 70)]   # M
    
    for i, Seqment in enumerate(Seqment):
      if Seqment.contains(pos):
        self.Toggle_Color(i)
        self.update()
        return
      
    # Check if any polygon is clicked
    Polygons = [[QPoint(130,130), QPoint(110, 60),
                 QPoint( 90, 60), QPoint(110,130)],   # Poly 3
                [QPoint(160,130), QPoint(180, 60), 
                 QPoint(200, 60), QPoint(180,130)],   # Poly 1
                [QPoint(200,240), QPoint(180,170),
                 QPoint(160,170), QPoint(180,240)],   # Poly 4
                [QPoint( 90,240), QPoint(110,170),
                 QPoint(130,170), QPoint(110,240)]]   # Poly 2

    for i,Poly in enumerate(Polygons):
      poly_shape = QPolygonF(Poly)
      if poly_shape.containsPoint(pos, Qt.OddEvenFill):
        self.Toggle_Poly(i)
        self.update()
        return

    # Check if the circle is clicked
    Circle = QRectF(240,260, 25, 25)
    if Circle.contains(pos):
      self.Toggle_Circle()
    self.update()

# *     N     M     L     K     J     H     G2    G1    F    E   D2  D1  C  B  A2  A1
# 1     2     3     4     5     6     7     8     9     10   11  12  13  14 15 16  17
# 1     1     1     1     1     1     1     1     1     1    1   1   1   1  1  1   1
# 65536 32768 16384 8192  4096  2048  1024  512   256   128  64  32  16  8  4  2   1

  def Toggle_Color(self,Index):

    Labels = [self.label_vA1,    # Value A1   1
              self.label_vA2,    # Value A2   2
              self.label_vB,     # Value B    4
              self.label_vC,     # Value C    8
              self.label_vD1,    # Value D1   16
              self.label_vD2,    # Value D2   32
              self.label_vE,     # Value E    64
              self.label_vF,     # Value F    128
              self.label_vG1,    # Value G1   256
              self.label_vG2,    # Value G2   512
              self.label_vJ,     # Value J    2048
              self.label_vM]     # Value M    16384
    
    Values = [1,2,4,8,16,32,64,128,256,512,2048,16384]

    if self.Seg_Color[Index] == QColor(128,0,0):  # Dark Red
      self.Seg_Color[Index] = QColor(255,0,0)     # Bright Red
      if 0 <= Index < len(Labels):
        Labels[Index].setText("1")
        self.Result += Values[Index]
    else:
      self.Seg_Color[Index] = QColor(128,0,0)     # Dark Red
      if 0 <= Index < len(Labels):
        Labels[Index].setText("0")
        self.Result -= Values[Index]

    self.ShowResult()

  def Toggle_Circle(self):
    if self.Circle_Color == QColor(128,0,0):      # Dark red
      self.Circle_Color = QColor(255,0,0)         # Bright red
      self.label_vDOT.setText("1")
      self.Result+= 65536
    else:
      self.Circle_Color = QColor(128,0,0)         # Dark red
      self.label_vDOT.setText("0")
      self.Result-= 65536
    self.ShowResult()

  def Toggle_Poly(self,Index):
    Labels = [self.label_vH,    # Value H   1024
              self.label_vK,    # Value K   4096
              self.label_vL,    # Value L   8192
              self.label_vN]    # Value N   32768

    Values = [1024,4096,8192,32768]

    if self.Poly_Color[Index] == QColor(128,0,0): # Dark Red
      self.Poly_Color[Index] = QColor(255,0,0)    # Bright Red
      if 0 <= Index < len(Labels):
        Labels[Index].setText("1")
        self.Result += Values[Index]
    else:
      self.Poly_Color[Index] = QColor(128,0,0)
      if 0 <= Index < len(Labels):
        Labels[Index].setText("0")
        self.Result -= Values[Index]
    self.ShowResult()


  # onSeqClicked
  def onSeqClicked(self):
    if self.radio_A2G.isChecked():
      self.SeqFlag = 1
    if self.radio_G2A.isChecked():
      self.SeqFlag = 0
    self.ShowResult()


  # onCOMClicked
  def onCOMClicked(self):
    if self.radio_COMH.isChecked():
      self.COMFlag = 1
    if self.radio_COML.isChecked():
      self.COMFlag = 0
    self.ShowResult()


  # ShowResult
  def ShowResult(self):
    # Set Result
    self.NewResult = self.Result

    if self.SeqFlag == 1:
      # Reverse Result
      for i in range(17):
        self.Reverse |= ((self.NewResult >> i) & 1) << (16 - i)
      self.NewResult = self.Reverse

    if self.COMFlag == 1:
        self.NewResult = self.NewResult ^ 0x1FFFF    # Reverse
    self.label_Result_Hex.setText(hex(self.NewResult)[2:].upper().zfill(5) + "H")


if __name__ == '__main__':
  print("Start Application")
  app = QApplication(sys.argv)
  ex = SegmentDisplay()
  sys.exit(app.exec_())

# Project: Seg7_Tool.py
# Author : William Hsiao

#      _____
#     |  A  |
#   F |_____| B
#     |  G  |
#   E |_____| C  O(DP)
#        D

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

# Core
from PyQt5.QtCore import QRectF                 # Rectangle

class SegmentDisplay(QWidget):
  # Constructor
  def __init__(self):
    super().__init__()
    self.Init_GUI()                             # Initial GUI
    self.Seg_Colors    = [QColor(128,0,0)]*7    # Initial Dark Red Color
    self.Circle_Color  = QColor(128,0,0)        # Initial Dark Red Color
    self.SegBack_Color = QColor(192,192,192)    # Initial Gray Color

    # Value
    self.Result = 0
    self.NewResult = 0
    self.SeqFlag = 0
    self.COMFlag = 1
    self.Reverse = 0
  
  # Init_GUI
  def Init_GUI(self):
    self.setWindowTitle("7-Seg Tool")           # Application Title
    self.setWindowIcon(QIcon("./Reousrce/Segment7.png"))
    self.setGeometry(100, 100, 300, 450)

    # Set Label
    self.label_A   = QLabel("A",self)
    self.label_B   = QLabel("B",self)
    self.label_C   = QLabel("C",self)
    self.label_D   = QLabel("D",self)
    self.label_E   = QLabel("E",self)
    self.label_F   = QLabel("F",self)
    self.label_G   = QLabel("G",self)
    self.label_DOT = QLabel("*",self)

    self.label_vA  = QLabel("0",self)
    self.label_vB  = QLabel("0",self)
    self.label_vC  = QLabel("0",self)
    self.label_vD  = QLabel("0",self)
    self.label_vE  = QLabel("0",self)
    self.label_vF  = QLabel("0",self)
    self.label_vG  = QLabel("0",self)
    self.label_vDOT= QLabel("0",self)

    self.label_Result_Hex = QLabel("00H",self)

    self.label_A.setGeometry(265,290,50,50)
    self.label_B.setGeometry(230,290,50,50)
    self.label_C.setGeometry(195,290,50,50)
    self.label_D.setGeometry(160,290,50,50)
    self.label_E.setGeometry(125,290,50,50)
    self.label_F.setGeometry( 90,290,50,50)
    self.label_G.setGeometry( 55,290,50,50)
    self.label_DOT.setGeometry(20,290,50,50)

    self.label_vA.setGeometry(265,320,50,50)
    self.label_vB.setGeometry(230,320,50,50)
    self.label_vC.setGeometry(195,320,50,50)
    self.label_vD.setGeometry(160,320,50,50)
    self.label_vE.setGeometry(125,320,50,50)
    self.label_vF.setGeometry( 90,320,50,50)
    self.label_vG.setGeometry( 55,320,50,50)
    self.label_vDOT.setGeometry(20,320,50,50)
    
    self.label_Result_Hex.setGeometry(175,390,120,50)

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

    # Set Font
    font1 = QFont('Arial',18,QFont.Bold)
    font2 = QFont('Arial',10,QFont.Bold)
    #font3 = QFont('Arial',16,QFont.Bold)
    #font4 = QFont('Arial',24,QFont.Bold)
    #font5 = QFont('Arial',28,QFont.Bold)
    font6 = QFont('Arial',32,QFont.Bold)

    self.radio_G2A.setFont(font2)
    self.radio_A2G.setFont(font2)
    self.radio_COMH.setFont(font2)
    self.radio_COML.setFont(font2)

    self.label_A.setFont(font1)
    self.label_B.setFont(font1)
    self.label_C.setFont(font1)
    self.label_D.setFont(font1)
    self.label_E.setFont(font1)
    self.label_F.setFont(font1)
    self.label_G.setFont(font1)
    self.label_DOT.setFont(font1)

    self.label_vA.setFont(font1)
    self.label_vB.setFont(font1)
    self.label_vC.setFont(font1)
    self.label_vD.setFont(font1)
    self.label_vE.setFont(font1)
    self.label_vF.setFont(font1)
    self.label_vG.setFont(font1)
    self.label_vDOT.setFont(font1)

    self.label_Result_Hex.setFont(font6)

    self.show()


  # paintEvent: Paint
  def paintEvent(self, event):
    Painter = QPainter(self)
    Painter.setRenderHint(QPainter.Antialiasing)  # Blending Antialiasing

    # Draw Rectangles (Segments) L  T   W   H
    self.DrawSeg(Painter,QRectF(35,  20,235,270),self.SegBack_Color)   # Background
    self.DrawSeg(Painter,QRectF(100, 30,100, 30),self.Seg_Colors[0])   # A
    self.DrawSeg(Painter,QRectF(210, 50, 30,100),self.Seg_Colors[1])   # B
    self.DrawSeg(Painter,QRectF(210,160, 30,100),self.Seg_Colors[2])   # C
    self.DrawSeg(Painter,QRectF(100,250,100, 30),self.Seg_Colors[3])   # D
    self.DrawSeg(Painter,QRectF( 60,160, 30,100),self.Seg_Colors[4])   # E
    self.DrawSeg(Painter,QRectF( 60, 50, 30,100),self.Seg_Colors[5])   # F
    self.DrawSeg(Painter,QRectF(100,140,100, 30),self.Seg_Colors[6])   # G

    # Draw Circle
    self.DrawCircle(Painter,QRectF(240,260, 25, 25),self.Circle_Color)  # Dot

  # DrawSeg: Draw Rectangle
  def DrawSeg(self,Painter,Rect,Color):
    Painter.setBrush(QBrush(Color))
    Painter.drawRect(Rect)

  # DrawCircle: Draw Circle
  def DrawCircle(self,Painter,Circle,Color):
    Painter.setBrush(QBrush(Color))
    Painter.drawEllipse(Circle)

  def mousePressEvent(self,event):
    pos = event.pos()

    # Check if any segment is clicked
    Seqment = [ QRectF(100, 30,100, 30),  # A
                QRectF(210, 50, 30,100),  # B
                QRectF(210,160, 30,100),  # C
                QRectF(100,250,100, 30),  # D
                QRectF( 60,160, 30,100),  # E
                QRectF( 60, 50, 30,100),  # F
                QRectF(100,140,100, 30)]  # G
    
    for i, Seqment in enumerate(Seqment):
      if Seqment.contains(pos):
        self.Toggle_Color(i)
        self.update()
        return

    # Check if the circle is clicked
    Circle = QRectF(240,260, 25, 25)
    if Circle.contains(pos):
      self.Toggle_Circle_Color()
    self.update()


  # Toggle_Colr
  def Toggle_Color(self,Index):
    Labels = [self.label_vA,    # Value A
              self.label_vB,    # Value B
              self.label_vC,    # Value C
              self.label_vD,    # Value D
              self.label_vE,    # Value E
              self.label_vF,    # Value F
              self.label_vG]    # Value G

    if self.Seg_Colors[Index] == QColor(128,0,0): # Dark Red
      self.Seg_Colors[Index] = QColor(255,0,0)    # Bright Red

      if 0 <= Index < len(Labels):
        Labels[Index].setText("1")
        self.Result += 1 << Index
    else:
      self.Seg_Colors[Index] = QColor(128,0,0)    # Dark Red

      if 0 <= Index < len(Labels):
        Labels[Index].setText("0")
        self.Result -= 1 << Index
    self.ShowResult()


  # Toggle_Circle_Color
  def Toggle_Circle_Color(self):
    if self.Circle_Color == QColor(128,0,0):      # Dark red
      self.Circle_Color = QColor(255,0,0)         # Bright red
      self.label_vDOT.setText("1")
      self.Result += 128
    else:
      self.Circle_Color = QColor(128,0,0)         # Dark red
      self.label_vDOT.setText("0")
      self.Result -= 128
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
      for i in range(8):
        self.Reverse |= ((self.NewResult >> i) & 1) << (7 - i)
      self.NewResult = self.Reverse

    if self.COMFlag == 1:
        self.NewResult = self.NewResult ^ 0xFF    # Reverse
    self.label_Result_Hex.setText(hex(self.NewResult)[2:].upper().zfill(2) + "H")


# Main Code
if __name__ == '__main__':
  print("Start Application")
  app = QApplication(sys.argv)
  ex = SegmentDisplay()
  sys.exit(app.exec_())

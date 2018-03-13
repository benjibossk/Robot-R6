import os
import wx
import picamera
 
 
 
class MainWindow(wx.Frame):
    def __init__(self, parent, title):
        frame = wx.Frame.__init__(self, parent, title=title, size=(600,600))
        self.Center()
 
        self.CreateStatusBar() # A StatusBar in the bottom of the window
 
        # Setting up the menu.
        filemenu= wx.Menu()
 
        # wx.ID_ABOUT and wx.ID_EXIT are standard ids provided by wxWidgets.
        menuAbout = filemenu.Append(wx.ID_ABOUT, "&About"," Information about this program")
        menuExit = filemenu.Append(wx.ID_EXIT,"E&xit"," Terminate the program")
 
        # Creating the menubar.
        menuBar = wx.MenuBar()
        menuBar.Append(filemenu,"&File") # Adding the "filemenu" to the MenuBar
        self.SetMenuBar(menuBar)  # Adding the MenuBar to the Frame content.
 
        # Create Image
        self.Image = wx.StaticBitmap(self, bitmap=wx.EmptyBitmap(512, 300))
        self.LoadImage()
 
        #Capture Button
        b = wx.Button(self, -1, "Capture")
        b.Bind(wx.EVT_BUTTON, self.Capture)
 
        # Using a Sizer to handle the layout
        box = wx.BoxSizer(wx.VERTICAL)
 
 
 
        # adding stretchable space before and after centers the image.
        box.Add((1,1),1)
        box.Add(self.Image, 0, wx.ALIGN_CENTER_HORIZONTAL | wx.ALL | wx.ADJUST_MINSIZE, 10)
        box.Add((1,1),1)
 
        box.Add(b, 0, wx.CENTER | wx.ALL,10)
 
        self.SetSizerAndFit(box)
 
        # Set events.
        self.Bind(wx.EVT_MENU, self.OnAbout, menuAbout)
        self.Bind(wx.EVT_MENU, self.OnExit, menuExit)
 
        self.Show(True)
 
    def Capture(self, event=None):
        with picamera.PiCamera() as camera:
            camera.vflip = True
            camera.capture('image.jpg')
        self.LoadImage()
 
 
    def LoadImage(self):
               # load the image
               Img = wx.Image("image.jpg", wx.BITMAP_TYPE_JPEG)
 
               # scale the image, preserving the aspect ratio
               W = Img.GetWidth()
               H = Img.GetHeight()
 
               Img = Img.Scale(512, 300)
 
               # convert it to a wx.Bitmap, and put it on the wx.StaticBitmap
               self.Image.SetBitmap(wx.BitmapFromImage(Img))
 
               # You can fit the frame to the image, if you want.
               #self.Fit()
               #self.Layout()
               self.Refresh()
 
    def OnAbout(self,e):
        # A message dialog box with an OK button. wx.OK is a standard ID in wxWidgets.
        dlg = wx.MessageDialog( self, "A wxPython based tool for using picamera", "About Camera Monitor", wx.OK)
        dlg.ShowModal() # Show it
        dlg.Destroy() # finally destroy it when finished.
 
    def OnExit(self,e):
        self.Close(True)  # Close the frame.
 
 
app = wx.App(False)
frame = MainWindow(None, "Camera Monitor")
app.MainLoop()

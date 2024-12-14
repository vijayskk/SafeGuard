from tkinter import *
from tkinter import ttk
from tkinter.filedialog import askopenfile

def idle():
    hint.config(text="Select a file to check for any infections")
    openbtn.config(text="Open file",command=openfile)

def checkfile():
    print("Checking...")
    hint.config(text="Checking...")
    openbtn.config(text="Cancel",command=idle)

def openfile():
    root.attributes('-topmost', False)
    filename = askopenfile()
    print(filename.name)
    hint.config(text=f"{filename.name} is selected. Press Scan Button to scan.")
    openbtn.config(text="Scan",command=checkfile)

root = Tk()

root.title("Safeguard++")
root.minsize(900, 500)
root.geometry("300x300+50+50") 
root.attributes('-topmost', True)
style = ttk.Style()
style.theme_use("aqua")

herologo = Label(root,text="SafeGuard++",font=("Inter",40,"bold"),anchor=CENTER)
herologo.grid(pady=70,row=0,column=3)

root.grid_columnconfigure(0, weight=1)  # First column for spacing
root.grid_columnconfigure(1, weight=0)  # Button 1 column
root.grid_columnconfigure(2, weight=1)  # Space between buttons
root.grid_columnconfigure(3, weight=0)  # Button 2 column
root.grid_columnconfigure(4, weight=1)  # Space between buttons
root.grid_columnconfigure(5, weight=0)  # Button 3 column
root.grid_columnconfigure(6, weight=1)  # Last column for spacing

# b1 = Button(root,command=filechecker,text="File Checker",width=15,font=("Inter",15),height=2)
# b2 = Button(root,command=filechecker,text="Directory Scanner",width=15,font=("Inter",15),height=2)
# b3 = Button(root,command=filechecker,text="Watchman",width=15,font=("Inter",15),height=2)

# b1.grid(row=1,column=1,pady=20,padx=5)
# b2.grid(row=1,column=3,pady=20,padx=5)
# b3.grid(row=1,column=5,pady=20,padx=5)

# File Checker
hint = Label(root,text="Select a file to check for any infections",font=("Inter",12),anchor=CENTER)
openbtn = Button(root,command=openfile,text="Open file",width=15)
hint.grid(pady=40,row=3,column=3)
openbtn.grid(pady=5,row=4,column=3)





root.mainloop()



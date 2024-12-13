from tkinter import *

root = Tk()

root.title("Safeguard++")
root.configure(background="white")
root.minsize(900, 500)
root.geometry("300x300+50+50") 
root.attributes('-topmost', True)


herologo = Label(root,text="Safeguard++",font="Inter",foreground="black",background="white")
herologo.pack()

root.mainloop()
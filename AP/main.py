import smtplib
import sys
import os
with open('temp.txt', 'r') as f:
    lines = f.readlines()

count = 0
name = lines[0].strip()
email = lines[1].strip()
string = ''
for line in lines[2:]:
    string += line.strip() + '\n'


sender = "ap.guys.store@gmail.com"
recevier = email
password = sys.argv[1]
subject = "Your Payment was Successfull :)"
body = string

message = f"""from:(Guys Store){sender}
To: ({name}){recevier}
subject: {subject}\n
{body}
"""


try:
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.starttls()
    server.login(sender, password)
    server.sendmail(sender, recevier, message)
    print("email sent")
except:
    print("can't send")

os.remove("temp.txt")
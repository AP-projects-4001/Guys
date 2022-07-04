import sys
import smtplib


Name = sys.argv[1]
Email = sys.argv[2]
Code = sys.argv[3]

# Code = 2
# Name = "Ali"
sender = "ap.guys.store@gmail.com"
recevier = Email
password = "uzhsypapwsrayzdx"
subject = "Registration Confirmation"
body = 'Dear ' + Name + ', The registration proccess has been initiated for your e-mail'
body += ' on the AP Guys Store program\n'
body += 'Your confirmation code is: ' + str(Code) + '\n'
body += 'If you have never initiated this registration proccess, please delete this e-mail\n'
body += 'Guys Store <3'
# print(body)


message = f"""from:(Guys Store){sender}
To: ({Name}){recevier}
subject: {subject}\n
{body}
"""

try:
  server = smtplib.SMTP("smtp.gmail.com",587)
  server.starttls()
  server.login(sender,password)
  server.sendmail(sender,recevier,message)
  print("email sent")
except:
  print("can't send")
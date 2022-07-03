import smtplib

with open('project/temp.txt', 'r') as f:
    lines = f.readlines()

count = 0
name = lines[0].strip()
email = lines[1].strip()
string = ''
for line in lines[2:]:
    string += line.strip() + '\n'
# string +='&#10084;&#65039;' #heart
# string += '&#128722;' #cart
print(name,email)
print(string)

#passssss "uzhsypapwsrayzdx"


sender = "ap.guys.store@gmail.com"
recevier = "poyduzospu@vusra.com"
password = "uzhsypapwsrayzdx"
subject = "Your Payment was Successfully :)"
body = string

message = f"""from:(Guys Store){sender}
To: ({name}){recevier}
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










# import smtplib
# sender = "ap.guys.store@gmail.com"
# recevier = "pulmosoydu@vusra.com"
# password = "uzhsypapwsrayzdx"
# subject = "Your Payment was Successfully :)"
# body = "thanks for your shopping..."

# message = f"""from:(Guys Store){sender}
# To: (Our sweety client){recevier}
# subject: {subject}\n
# {body}
# """
# try:
#   server = smtplib.SMTP("smtp.gmail.com",587)
#   server.starttls()
#   server.login(sender,password)
#   server.sendmail(sender,recevier,message)
#   print("email sent")
# except:
#   print("can't send")
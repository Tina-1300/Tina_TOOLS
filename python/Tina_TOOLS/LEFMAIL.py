
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

from email.mime.base import MIMEBase
from email import encoders
import mimetypes


class LEFMAIL:

    def __init__(self, smtp_server, smtp_port, login, password):
        self.smtp_server = smtp_server
        self.smtp_port = smtp_port
        self.login = login
        self.password = password


    def SenderEmail_1(self, to_email, subject, message, typemsg):
        if typemsg == False:
            textORhtml = "plain"
        elif typemsg == True:
            textORhtml = "html"
        else:
            return "Error type msg"
        msg = MIMEMultipart()
        msg['From'] = self.login
        msg['To'] = to_email
        msg['Subject'] = subject

        html_part = MIMEText(message, textORhtml)
        msg.attach(html_part)
        try:
            with smtplib.SMTP(self.smtp_server, self.smtp_port) as server:
                server.starttls()
                server.login(self.login, self.password)
                server.sendmail(self.login, to_email, msg.as_string())
            return 200
        except Exception as e:
            print(f"Erreur lors de l'envoi de l'email HTML : {e}")


    def SenderEmail_2(self, to_email, subject, message, files, typemsg):
        if typemsg == False:
            textORhtml = "plain"
        elif typemsg == True:
            textORhtml = "html"
        else:
            return "Error type msg"

        msg = MIMEMultipart()
        msg['From'] = self.login
        msg['To'] = to_email
        msg['Subject'] = subject
        msg.attach(MIMEText(message, textORhtml))

        for file in files:

            mimetype, _ = mimetypes.guess_type(file)
            if mimetype is None:
                return "Error MimTypes non détécter"
        
            mime_main, mime_sub = mimetype.split('/')

            with open(file, "rb") as attachment:
                part = MIMEBase(mime_main, mime_sub)
                part.set_payload(attachment.read())

            encoders.encode_base64(part)
            part.add_header("Content-Disposition", f"attachment; filename= {file}")
            msg.attach(part)

        try:
            with smtplib.SMTP(self.smtp_server, self.smtp_port) as server:
                server.starttls()
                server.login(self.login, self.password)
                server.sendmail(self.login, to_email, msg.as_string())
            return 200
        except Exception as e:
            print(f"Error l'ors de l'envoi de l'email : {e}")



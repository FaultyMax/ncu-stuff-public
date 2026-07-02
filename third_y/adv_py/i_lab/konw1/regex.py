
import re

regex = r"[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,7}"

text = "ttt abc@mail.com ddd "

if match := re.search(regex, text):
    print(match.group(0))

# pip install qrcode

import qrcode

img = qrcode.make("https://www.youtube.com/watch?v=x9oO1jw9LKw&ab_channel=blink-182-Topic")
img.save("qr.png", "PNG")
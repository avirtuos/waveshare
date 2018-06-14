
import string,cgi,time
from os import curdir, sep
from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer

import epd7in5b
import Image
import ImageDraw
import ImageFont
import traceback

#import pri


EPD_WIDTH = 640
EPD_HEIGHT = 384

epd = epd7in5b.EPD()
epd.init()


class MyHandler(BaseHTTPRequestHandler):

    def do_GET(self):
        try:
            self.send_response(200)
            self.send_header('Content-type',	'text/html')
            self.end_headers()
            self.wfile.write("OK")
            f.close()
            return

        except IOError:
            self.send_error(404,'File Not Found: %s' % self.path)


    def do_POST(self):
        global rootnode
        try:
            ctype, pdict = cgi.parse_header(self.headers.getheader('content-type'))
            if ctype == 'multipart/form-data':
                query=cgi.parse_multipart(self.rfile, pdict)
            self.send_response(301)

            self.end_headers()
            upfilecontent = query.get('upfile')
            print("filecontent", len(upfilecontent[0]))

            out = open("test.bmp", 'wb')
            out.write(upfilecontent[0])
            out.close()

            im = Image.open("test.bmp")
            im2 = im.rotate(180).resize((640, 384))
            im2.save("test-resized.bmp", "BMP")

            image = Image.open('test-resized.bmp')
            epd.display_frame(epd.get_frame_buffer(image))
            self.wfile.write("<HTML>OK.<BR><BR>");

        except Exception as e:
            print("ERROR....%s" % str(e))
            traceback.print_exc()

def main():
    server = HTTPServer(('', 80), MyHandler)
    print('started httpserver...')
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print('^C received, shutting down server')
        server.socket.close()

if __name__ == '__main__':
    main()
